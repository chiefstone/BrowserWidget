// Copyright (c) 20010 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "xml_reader_impl.h"
#include "base/logging.h"
#include "base/utf_string_conversions.h"

// Static functions

//static
CefRefPtr<CefXmlReader> CefXmlReader::Create(CefRefPtr<CefStreamReader> stream,
                                             EncodingType encodingType,
                                             const std::wstring& URI)
{
  CefRefPtr<CefXmlReaderImpl> impl(new CefXmlReaderImpl());
  if (!impl->Initialize(stream, encodingType, URI))
    return NULL;
  return impl.get();
}


// CefXmlReaderImpl

namespace {

/**
 * xmlInputReadCallback:
 * @context:  an Input context
 * @buffer:  the buffer to store data read
 * @len:  the length of the buffer in bytes
 *
 * Callback used in the I/O Input API to read the resource
 *
 * Returns the number of bytes read or -1 in case of error
 */
int XMLCALL xml_read_callback(void * context, char * buffer, int len)
{
  CefRefPtr<CefStreamReader> reader(static_cast<CefStreamReader*>(context));
  return reader->Read(buffer, 1, len);
}

/**
 * xmlInputCloseCallback:
 * @context:  an Input context
 *
 * Callback used in the I/O Input API to close the resource
 *
 * Returns 0 or -1 in case of error
 */
int XMLCALL xml_close_callback(void * context)
{
  CefRefPtr<CefStreamReader> reader(static_cast<CefStreamReader*>(context));
  
  // Release the reference added by CefXmlReaderImpl::Initialize().
  reader->Release();
  return 1;
}

/**
 * xmlTextReaderErrorFunc:
 * @arg: the user argument
 * @msg: the message
 * @severity: the severity of the error
 * @locator: a locator indicating where the error occured
 *
 * Signature of an error callback from a reader parser
 */
void XMLCALL xml_error_callback(void *arg, const char *msg,
						 xmlParserSeverities severity, xmlTextReaderLocatorPtr locator)
{
  if (!msg)
    return;

  std::wstring error_str;
  UTF8ToWide(msg, strlen(msg), &error_str);

  if (!error_str.empty() && error_str[error_str.length()-1] == '\n')
    error_str.resize(error_str.length()-1);
  
  std::wstringstream ss;
  ss << error_str << L", line " << xmlTextReaderLocatorLineNumber(locator);

  LOG(INFO) << ss.str();
  
  CefRefPtr<CefXmlReaderImpl> impl(static_cast<CefXmlReaderImpl*>(arg));
  impl->AppendError(ss.str());
}

/**
 * xmlStructuredErrorFunc:
 * @userData:  user provided data for the error callback
 * @error:  the error being raised.
 *
 * Signature of the function to use when there is an error and
 * the module handles the new error reporting mechanism.
 */
void XMLCALL xml_structured_error_callback(void *userData, xmlErrorPtr error)
{
  if (!error->message)
    return;

  std::wstring error_str;
  UTF8ToWide(error->message, strlen(error->message), &error_str);
  
  if (!error_str.empty() && error_str[error_str.length()-1] == '\n')
    error_str.resize(error_str.length()-1);
  
  std::wstringstream ss;
  ss << error_str << L", line " << error->line;

  LOG(INFO) << ss.str();
  
  CefRefPtr<CefXmlReaderImpl> impl(static_cast<CefXmlReaderImpl*>(userData));
  impl->AppendError(ss.str());
}

std::wstring xmlCharToWString(const xmlChar* xmlStr, bool free)
{
  if (!xmlStr)
    return std::wstring();

  const char* str = reinterpret_cast<const char*>(xmlStr);
  std::wstring wstr;
  UTF8ToWide(str, strlen(str), &wstr);
  
  if (free)
    xmlFree(const_cast<xmlChar*>(xmlStr));
  
  return wstr;
}

} // namespace

CefXmlReaderImpl::CefXmlReaderImpl()
  : supported_thread_id_(PlatformThread::CurrentId()), reader_(NULL)
{
}

CefXmlReaderImpl::~CefXmlReaderImpl()
{
  if (reader_ != NULL) {
    if (!VerifyContext()) {
      // Close() is supposed to be called directly. We'll try to free the reader
      // now on the wrong thread but there's no guarantee this call won't crash. 
      xmlFreeTextReader(reader_);
    } else {
      Close();
    }
  }
}

