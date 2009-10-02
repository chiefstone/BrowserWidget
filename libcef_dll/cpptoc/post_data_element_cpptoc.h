// Copyright (c) 2009 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
#ifndef _POSTDATAELEMENT_CPPTOC_H
#define _POSTDATAELEMENT_CPPTOC_H

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else // BUILDING_CEF_SHARED

#include "include/cef.h"
#include "include/cef_capi.h"
#include "libcef_dll/cpptoc/cpptoc.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefPostDataElementCppToC
    : public CefCppToC<CefPostDataElementCppToC, CefPostDataElement,
        cef_post_data_element_t>
{
public:
  CefPostDataElementCppToC(CefPostDataElement* cls);
  virtual ~CefPostDataElementCppToC() {}
};

#endif // BUILDING_CEF_SHARED
#endif // _POSTDATAELEMENT_CPPTOC_H

