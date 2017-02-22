// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

// Defines all of the command line switches used by cefclient.

#ifndef CEF_TESTS_SHARED_SHARED_COMMON_SWITCHES_H_
#define CEF_TESTS_SHARED_SHARED_COMMON_SWITCHES_H_
#pragma once

namespace client {
namespace switches {

extern const char kMultiThreadedMessageLoop[];
extern const char kExternalMessagePump[];
extern const char kCachePath[];
extern const char kUrl[];
extern const char kOffScreenRenderingEnabled[];
extern const char kOffScreenFrameRate[];
extern const char kTransparentPaintingEnabled[];
extern const char kShowUpdateRect[];
extern const char kMouseCursorChangeDisabled[];
extern const char kRequestContextPerBrowser[];
extern const char kRequestContextSharedCache[];
extern const char kBackgroundColor[];
extern const char kEnableGPU[];
extern const char kFilterURL[];
extern const char kUseViews[];
extern const char kHideFrame[];
extern const char kHideControls[];
extern const char kHideTopMenu[];
extern const char kWidevineCdmPath[];
extern const char kSslClientCertificate[];

}  // namespace switches
}  // namespace client

#endif  // CEF_TESTS_SHARED_SHARED_COMMON_SWITCHES_H_
