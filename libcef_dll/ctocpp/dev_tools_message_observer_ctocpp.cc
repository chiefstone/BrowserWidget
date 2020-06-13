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
// $hash=e8d1eaf4b8cdfd79a260de33fb3be05a2948c81e$
//

#include "libcef_dll/ctocpp/dev_tools_message_observer_ctocpp.h"
#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
bool CefDevToolsMessageObserverCToCpp::OnDevToolsMessage(
    CefRefPtr<CefBrowser> browser,
    const void* message,
    size_t message_size) {
  shutdown_checker::AssertNotShutdown();

  cef_dev_tools_message_observer_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_dev_tools_message))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: message; type: simple_byaddr
  DCHECK(message);
  if (!message)
    return false;

  // Execute
  int _retval = _struct->on_dev_tools_message(
      _struct, CefBrowserCppToC::Wrap(browser), message, message_size);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void CefDevToolsMessageObserverCToCpp::OnDevToolsMethodResult(
    CefRefPtr<CefBrowser> browser,
    int message_id,
    bool success,
    const void* result,
    size_t result_size) {
  shutdown_checker::AssertNotShutdown();

  cef_dev_tools_message_observer_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_dev_tools_method_result))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Unverified params: result

  // Execute
  _struct->on_dev_tools_method_result(_struct, CefBrowserCppToC::Wrap(browser),
                                      message_id, success, result, result_size);
}

NO_SANITIZE("cfi-icall")
void CefDevToolsMessageObserverCToCpp::OnDevToolsEvent(
    CefRefPtr<CefBrowser> browser,
    const CefString& method,
    const void* params,
    size_t params_size) {
  shutdown_checker::AssertNotShutdown();

  cef_dev_tools_message_observer_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_dev_tools_event))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: method; type: string_byref_const
  DCHECK(!method.empty());
  if (method.empty())
    return;
  // Unverified params: params

  // Execute
  _struct->on_dev_tools_event(_struct, CefBrowserCppToC::Wrap(browser),
                              method.GetStruct(), params, params_size);
}

NO_SANITIZE("cfi-icall")
void CefDevToolsMessageObserverCToCpp::OnDevToolsAgentAttached(
    CefRefPtr<CefBrowser> browser) {
  shutdown_checker::AssertNotShutdown();

  cef_dev_tools_message_observer_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_dev_tools_agent_attached))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;

  // Execute
  _struct->on_dev_tools_agent_attached(_struct,
                                       CefBrowserCppToC::Wrap(browser));
}

NO_SANITIZE("cfi-icall")
void CefDevToolsMessageObserverCToCpp::OnDevToolsAgentDetached(
    CefRefPtr<CefBrowser> browser) {
  shutdown_checker::AssertNotShutdown();

  cef_dev_tools_message_observer_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_dev_tools_agent_detached))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;

  // Execute
  _struct->on_dev_tools_agent_detached(_struct,
                                       CefBrowserCppToC::Wrap(browser));
}

// CONSTRUCTOR - Do not edit by hand.

CefDevToolsMessageObserverCToCpp::CefDevToolsMessageObserverCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefDevToolsMessageObserverCToCpp::~CefDevToolsMessageObserverCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_dev_tools_message_observer_t* CefCToCppRefCounted<
    CefDevToolsMessageObserverCToCpp,
    CefDevToolsMessageObserver,
    cef_dev_tools_message_observer_t>::UnwrapDerived(CefWrapperType type,
                                                     CefDevToolsMessageObserver*
                                                         c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType
    CefCToCppRefCounted<CefDevToolsMessageObserverCToCpp,
                        CefDevToolsMessageObserver,
                        cef_dev_tools_message_observer_t>::kWrapperType =
        WT_DEV_TOOLS_MESSAGE_OBSERVER;
