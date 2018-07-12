// Copyright (c) 2018 The Chromium Embedded Framework Authors. All rights
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
// $hash=c3f29dd98a52a1ce978bb30bb6a1680c9e1abca0$
//

#include "libcef_dll/ctocpp/read_handler_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
size_t CefReadHandlerCToCpp::Read(void* ptr, size_t size, size_t n) {
  cef_read_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, read))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: ptr; type: simple_byaddr
  DCHECK(ptr);
  if (!ptr)
    return 0;

  // Execute
  size_t _retval = _struct->read(_struct, ptr, size, n);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
int CefReadHandlerCToCpp::Seek(int64 offset, int whence) {
  cef_read_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, seek))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->seek(_struct, offset, whence);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int64 CefReadHandlerCToCpp::Tell() {
  cef_read_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, tell))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int64 _retval = _struct->tell(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") int CefReadHandlerCToCpp::Eof() {
  cef_read_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, eof))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->eof(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") bool CefReadHandlerCToCpp::MayBlock() {
  cef_read_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, may_block))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->may_block(_struct);

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefReadHandlerCToCpp::CefReadHandlerCToCpp() {}

template <>
cef_read_handler_t*
CefCToCppRefCounted<CefReadHandlerCToCpp, CefReadHandler, cef_read_handler_t>::
    UnwrapDerived(CefWrapperType type, CefReadHandler* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCToCppRefCounted<CefReadHandlerCToCpp,
                                         CefReadHandler,
                                         cef_read_handler_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCToCppRefCounted<CefReadHandlerCToCpp,
                                   CefReadHandler,
                                   cef_read_handler_t>::kWrapperType =
    WT_READ_HANDLER;
