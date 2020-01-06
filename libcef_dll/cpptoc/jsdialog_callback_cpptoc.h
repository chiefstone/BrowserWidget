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
// $hash=9ca357bc7ca56079e4136481bcefba7fe8925b04$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_JSDIALOG_CALLBACK_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_JSDIALOG_CALLBACK_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_jsdialog_handler_capi.h"
#include "include/cef_jsdialog_handler.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefJSDialogCallbackCppToC
    : public CefCppToCRefCounted<CefJSDialogCallbackCppToC,
                                 CefJSDialogCallback,
                                 cef_jsdialog_callback_t> {
 public:
  CefJSDialogCallbackCppToC();
  virtual ~CefJSDialogCallbackCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_JSDIALOG_CALLBACK_CPPTOC_H_
