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
// $hash=416023b2c36043987ebe05f5467b838319d3f063$
//

#include "libcef_dll/ctocpp/client_ctocpp.h"
#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/process_message_cpptoc.h"
#include "libcef_dll/ctocpp/context_menu_handler_ctocpp.h"
#include "libcef_dll/ctocpp/dialog_handler_ctocpp.h"
#include "libcef_dll/ctocpp/display_handler_ctocpp.h"
#include "libcef_dll/ctocpp/download_handler_ctocpp.h"
#include "libcef_dll/ctocpp/drag_handler_ctocpp.h"
#include "libcef_dll/ctocpp/find_handler_ctocpp.h"
#include "libcef_dll/ctocpp/focus_handler_ctocpp.h"
#include "libcef_dll/ctocpp/jsdialog_handler_ctocpp.h"
#include "libcef_dll/ctocpp/keyboard_handler_ctocpp.h"
#include "libcef_dll/ctocpp/life_span_handler_ctocpp.h"
#include "libcef_dll/ctocpp/load_handler_ctocpp.h"
#include "libcef_dll/ctocpp/render_handler_ctocpp.h"
#include "libcef_dll/ctocpp/request_handler_ctocpp.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefContextMenuHandler> CefClientCToCpp::GetContextMenuHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_context_menu_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_context_menu_handler_t* _retval =
      _struct->get_context_menu_handler(_struct);

  // Return type: refptr_same
  return CefContextMenuHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDialogHandler> CefClientCToCpp::GetDialogHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_dialog_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_dialog_handler_t* _retval = _struct->get_dialog_handler(_struct);

  // Return type: refptr_same
  return CefDialogHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDisplayHandler> CefClientCToCpp::GetDisplayHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_display_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_display_handler_t* _retval = _struct->get_display_handler(_struct);

  // Return type: refptr_same
  return CefDisplayHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDownloadHandler> CefClientCToCpp::GetDownloadHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_download_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_download_handler_t* _retval = _struct->get_download_handler(_struct);

  // Return type: refptr_same
  return CefDownloadHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDragHandler> CefClientCToCpp::GetDragHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_drag_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_drag_handler_t* _retval = _struct->get_drag_handler(_struct);

  // Return type: refptr_same
  return CefDragHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefFindHandler> CefClientCToCpp::GetFindHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_find_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_find_handler_t* _retval = _struct->get_find_handler(_struct);

  // Return type: refptr_same
  return CefFindHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefFocusHandler> CefClientCToCpp::GetFocusHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_focus_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_focus_handler_t* _retval = _struct->get_focus_handler(_struct);

  // Return type: refptr_same
  return CefFocusHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefJSDialogHandler> CefClientCToCpp::GetJSDialogHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_jsdialog_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_jsdialog_handler_t* _retval = _struct->get_jsdialog_handler(_struct);

  // Return type: refptr_same
  return CefJSDialogHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefKeyboardHandler> CefClientCToCpp::GetKeyboardHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_keyboard_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_keyboard_handler_t* _retval = _struct->get_keyboard_handler(_struct);

  // Return type: refptr_same
  return CefKeyboardHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefLifeSpanHandler> CefClientCToCpp::GetLifeSpanHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_life_span_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_life_span_handler_t* _retval = _struct->get_life_span_handler(_struct);

  // Return type: refptr_same
  return CefLifeSpanHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefLoadHandler> CefClientCToCpp::GetLoadHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_load_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_load_handler_t* _retval = _struct->get_load_handler(_struct);

  // Return type: refptr_same
  return CefLoadHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefRenderHandler> CefClientCToCpp::GetRenderHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_render_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_render_handler_t* _retval = _struct->get_render_handler(_struct);

  // Return type: refptr_same
  return CefRenderHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefRequestHandler> CefClientCToCpp::GetRequestHandler() {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_request_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_request_handler_t* _retval = _struct->get_request_handler(_struct);

  // Return type: refptr_same
  return CefRequestHandlerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
bool CefClientCToCpp::OnProcessMessageReceived(
    CefRefPtr<CefBrowser> browser,
    CefProcessId source_process,
    CefRefPtr<CefProcessMessage> message) {
  cef_client_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_process_message_received))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: message; type: refptr_diff
  DCHECK(message.get());
  if (!message.get())
    return false;

  // Execute
  int _retval = _struct->on_process_message_received(
      _struct, CefBrowserCppToC::Wrap(browser), source_process,
      CefProcessMessageCppToC::Wrap(message));

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefClientCToCpp::CefClientCToCpp() {}

template <>
cef_client_t*
CefCToCppRefCounted<CefClientCToCpp, CefClient, cef_client_t>::UnwrapDerived(
    CefWrapperType type,
    CefClient* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount
    CefCToCppRefCounted<CefClientCToCpp, CefClient, cef_client_t>::DebugObjCt
        ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCToCppRefCounted<CefClientCToCpp, CefClient, cef_client_t>::
    kWrapperType = WT_CLIENT;
