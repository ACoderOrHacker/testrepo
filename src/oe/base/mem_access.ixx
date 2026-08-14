/**
 * @file mem_access.ixx
 * @brief The C memory APIs wrapper for memory.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <cstring>

export module oe.base.mem_access;

export namespace oe::base {
using std::memchr;
using std::memcmp;
using std::memcpy;
using std::memmove;
using std::memset;
} // namespace oe::base
