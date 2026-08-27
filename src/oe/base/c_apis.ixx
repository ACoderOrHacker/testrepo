/**
 * @file c_apis.ixx
 * @brief Compatibility exports for the C memory APIs.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <cstring>

export module oe.memory.c_apis;

export namespace oe {
using std::memchr;
using std::memcmp;
using std::memcpy;
using std::memmove;
using std::memset;
} // namespace oe
