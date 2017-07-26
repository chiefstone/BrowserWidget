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
// $hash=c2256192e44464a7c89f2e43619a92049d1c080c$
//

#include "libcef_dll/ctocpp/views/window_delegate_ctocpp.h"
#include "libcef_dll/cpptoc/views/view_cpptoc.h"
#include "libcef_dll/cpptoc/views/window_cpptoc.h"

// VIRTUAL METHODS - Body may be edited by hand.

void CefWindowDelegateCToCpp::OnWindowCreated(CefRefPtr<CefWindow> window) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_window_created))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return;

  // Execute
  _struct->on_window_created(_struct, CefWindowCppToC::Wrap(window));
}

void CefWindowDelegateCToCpp::OnWindowDestroyed(CefRefPtr<CefWindow> window) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_window_destroyed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return;

  // Execute
  _struct->on_window_destroyed(_struct, CefWindowCppToC::Wrap(window));
}

bool CefWindowDelegateCToCpp::IsFrameless(CefRefPtr<CefWindow> window) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_frameless))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return false;

  // Execute
  int _retval = _struct->is_frameless(_struct, CefWindowCppToC::Wrap(window));

  // Return type: bool
  return _retval ? true : false;
}

bool CefWindowDelegateCToCpp::CanResize(CefRefPtr<CefWindow> window) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_resize))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return false;

  // Execute
  int _retval = _struct->can_resize(_struct, CefWindowCppToC::Wrap(window));

  // Return type: bool
  return _retval ? true : false;
}

bool CefWindowDelegateCToCpp::CanMaximize(CefRefPtr<CefWindow> window) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_maximize))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return false;

  // Execute
  int _retval = _struct->can_maximize(_struct, CefWindowCppToC::Wrap(window));

  // Return type: bool
  return _retval ? true : false;
}

bool CefWindowDelegateCToCpp::CanMinimize(CefRefPtr<CefWindow> window) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_minimize))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return false;

  // Execute
  int _retval = _struct->can_minimize(_struct, CefWindowCppToC::Wrap(window));

  // Return type: bool
  return _retval ? true : false;
}

bool CefWindowDelegateCToCpp::CanClose(CefRefPtr<CefWindow> window) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_close))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return false;

  // Execute
  int _retval = _struct->can_close(_struct, CefWindowCppToC::Wrap(window));

  // Return type: bool
  return _retval ? true : false;
}

bool CefWindowDelegateCToCpp::OnAccelerator(CefRefPtr<CefWindow> window,
                                            int command_id) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_accelerator))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return false;

  // Execute
  int _retval = _struct->on_accelerator(_struct, CefWindowCppToC::Wrap(window),
                                        command_id);

  // Return type: bool
  return _retval ? true : false;
}

bool CefWindowDelegateCToCpp::OnKeyEvent(CefRefPtr<CefWindow> window,
                                         const CefKeyEvent& event) {
  cef_window_delegate_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_key_event))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: window; type: refptr_diff
  DCHECK(window.get());
  if (!window.get())
    return false;

  // Execute
  int _retval =
      _struct->on_key_event(_struct, CefWindowCppToC::Wrap(window), &event);

  // Return type: bool
  return _retval ? true : false;
}

CefSize CefWindowDelegateCToCpp::GetPreferredSize(CefRefPtr<CefView> view) {
  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_preferred_size))
    return CefSize();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return CefSize();

  // Execute
  cef_size_t _retval =
      _struct->get_preferred_size(_struct, CefViewCppToC::Wrap(view));

  // Return type: simple
  return _retval;
}

CefSize CefWindowDelegateCToCpp::GetMinimumSize(CefRefPtr<CefView> view) {
  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_minimum_size))
    return CefSize();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return CefSize();

  // Execute
  cef_size_t _retval =
      _struct->get_minimum_size(_struct, CefViewCppToC::Wrap(view));

  // Return type: simple
  return _retval;
}

CefSize CefWindowDelegateCToCpp::GetMaximumSize(CefRefPtr<CefView> view) {
  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_maximum_size))
    return CefSize();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return CefSize();

  // Execute
  cef_size_t _retval =
      _struct->get_maximum_size(_struct, CefViewCppToC::Wrap(view));

  // Return type: simple
  return _retval;
}

int CefWindowDelegateCToCpp::GetHeightForWidth(CefRefPtr<CefView> view,
                                               int width) {
  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, get_height_for_width))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return 0;

  // Execute
  int _retval =
      _struct->get_height_for_width(_struct, CefViewCppToC::Wrap(view), width);

  // Return type: simple
  return _retval;
}

void CefWindowDelegateCToCpp::OnParentViewChanged(CefRefPtr<CefView> view,
                                                  bool added,
                                                  CefRefPtr<CefView> parent) {
  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_parent_view_changed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return;
  // Verify param: parent; type: refptr_diff
  DCHECK(parent.get());
  if (!parent.get())
    return;

  // Execute
  _struct->on_parent_view_changed(_struct, CefViewCppToC::Wrap(view), added,
                                  CefViewCppToC::Wrap(parent));
}

void CefWindowDelegateCToCpp::OnChildViewChanged(CefRefPtr<CefView> view,
                                                 bool added,
                                                 CefRefPtr<CefView> child) {
  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_child_view_changed))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return;
  // Verify param: child; type: refptr_diff
  DCHECK(child.get());
  if (!child.get())
    return;

  // Execute
  _struct->on_child_view_changed(_struct, CefViewCppToC::Wrap(view), added,
                                 CefViewCppToC::Wrap(child));
}

void CefWindowDelegateCToCpp::OnFocus(CefRefPtr<CefView> view) {
  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_focus))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return;

  // Execute
  _struct->on_focus(_struct, CefViewCppToC::Wrap(view));
}

void CefWindowDelegateCToCpp::OnBlur(CefRefPtr<CefView> view) {
  cef_view_delegate_t* _struct =
      reinterpret_cast<cef_view_delegate_t*>(GetStruct());
  if (CEF_MEMBER_MISSING(_struct, on_blur))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: view; type: refptr_diff
  DCHECK(view.get());
  if (!view.get())
    return;

  // Execute
  _struct->on_blur(_struct, CefViewCppToC::Wrap(view));
}

// CONSTRUCTOR - Do not edit by hand.

CefWindowDelegateCToCpp::CefWindowDelegateCToCpp() {}

template <>
cef_window_delegate_t* CefCToCppRefCounted<
    CefWindowDelegateCToCpp,
    CefWindowDelegate,
    cef_window_delegate_t>::UnwrapDerived(CefWrapperType type,
                                          CefWindowDelegate* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCToCppRefCounted<CefWindowDelegateCToCpp,
                                         CefWindowDelegate,
                                         cef_window_delegate_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCToCppRefCounted<CefWindowDelegateCToCpp,
                                   CefWindowDelegate,
                                   cef_window_delegate_t>::kWrapperType =
    WT_WINDOW_DELEGATE;