bool CefXmlReaderImpl::Initialize(CefRefPtr<CefStreamReader> stream,
                                  EncodingType encodingType,
                                  const std::wstring& URI)
{
  xmlCharEncoding enc = XML_CHAR_ENCODING_NONE;
  switch (encodingType) {
    case XML_ENCODING_UTF8:
      enc = XML_CHAR_ENCODING_UTF8;
      break;
    case XML_ENCODING_UTF16LE:
      enc = XML_CHAR_ENCODING_UTF16LE;
      break;
    case XML_ENCODING_UTF16BE:
      enc = XML_CHAR_ENCODING_UTF16BE;
      break;
    case XML_ENCODING_ASCII:
      enc = XML_CHAR_ENCODING_ASCII;
      break;
    default:
      break;
  }

  // Create the input buffer.
  xmlParserInputBufferPtr input_buffer = xmlAllocParserInputBuffer(enc);
  if (!input_buffer)
    return false;

  // Add a reference that will be released by xml_close_callback().
  stream->AddRef();
  
  input_buffer->context = stream.get();
	input_buffer->readcallback = xml_read_callback;
	input_buffer->closecallback = xml_close_callback;

  // Create the text reader.
  reader_ = xmlNewTextReader(input_buffer, WideToUTF8(URI).c_str());
  if (!reader_) {
    // Free the input buffer.
    xmlFreeParserInputBuffer(input_buffer);
    return false;
  }

  // Register the error callbacks.
  xmlTextReaderSetErrorHandler(reader_, xml_error_callback, this);
  xmlTextReaderSetStructuredErrorHandler(reader_,
      xml_structured_error_callback, this);
  
  return true;
}

bool CefXmlReaderImpl::MoveToNextElement()
{
  if (!VerifyContext())
    return false;

  return xmlTextReaderRead(reader_) == 1 ? true : false;
}

bool CefXmlReaderImpl::Close()
{
  if (!VerifyContext())
    return false;

  // The input buffer will be freed automatically.
  xmlFreeTextReader(reader_);
  reader_ = NULL;
  return true;
}

bool CefXmlReaderImpl::HasError()
{
  if (!VerifyContext())
    return false;

  return !error_buf_.str().empty();
}

std::wstring CefXmlReaderImpl::GetError()
{
  if (!VerifyContext())
    return std::wstring();

  return error_buf_.str();
}

CefXmlReader::NodeType CefXmlReaderImpl::GetType()
{
  if (!VerifyContext())
    return XML_NODE_UNSUPPORTED;

  switch (xmlTextReaderNodeType(reader_)) {
    case XML_READER_TYPE_ELEMENT:
      return XML_NODE_ELEMENT_START;
    case XML_READER_TYPE_END_ELEMENT:
      return XML_NODE_ELEMENT_END;
    case XML_READER_TYPE_ATTRIBUTE:
      return XML_NODE_ATTRIBUTE;
    case XML_READER_TYPE_TEXT:
      return XML_NODE_TEXT;
    case XML_READER_TYPE_SIGNIFICANT_WHITESPACE:
    case XML_READER_TYPE_WHITESPACE:
      return XML_NODE_WHITESPACE;
    case XML_READER_TYPE_CDATA:
      return XML_NODE_CDATA;
    case XML_READER_TYPE_ENTITY_REFERENCE:
      return XML_NODE_ENTITY_REFERENCE;
    case XML_READER_TYPE_PROCESSING_INSTRUCTION:
      return XML_NODE_PROCESSING_INSTRUCTION;
    case XML_READER_TYPE_COMMENT:
      return XML_NODE_COMMENT;
    case XML_READER_TYPE_DOCUMENT_TYPE:
      return XML_NODE_DOCUMENT_TYPE;
    default:
      break;
  }

  return XML_NODE_UNSUPPORTED;
}

int CefXmlReaderImpl::GetDepth()
{
  if (!VerifyContext())
    return -1;

  return xmlTextReaderDepth(reader_);
}

std::wstring CefXmlReaderImpl::GetLocalName()
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderConstLocalName(reader_), false);
}

std::wstring CefXmlReaderImpl::GetPrefix()
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderConstPrefix(reader_), false);
}

std::wstring CefXmlReaderImpl::GetQualifiedName()
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderConstName(reader_), false);
}

std::wstring CefXmlReaderImpl::GetNamespaceURI()
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderConstNamespaceUri(reader_), false);
}

std::wstring CefXmlReaderImpl::GetBaseURI()
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderConstBaseUri(reader_), false);
}

std::wstring CefXmlReaderImpl::GetXmlLang()
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderConstXmlLang(reader_), false);
}

bool CefXmlReaderImpl::IsEmptyElement()
{
  if (!VerifyContext())
    return false;

  return xmlTextReaderIsEmptyElement(reader_) == 1 ? true : false;
}

bool CefXmlReaderImpl::HasValue()
{
  if (!VerifyContext())
    return false;

  if (xmlTextReaderNodeType(reader_) == XML_READER_TYPE_ENTITY_REFERENCE) {
    // Provide special handling to return entity reference values.
    return true;
  } else {
    return xmlTextReaderHasValue(reader_) == 1 ? true : false;
  }
}

