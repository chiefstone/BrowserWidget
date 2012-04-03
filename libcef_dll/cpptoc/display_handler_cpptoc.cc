// Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
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

#include "libcef_dll/cpptoc/display_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK display_handler_on_loading_state_change(
    struct _cef_display_handler_t* self, cef_browser_t* browser, int isLoading,
    int canGoBack, int canGoForward) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnLoadingStateChange(
      CefBrowserCToCpp::Wrap(browser),
      isLoading?true:false,
      canGoBack?true:false,
      canGoForward?true:false);
}

void CEF_CALLBACK display_handler_on_address_change(
    struct _cef_display_handler_t* self, cef_browser_t* browser,
    struct _cef_frame_t* frame, const cef_string_t* url) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame)
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return;

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnAddressChange(
      CefBrowserCToCpp::Wrap(browser),
      CefFrameCToCpp::Wrap(frame),
      CefString(url));
}

void CEF_CALLBACK display_handler_on_title_change(
    struct _cef_display_handler_t* self, cef_browser_t* browser,
    const cef_string_t* title) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Unverified params: title

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnTitleChange(
      CefBrowserCToCpp::Wrap(browser),
      CefString(title));
}

int CEF_CALLBACK display_handler_on_tooltip(struct _cef_display_handler_t* self,
    cef_browser_t* browser, cef_string_t* text) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Unverified params: text

  // Translate param: text; type: string_byref
  CefString textStr(text);

  // Execute
  bool _retval = CefDisplayHandlerCppToC::Get(self)->OnTooltip(
      CefBrowserCToCpp::Wrap(browser),
      textStr);

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK display_handler_on_status_message(
    struct _cef_display_handler_t* self, cef_browser_t* browser,
    const cef_string_t* value, enum cef_handler_statustype_t type) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return;
  // Unverified params: value

  // Execute
  CefDisplayHandlerCppToC::Get(self)->OnStatusMessage(
      CefBrowserCToCpp::Wrap(browser),
      CefString(value),
      type);
}

int CEF_CALLBACK display_handler_on_console_message(
    struct _cef_display_handler_t* self, cef_browser_t* browser,
    const cef_string_t* message, const cef_string_t* source, int line) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser)
    return 0;
  // Unverified params: message, source

  // Execute
  bool _retval = CefDisplayHandlerCppToC::Get(self)->OnConsoleMessage(
      CefBrowserCToCpp::Wrap(browser),
      CefString(message),
      CefString(source),
      line);

  // Return type: bool
  return _retval;
}


// CONSTRUCTOR - Do not edit by hand.

CefDisplayHandlerCppToC::CefDisplayHandlerCppToC(CefDisplayHandler* cls)
    : CefCppToC<CefDisplayHandlerCppToC, CefDisplayHandler,
        cef_display_handler_t>(cls) {
  struct_.struct_.on_loading_state_change =
      display_handler_on_loading_state_change;
  struct_.struct_.on_address_change = display_handler_on_address_change;
  struct_.struct_.on_title_change = display_handler_on_title_change;
  struct_.struct_.on_tooltip = display_handler_on_tooltip;
  struct_.struct_.on_status_message = display_handler_on_status_message;
  struct_.struct_.on_console_message = display_handler_on_console_message;
}

#ifndef NDEBUG
template<> long CefCppToC<CefDisplayHandlerCppToC, CefDisplayHandler,
    cef_display_handler_t>::DebugObjCt = 0;
#endif

