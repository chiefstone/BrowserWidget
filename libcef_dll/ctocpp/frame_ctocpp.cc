// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/ctocpp/frame_ctocpp.h"
#include "libcef_dll/ctocpp/request_ctocpp.h"
#include "libcef_dll/ctocpp/stream_reader_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

void CefFrameCToCpp::Undo()
{
  if(CEF_MEMBER_MISSING(struct_, undo))
    return;
  
  struct_->undo(struct_);
}

void CefFrameCToCpp::Redo()
{
  if(CEF_MEMBER_MISSING(struct_, redo))
    return;
  
  struct_->redo(struct_);
}

void CefFrameCToCpp::Cut()
{
  if(CEF_MEMBER_MISSING(struct_, cut))
    return;
  
  struct_->cut(struct_);
}

void CefFrameCToCpp::Copy()
{
  if(CEF_MEMBER_MISSING(struct_, copy))
    return;
  
  struct_->copy(struct_);
}

void CefFrameCToCpp::Paste()
{
  if(CEF_MEMBER_MISSING(struct_, paste))
    return;
  
  struct_->paste(struct_);
}

void CefFrameCToCpp::Delete()
{
  if(CEF_MEMBER_MISSING(struct_, del))
    return;
  
  struct_->del(struct_);
}

void CefFrameCToCpp::SelectAll()
{
  if(CEF_MEMBER_MISSING(struct_, select_all))
    return;
  
  struct_->select_all(struct_);
}

void CefFrameCToCpp::Print()
{
  if(CEF_MEMBER_MISSING(struct_, print))
    return;
  
  struct_->print(struct_);
}

void CefFrameCToCpp::ViewSource()
{
  if(CEF_MEMBER_MISSING(struct_, view_source))
    return;
  
  struct_->view_source(struct_);
}

CefString CefFrameCToCpp::GetSource()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_source))
    return str;

  cef_string_userfree_t strPtr = struct_->get_source(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}

CefString CefFrameCToCpp::GetText()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_text))
    return str;

  cef_string_userfree_t strPtr = struct_->get_text(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}

void CefFrameCToCpp::LoadRequest(CefRefPtr<CefRequest> request)
{
  if(CEF_MEMBER_MISSING(struct_, load_request))
    return;

  struct_->load_request(struct_, CefRequestCToCpp::Unwrap(request));
}

void CefFrameCToCpp::LoadURL(const CefString& url)
{
  if(CEF_MEMBER_MISSING(struct_, load_url))
    return;

  struct_->load_url(struct_, url.GetStruct());
}

void CefFrameCToCpp::LoadString(const CefString& string, const CefString& url)
{
  if(CEF_MEMBER_MISSING(struct_, load_string))
    return;
  
  struct_->load_string(struct_, string.GetStruct(), url.GetStruct());
}

void CefFrameCToCpp::LoadStream(CefRefPtr<CefStreamReader> stream,
    const CefString& url)
{
  if(CEF_MEMBER_MISSING(struct_, load_stream))
    return;

  struct_->load_stream(struct_, CefStreamReaderCToCpp::Unwrap(stream),
      url.GetStruct());
}

void CefFrameCToCpp::ExecuteJavaScript(const CefString& jsCode,
    const CefString& scriptUrl, int startLine)
{
  if(CEF_MEMBER_MISSING(struct_, execute_java_script))
    return;

  struct_->execute_java_script(struct_, jsCode.GetStruct(),
      scriptUrl.GetStruct(), startLine);
}

bool CefFrameCToCpp::IsMain()
{
  if(CEF_MEMBER_MISSING(struct_, is_main))
    return false;

  return struct_->is_main(struct_)?true:false;
}

bool CefFrameCToCpp::IsFocused()
{
  if(CEF_MEMBER_MISSING(struct_, is_focused))
    return false;

  return struct_->is_focused(struct_)?true:false;
}

CefString CefFrameCToCpp::GetName()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_name))
    return str;

  cef_string_userfree_t strPtr = struct_->get_name(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}

CefString CefFrameCToCpp::GetURL()
{
  CefString str;
  if(CEF_MEMBER_MISSING(struct_, get_url))
    return str;

  cef_string_userfree_t strPtr = struct_->get_url(struct_);
  str.AttachToUserFree(strPtr);
  return str;
}


#ifdef _DEBUG
long CefCToCpp<CefFrameCToCpp, CefFrame, cef_frame_t>::DebugObjCt = 0;
#endif

