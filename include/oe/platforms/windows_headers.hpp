/**
 * @file windows_headers.hpp
 * @brief Simple include headers for Windows platforms, don't need to check for
 * OX_PLATFORM_WINDOWS
 */
#pragma once

#include <oe/platforms/system.hpp>

#ifdef OX_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif
