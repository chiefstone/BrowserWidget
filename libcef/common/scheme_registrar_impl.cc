// Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that can
// be found in the LICENSE file.

#include "libcef/common/scheme_registrar_impl.h"

#include <string>

#include "libcef/common/content_client.h"
#include "libcef/common/net/scheme_registration.h"

#include "base/bind.h"
#include "base/logging.h"
#include "base/strings/string_util.h"

namespace {

void AppendArray(const std::vector<std::string>& source,
                 std::vector<std::string>* target) {
  if (source.empty())
    return;
  target->insert(target->end(), source.begin(), source.end());
}

}

CefSchemeRegistrarImpl::CefSchemeRegistrarImpl()
    : supported_thread_id_(base::PlatformThread::CurrentId()) {
}

bool CefSchemeRegistrarImpl::AddCustomScheme(
    const CefString& scheme_name,
    bool is_standard,
    bool is_local,
    bool is_display_isolated,
    bool is_secure,
    bool is_cors_enabled) {
  if (!VerifyContext())
    return false;

  const std::string& scheme = base::ToLowerASCII(scheme_name.ToString());
  if (scheme::IsInternalHandledScheme(scheme) ||
      registered_schemes_.find(scheme) != registered_schemes_.end()) {
    return false;
  }

  registered_schemes_.insert(scheme);

  // The |is_display_isolated| value is excluded here because it's registered
  // with Blink only.
  if (is_standard)
    schemes_.standard_schemes.push_back(scheme);
  if (is_local)
    schemes_.local_schemes.push_back(scheme);
  if (is_secure)
    schemes_.secure_schemes.push_back(scheme);
  if (is_cors_enabled)
    schemes_.cors_enabled_schemes.push_back(scheme);

  CefContentClient::SchemeInfo scheme_info = {
      scheme, is_standard, is_local, is_display_isolated, is_secure,
      is_cors_enabled
  };
  CefContentClient::Get()->AddCustomScheme(scheme_info);

  return true;
}

void CefSchemeRegistrarImpl::GetSchemes(
    content::ContentClient::Schemes* schemes) {
  if (!VerifyContext())
    return;

  AppendArray(schemes_.standard_schemes, &schemes->standard_schemes);
  AppendArray(schemes_.local_schemes, &schemes->local_schemes);
  AppendArray(schemes_.secure_schemes, &schemes->secure_schemes);
  AppendArray(schemes_.cors_enabled_schemes, &schemes->cors_enabled_schemes);
}

bool CefSchemeRegistrarImpl::VerifyRefCount() {
  return HasOneRef();
}

void CefSchemeRegistrarImpl::Detach() {
  if (VerifyContext())
    supported_thread_id_ = base::kInvalidThreadId;
}

bool CefSchemeRegistrarImpl::VerifyContext() {
  if (base::PlatformThread::CurrentId() != supported_thread_id_) {
    // This object should only be accessed from the thread that created it.
    NOTREACHED();
    return false;
  }

  return true;
}
