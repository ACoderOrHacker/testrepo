/**
 * @file assertions.ixx
 * @brief The part of OE Contracts, supports assertions functions like enforce,
 * assert.
 * @warning Before using this module, disable the assert macro in
 * the std cassert header (using `#undef assert`), the `assert` macro might
 * conflict with the library's `oe::assert` function and cause confusion.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
module;

#include <cstdio>
#include <oe/configs.h>
#include <oe/api.h>

export module oe.contracts.assertions;

import oe.utilities.source_location;
import oe.utilities.terminating;

export namespace oe {
/**
 * @brief Checks whether the given condition is true, and panics if it is not.
 * Always asserts. Can be used in constant evaluated contexts if condition is
 * `true`. if the condition is `false`, the compiler will give a compilation
 * error.
 *
 * @see oe::assert
 * @param condition The condition to check.
 * @param msg The extra message to print if the condition is false.
 * @param loc The source location information.
 */
constexpr OE_API void
enforce(const bool condition, const char* msg,
        const oe::source_location& loc = oe::source_location::current()) noexcept {
    if (!condition) {
        std::printf("Assertion Failed:\n");
        oe::panic(msg, loc);
    }
}

/**
 * @brief Checks whether the given condition is true, and panics if it is not.
 * Only asserts if OE_IS_DEBUG == 1, or does nothing. Can be used in constant
 * evaluated contexts if condition is `true`. if the condition is `false`, the
 * compiler will give a compilation error.
 *
 * @see oe::enforce
 * @param condition The condition to check.
 * @param msg The extra message to print if the condition is false.
 * @param loc The source location information.
 */
constexpr OE_API void
assert(const bool condition, const char* msg,
       const oe::source_location& loc = oe::source_location::current()) noexcept {
#ifdef OE_IS_DEBUG
    oe::enforce(condition, msg, loc);
#endif
}
} // namespace oe
