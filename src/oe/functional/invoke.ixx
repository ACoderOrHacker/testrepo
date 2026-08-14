/**
 * @file invoke.ixx
 * @brief Provides the `invoke` operations for `functional` module.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/detections.h>
#include <functional> // for std::invoke, std::invoke_r

export module oe.functional.invoke;

export namespace oe {
using std::invoke;

#if OE_CPP_STANDARD >= OE_CPP23_ID
using std::invoke_r;
#endif
} // namespace oe