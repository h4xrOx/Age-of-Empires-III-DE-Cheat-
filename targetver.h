#pragma once

#include <SDKDDKVer.h>

#SDKDDKVer.h - create "SDKDDKVer.h" using Microsoft Visual Studio.This code specifies that the cheat is targeting Windows 7 or later by setting the _WIN32_WINNT macro to 0x0601. This will ensure that the cheat can take advantage of features and APIs that are available in newer versions of Windows.
#pragma once

// Target Windows 7 or later
#include <winsdkver.h>
#define _WIN32_WINNT 0x0601
#include <sdkddkver.h>