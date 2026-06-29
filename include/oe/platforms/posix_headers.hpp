/**
 * @file posix_headers.hpp
 * @brief Simple include headers for POSIX platforms, don't need to check for
 * OX_PLATFORM_POSIX_SYSTEM
 */
#pragma once

#include <oe/platforms/system.hpp>

#ifdef OX_PLATFORM_POSIX_SYSTEM
#include <unistd.h>
#endif
