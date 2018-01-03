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
// $hash=5bd0f16810c3c46a19a5f64133e02e4681675f04$
//

#include "libcef_dll/cpptoc/geolocation_callback_cpptoc.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK
geolocation_callback_cont(struct _cef_geolocation_callback_t* self, int allow) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefGeolocationCallbackCppToC::Get(self)->Continue(allow ? true : false);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefGeolocationCallbackCppToC::CefGeolocationCallbackCppToC() {
  GetStruct()->cont = geolocation_callback_cont;
}

template <>
CefRefPtr<CefGeolocationCallback> CefCppToCRefCounted<
    CefGeolocationCallbackCppToC,
    CefGeolocationCallback,
    cef_geolocation_callback_t>::UnwrapDerived(CefWrapperType type,
                                               cef_geolocation_callback_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<CefGeolocationCallbackCppToC,
                                         CefGeolocationCallback,
                                         cef_geolocation_callback_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefGeolocationCallbackCppToC,
                                   CefGeolocationCallback,
                                   cef_geolocation_callback_t>::kWrapperType =
    WT_GEOLOCATION_CALLBACK;
