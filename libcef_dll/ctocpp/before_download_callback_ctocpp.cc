// Copyright (c) 2020 The Chromium Embedded Framework Authors. All rights
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
// $hash=80acec0f2efd94bad9a4de54cd9eb5c9e21d8f8b$
//

#include "libcef_dll/ctocpp/before_download_callback_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void CefBeforeDownloadCallbackCToCpp::Continue(const CefString& download_path,
                                               bool show_dialog) {
  shutdown_checker::AssertNotShutdown();

  cef_before_download_callback_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, cont))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: download_path

  // Execute
  _struct->cont(_struct, download_path.GetStruct(), show_dialog);
}

// CONSTRUCTOR - Do not edit by hand.

CefBeforeDownloadCallbackCToCpp::CefBeforeDownloadCallbackCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefBeforeDownloadCallbackCToCpp::~CefBeforeDownloadCallbackCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_before_download_callback_t* CefCToCppRefCounted<
    CefBeforeDownloadCallbackCToCpp,
    CefBeforeDownloadCallback,
    cef_before_download_callback_t>::UnwrapDerived(CefWrapperType type,
                                                   CefBeforeDownloadCallback*
                                                       c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

template <>
CefWrapperType
    CefCToCppRefCounted<CefBeforeDownloadCallbackCToCpp,
                        CefBeforeDownloadCallback,
                        cef_before_download_callback_t>::kWrapperType =
        WT_BEFORE_DOWNLOAD_CALLBACK;
