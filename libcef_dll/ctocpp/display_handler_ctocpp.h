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
// $hash=834d40adeea090f273d3b4a1c47b5e5ab546f542$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_DISPLAY_HANDLER_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_DISPLAY_HANDLER_CTOCPP_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include <vector>
#include "include/capi/cef_display_handler_capi.h"
#include "include/cef_display_handler.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefDisplayHandlerCToCpp
    : public CefCToCppRefCounted<CefDisplayHandlerCToCpp,
                                 CefDisplayHandler,
                                 cef_display_handler_t> {
 public:
  CefDisplayHandlerCToCpp();

  // CefDisplayHandler methods.
  void OnAddressChange(CefRefPtr<CefBrowser> browser,
                       CefRefPtr<CefFrame> frame,
                       const CefString& url) override;
  void OnTitleChange(CefRefPtr<CefBrowser> browser,
                     const CefString& title) override;
  void OnFaviconURLChange(CefRefPtr<CefBrowser> browser,
                          const std::vector<CefString>& icon_urls) override;
  void OnFullscreenModeChange(CefRefPtr<CefBrowser> browser,
                              bool fullscreen) override;
  bool OnTooltip(CefRefPtr<CefBrowser> browser, CefString& text) override;
  void OnStatusMessage(CefRefPtr<CefBrowser> browser,
                       const CefString& value) override;
  bool OnConsoleMessage(CefRefPtr<CefBrowser> browser,
                        cef_log_severity_t level,
                        const CefString& message,
                        const CefString& source,
                        int line) override;
  bool OnAutoResize(CefRefPtr<CefBrowser> browser,
                    const CefSize& new_size) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_DISPLAY_HANDLER_CTOCPP_H_
