/**
 * @file unreachable.ixx
 * @brief Marks codes as `unreachable` code. Internal use.
 *
 * @warning Users should use `oe.utilities`.
 *
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/detections.h>

export module oe.base.unreachable;

export namespace oe::base {
/**
 * @brief Marks a code as `unreachable` for the compiler to optimize.
 */
[[noreturn]]
inline void unreachable() noexcept {
#if OE_COMPILER_SINGLE == OE_COMPILER_MSVC
    __assume(false);
#elif OE_COMPILER_SINGLE == OE_COMPILER_GCC || OE_COMPILER_SINGLE == OE_COMPILER_CLANG
    __builtin_unreachable();
#endif
}
} // namespace oe::base