std::wstring CefXmlReaderImpl::GetValue()
{
  if (!VerifyContext())
    return std::wstring();

  if (xmlTextReaderNodeType(reader_) == XML_READER_TYPE_ENTITY_REFERENCE) {
    // Provide special handling to return entity reference values.
    xmlNodePtr node = xmlTextReaderCurrentNode(reader_);
    if (node->content != NULL)
      return xmlCharToWString(node->content, false);
    return NULL;
  } else {
    return xmlCharToWString(xmlTextReaderConstValue(reader_), false);
  }
}

bool CefXmlReaderImpl::HasAttributes()
{
  if (!VerifyContext())
    return false;

  return xmlTextReaderHasAttributes(reader_) == 1 ? true : false;
}

size_t CefXmlReaderImpl::GetAttributeCount()
{
  if (!VerifyContext())
    return 0;

  return xmlTextReaderAttributeCount(reader_);
}

std::wstring CefXmlReaderImpl::GetAttribute(int index)
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderGetAttributeNo(reader_, index), true);
}

std::wstring CefXmlReaderImpl::GetAttribute(const std::wstring& qualifiedName)
{
  if (!VerifyContext())
    return std::wstring();

  std::string qualifiedNameStr = WideToUTF8(qualifiedName);
  return xmlCharToWString(xmlTextReaderGetAttribute(reader_,
      BAD_CAST qualifiedNameStr.c_str()), true);
}

std::wstring CefXmlReaderImpl::GetAttribute(const std::wstring& localName,
                                            const std::wstring& namespaceURI)
{
  if (!VerifyContext())
    return std::wstring();

  std::string localNameStr = WideToUTF8(localName);
  std::string namespaceURIStr = WideToUTF8(namespaceURI);
  return xmlCharToWString(xmlTextReaderGetAttributeNs(reader_,
      BAD_CAST localNameStr.c_str(), BAD_CAST namespaceURIStr.c_str()), true);
}

std::wstring CefXmlReaderImpl::GetInnerXml()
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderReadInnerXml(reader_), true);
}

std::wstring CefXmlReaderImpl::GetOuterXml()
{
  if (!VerifyContext())
    return std::wstring();

  return xmlCharToWString(xmlTextReaderReadOuterXml(reader_), true);
}

int CefXmlReaderImpl::GetLineNumber()
{
  if (!VerifyContext())
    return -1;

  return xmlTextReaderGetParserLineNumber(reader_);
}

bool CefXmlReaderImpl::MoveToAttribute(int index)
{
  if (!VerifyContext())
    return false;

  return xmlTextReaderMoveToAttributeNo(reader_, index) == 1 ? true : false;
}

bool CefXmlReaderImpl::MoveToAttribute(const std::wstring& qualifiedName)
{
  if (!VerifyContext())
    return false;

  std::string qualifiedNameStr = WideToUTF8(qualifiedName);
  return xmlTextReaderMoveToAttribute(reader_,
      BAD_CAST qualifiedNameStr.c_str()) == 1 ? true : false;
}

bool CefXmlReaderImpl::MoveToAttribute(const std::wstring& localName,
                                       const std::wstring& namespaceURI)
{
  if (!VerifyContext())
    return false;

  std::string localNameStr = WideToUTF8(localName);
  std::string namespaceURIStr = WideToUTF8(namespaceURI);
  return xmlTextReaderMoveToAttributeNs(reader_,
      BAD_CAST localNameStr.c_str(), BAD_CAST namespaceURIStr.c_str()) == 1 ?
      true : false;
}

bool CefXmlReaderImpl::MoveToFirstAttribute()
{
  if (!VerifyContext())
    return false;

  return xmlTextReaderMoveToFirstAttribute(reader_) == 1 ? true : false;
}

bool CefXmlReaderImpl::MoveToNextAttribute()
{
  if (!VerifyContext())
    return false;

  return xmlTextReaderMoveToNextAttribute(reader_) == 1 ? true : false;
}

bool CefXmlReaderImpl::MoveToCarryingElement()
{
  if (!VerifyContext())
    return false;

  return xmlTextReaderMoveToElement(reader_) == 1 ? true : false;
}

void CefXmlReaderImpl::AppendError(const std::wstring& error_str)
{
  if (!error_buf_.str().empty())
    error_buf_ << L"\n";
  error_buf_ << error_str;
}

bool CefXmlReaderImpl::VerifyContext()
{
  if (PlatformThread::CurrentId() != supported_thread_id_) {
    // This object should only be accessed from the thread that created it.
    NOTREACHED();
    return false;
  }

  return (reader_ != NULL);
}
