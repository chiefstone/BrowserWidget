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
// $hash=95b47a7c128c1ddb4ba842ac13fc344d51cc96dd$
//

#include "libcef_dll/ctocpp/set_cookie_callback_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

void CefSetCookieCallbackCToCpp::OnComplete(bool success) {
  cef_set_cookie_callback_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_complete))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->on_complete(_struct, success);
}

// CONSTRUCTOR - Do not edit by hand.

CefSetCookieCallbackCToCpp::CefSetCookieCallbackCToCpp() {}

template <>
cef_set_cookie_callback_t* CefCToCppRefCounted<
    CefSetCookieCallbackCToCpp,
    CefSetCookieCallback,
    cef_set_cookie_callback_t>::UnwrapDerived(CefWrapperType type,
                                              CefSetCookieCallback* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCToCppRefCounted<CefSetCookieCallbackCToCpp,
                                         CefSetCookieCallback,
                                         cef_set_cookie_callback_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCToCppRefCounted<CefSetCookieCallbackCToCpp,
                                   CefSetCookieCallback,
                                   cef_set_cookie_callback_t>::kWrapperType =
    WT_SET_COOKIE_CALLBACK;
