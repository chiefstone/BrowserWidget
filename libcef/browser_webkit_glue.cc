// Copyright (c) 2008-2009 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2006-2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "precompiled_libcef.h"

#include "base/compiler_specific.h"
#include "base/logging.h"

#undef LOG
#include "config.h"
MSVC_PUSH_WARNING_LEVEL(0);
#include "Cache.h"
#include "TextEncoding.h"
#include "webkit/glue/webframe_impl.h"
MSVC_POP_WARNING();

#include "browser_webkit_glue.h"

#include "base/path_service.h"
#include "base/resource_util.h"
#include "base/scoped_ptr.h"
#include "base/string16.h"
#include "base/win_util.h"
#include "net/base/mime_util.h"
#include "webkit/api/public/WebFrame.h"
#include "webkit/glue/glue_util.h"
#include "webkit/glue/webkit_glue.h"

// Generated by GRIT
#include "grit/webkit_resources.h"

namespace webkit_glue {

bool IsMediaPlayerAvailable() {
  return true;
}

void PrecacheUrl(const char16* url, int url_length) {}

void AppendToLog(const char* file, int line, const char* msg) {
  logging::LogMessage(file, line).stream() << msg;
}

base::StringPiece GetRawDataResource(HMODULE module, int resource_id) {
  void* data_ptr;
  size_t data_size;
  return base::GetDataResourceFromModule(module, resource_id, &data_ptr,
                                         &data_size)
      ? base::StringPiece(static_cast<char*>(data_ptr), data_size)
      : base::StringPiece();
}

base::StringPiece NetResourceProvider(int key) {
  return GetRawDataResource(::GetModuleHandle(NULL), key);
}

base::StringPiece GetDataResource(int resource_id) {
  switch (resource_id) {
  case IDR_BROKENIMAGE: {
    // Use webkit's broken image icon (16x16)
    static unsigned char broken_image_data[] = {
      0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x10, 0x00, 0x10, 0x00, 0xD5, 0x00,
      0x00, 0x20, 0x68, 0xB0, 0x70, 0x98, 0xC0, 0x28, 0x78, 0xB8, 0x20, 0x70,
      0xB8, 0x88, 0xB8, 0xD8, 0x78, 0x98, 0xC8, 0x28, 0x80, 0xC0, 0xF8, 0xF8,
      0xF8, 0xF0, 0xF0, 0xF8, 0xE0, 0xE8, 0xF0, 0xD0, 0xE0, 0xF0, 0xB8, 0xD0,
      0xE8, 0xC0, 0xD8, 0xE8, 0x98, 0xC0, 0xE0, 0x68, 0x90, 0xC0, 0x70, 0x90,
      0xC0, 0x30, 0x80, 0xC0, 0x28, 0x88, 0xC0, 0x30, 0x78, 0xB8, 0x88, 0xB8,
      0xE0, 0x78, 0xA0, 0xC8, 0x20, 0x70, 0xB0, 0x90, 0xA8, 0xD0, 0x88, 0xA8,
      0xD0, 0x70, 0x98, 0xC8, 0x90, 0xB0, 0xD0, 0x80, 0xA0, 0xC8, 0x28, 0x88,
      0xC8, 0x20, 0x78, 0xB8, 0x40, 0x90, 0xC8, 0x50, 0x98, 0xC8, 0x28, 0x78,
      0xC0, 0x50, 0x90, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00, 0x06,
      0x8F, 0xC0, 0x8C, 0x70, 0x48, 0x2C, 0x66, 0x2C, 0x87, 0xA4, 0x72, 0xB9,
      0xB4, 0x20, 0x37, 0xD0, 0xA8, 0x14, 0x7A, 0xB0, 0x5C, 0x0E, 0x51, 0x83,
      0x76, 0x1B, 0x3D, 0x5C, 0xAE, 0x91, 0x88, 0x76, 0x32, 0x59, 0x34, 0x3A,
      0x86, 0xB0, 0x57, 0x73, 0xD8, 0x12, 0x12, 0x86, 0xCE, 0x21, 0xF1, 0xD1,
      0x1E, 0x34, 0xEC, 0xAD, 0x87, 0x20, 0x80, 0x1C, 0x10, 0x02, 0x76, 0x78,
      0x6D, 0x06, 0x1F, 0x02, 0x87, 0x0D, 0x0C, 0x20, 0x1C, 0x82, 0x14, 0x07,
      0x87, 0x87, 0x1C, 0x20, 0x04, 0x1C, 0x95, 0x87, 0x07, 0x14, 0x05, 0x07,
      0x95, 0x95, 0x03, 0x12, 0x12, 0x03, 0x9C, 0x1C, 0x07, 0x05, 0x18, 0x07,
      0x03, 0xA8, 0x03, 0x15, 0x0A, 0x0A, 0x15, 0xA9, 0x03, 0x07, 0x18, 0x01,
      0xA7, 0xA9, 0xAB, 0xAD, 0xAF, 0x07, 0x01, 0x0F, 0x07, 0x15, 0xBD, 0x15,
      0x00, 0xC0, 0x00, 0xBE, 0x15, 0x07, 0x0F, 0x0E, 0xBC, 0xC3, 0xC9, 0xBD,
      0x07, 0x0E, 0xC7, 0x4C, 0xCF, 0x49, 0xCD, 0xD2, 0xD3, 0xD4, 0xD2, 0x41,
      0x00, 0x3B
    };
    return base::StringPiece(reinterpret_cast<char*>(broken_image_data),
        static_cast<base::StringPiece::size_type>(
            sizeof(broken_image_data) / sizeof(unsigned char)));
  }
  case IDR_FEED_PREVIEW:
    // It is necessary to return a feed preview template that contains
    // a {{URL}} substring where the feed URL should go; see the code 
    // that computes feed previews in feed_preview.cc:MakeFeedPreview. 
    // This fixes issue #932714.    
    return "Feed preview for {{URL}}";
  case IDR_TEXTAREA_RESIZER: {
    // Use webkit's text area resizer image.
    static unsigned char area_resizer_data[] = {
      0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D,
      0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08,
      0x08, 0x06, 0x00, 0x00, 0x00, 0xC4, 0x0F, 0xBE, 0x8B, 0x00, 0x00, 0x00,
      0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x0B, 0x13, 0x00, 0x00, 0x0B,
      0x13, 0x01, 0x00, 0x9A, 0x9C, 0x18, 0x00, 0x00, 0x00, 0x04, 0x67, 0x41,
      0x4D, 0x41, 0x00, 0x00, 0xB1, 0x8E, 0x7C, 0xFB, 0x51, 0x93, 0x00, 0x00,
      0x00, 0x20, 0x63, 0x48, 0x52, 0x4D, 0x00, 0x00, 0x7A, 0x25, 0x00, 0x00,
      0x80, 0x83, 0x00, 0x00, 0xF9, 0xFF, 0x00, 0x00, 0x80, 0xE9, 0x00, 0x00,
      0x75, 0x30, 0x00, 0x00, 0xEA, 0x60, 0x00, 0x00, 0x3A, 0x98, 0x00, 0x00,
      0x17, 0x6F, 0x92, 0x5F, 0xC5, 0x46, 0x00, 0x00, 0x00, 0x39, 0x49, 0x44,
      0x41, 0x54, 0x78, 0xDA, 0x7C, 0x8E, 0xB1, 0x0D, 0x00, 0x20, 0x0C, 0xC3,
      0x1C, 0x9E, 0xE5, 0xA6, 0x5E, 0x1B, 0xB6, 0x4A, 0xA0, 0xD0, 0xAC, 0x8E,
      0x25, 0xC3, 0x7F, 0x65, 0x9B, 0x35, 0xC1, 0xC9, 0x2C, 0x80, 0x74, 0x6A,
      0x98, 0x0E, 0x17, 0x7C, 0x1B, 0xCA, 0x36, 0x92, 0x76, 0x6A, 0x48, 0x66,
      0x37, 0x68, 0xAA, 0x05, 0x38, 0x03, 0x00, 0x40, 0x17, 0x33, 0x3D, 0x58,
      0x57, 0x6B, 0xB3, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE,
      0x42, 0x60, 0x82
    };
    return base::StringPiece(reinterpret_cast<char*>(area_resizer_data),
        static_cast<base::StringPiece::size_type>(
            sizeof(area_resizer_data) / sizeof(unsigned char)));
  }
  case IDR_SEARCH_CANCEL:
  case IDR_SEARCH_CANCEL_PRESSED:
  case IDR_SEARCH_MAGNIFIER:
  case IDR_SEARCH_MAGNIFIER_RESULTS:
  case IDR_MEDIA_PAUSE_BUTTON:
  case IDR_MEDIA_PLAY_BUTTON:
  case IDR_MEDIA_PLAY_BUTTON_DISABLED:
  case IDR_MEDIA_SOUND_FULL_BUTTON:
  case IDR_MEDIA_SOUND_NONE_BUTTON:
  case IDR_MEDIA_SOUND_DISABLED:
  case IDR_MEDIA_SLIDER_THUMB:
  case IDR_MEDIA_VOLUME_SLIDER_THUMB:
    return NetResourceProvider(resource_id);
  default:
    break;
  }

  return base::StringPiece();
}

bool GetApplicationDirectory(FilePath* path) {
  return PathService::Get(base::DIR_EXE, path);
}

GURL GetInspectorURL() {
  return GURL("cef-resource://inspector/inspector.html");
}

std::string GetUIResourceProtocol() {
  return "cef-resource";
}

bool GetExeDirectory(FilePath* path) {
  return PathService::Get(base::DIR_EXE, path);
}

bool IsPluginRunningInRendererProcess() {
  return true;
}

bool GetPluginFinderURL(std::string* plugin_finder_url) {
  return false;
}

bool IsDefaultPluginEnabled() {
  return false;
}

bool IsProtocolSupportedForMedia(const GURL& url) {
  if (url.SchemeIsFile() || url.SchemeIs("http") || url.SchemeIs("https"))
    return true;
  return false;
}

std::wstring GetWebKitLocale() {
  return L"en-US";
}

void InitializeTextEncoding() {
  WebCore::UTF8Encoding();
}

v8::Handle<v8::Context> GetV8Context(WebKit::WebFrame* frame)
{
  WebFrameImpl* webFrameImpl = static_cast<WebFrameImpl*>(frame);
  WebCore::Frame* core_frame = webFrameImpl->frame();
  return WebCore::V8Proxy::context(core_frame);
}

void CloseIdleConnections() {
  // Used in benchmarking,  Ignored for CEF.
}

void SetCacheMode(bool enabled) {
  // Used in benchmarking,  Ignored for CEF.
}

void ClearCache()
{
  // Clear the cache by disabling it and then re-enabling it.
  WebCore::cache()->setDisabled(true);
  WebCore::cache()->setDisabled(false);
}

}  // namespace webkit_glue
