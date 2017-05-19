// Copyright (c) 2017 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=a5cfbfd7e733f9874caf3bff213719d3267d3287$
//

#include "libcef_dll/cpptoc/zip_reader_cpptoc.h"
#include "libcef_dll/cpptoc/stream_reader_cpptoc.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_zip_reader_t* cef_zip_reader_create(
    cef_stream_reader_t* stream) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: stream; type: refptr_same
  DCHECK(stream);
  if (!stream)
    return NULL;

  // Execute
  CefRefPtr<CefZipReader> _retval =
      CefZipReader::Create(CefStreamReaderCppToC::Unwrap(stream));

  // Return type: refptr_same
  return CefZipReaderCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK zip_reader_move_to_first_file(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefZipReaderCppToC::Get(self)->MoveToFirstFile();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK zip_reader_move_to_next_file(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefZipReaderCppToC::Get(self)->MoveToNextFile();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK zip_reader_move_to_file(struct _cef_zip_reader_t* self,
                                         const cef_string_t* fileName,
                                         int caseSensitive) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: fileName; type: string_byref_const
  DCHECK(fileName);
  if (!fileName)
    return 0;

  // Execute
  bool _retval = CefZipReaderCppToC::Get(self)->MoveToFile(
      CefString(fileName), caseSensitive ? true : false);

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK zip_reader_close(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefZipReaderCppToC::Get(self)->Close();

  // Return type: bool
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK
zip_reader_get_file_name(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefZipReaderCppToC::Get(self)->GetFileName();

  // Return type: string
  return _retval.DetachToUserFree();
}

int64 CEF_CALLBACK zip_reader_get_file_size(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int64 _retval = CefZipReaderCppToC::Get(self)->GetFileSize();

  // Return type: simple
  return _retval;
}

cef_time_t CEF_CALLBACK
zip_reader_get_file_last_modified(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefTime();

  // Execute
  cef_time_t _retval = CefZipReaderCppToC::Get(self)->GetFileLastModified();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK zip_reader_open_file(struct _cef_zip_reader_t* self,
                                      const cef_string_t* password) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Unverified params: password

  // Execute
  bool _retval = CefZipReaderCppToC::Get(self)->OpenFile(CefString(password));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK zip_reader_close_file(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefZipReaderCppToC::Get(self)->CloseFile();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK zip_reader_read_file(struct _cef_zip_reader_t* self,
                                      void* buffer,
                                      size_t bufferSize) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: buffer; type: simple_byaddr
  DCHECK(buffer);
  if (!buffer)
    return 0;

  // Execute
  int _retval = CefZipReaderCppToC::Get(self)->ReadFile(buffer, bufferSize);

  // Return type: simple
  return _retval;
}

int64 CEF_CALLBACK zip_reader_tell(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int64 _retval = CefZipReaderCppToC::Get(self)->Tell();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK zip_reader_eof(struct _cef_zip_reader_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefZipReaderCppToC::Get(self)->Eof();

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefZipReaderCppToC::CefZipReaderCppToC() {
  GetStruct()->move_to_first_file = zip_reader_move_to_first_file;
  GetStruct()->move_to_next_file = zip_reader_move_to_next_file;
  GetStruct()->move_to_file = zip_reader_move_to_file;
  GetStruct()->close = zip_reader_close;
  GetStruct()->get_file_name = zip_reader_get_file_name;
  GetStruct()->get_file_size = zip_reader_get_file_size;
  GetStruct()->get_file_last_modified = zip_reader_get_file_last_modified;
  GetStruct()->open_file = zip_reader_open_file;
  GetStruct()->close_file = zip_reader_close_file;
  GetStruct()->read_file = zip_reader_read_file;
  GetStruct()->tell = zip_reader_tell;
  GetStruct()->eof = zip_reader_eof;
}

template <>
CefRefPtr<CefZipReader>
CefCppToCRefCounted<CefZipReaderCppToC, CefZipReader, cef_zip_reader_t>::
    UnwrapDerived(CefWrapperType type, cef_zip_reader_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<CefZipReaderCppToC,
                                         CefZipReader,
                                         cef_zip_reader_t>::DebugObjCt = 0;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefZipReaderCppToC,
                                   CefZipReader,
                                   cef_zip_reader_t>::kWrapperType =
    WT_ZIP_READER;
