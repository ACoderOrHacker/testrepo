/**
 * @file exception_assertions.ixx
 * @brief Assertions for C++ exceptions only.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/configs.h>
#include <oe/api.h>

export module oe.contracts.exception_assertions;

import oe.meta;
import oe.functional.invoke;
import oe.conv.cast;
import oe.utilities.source_location;
import oe.contracts.assertions;

export namespace oe {
/**
 * @brief Checks whether the given function throws an exception, and panics if
 * it doesn't throw. Always asserts. Can be used in constant evaluated contexts
 * if condition is `true`. if the condition is `false`, the compiler will give a
 * compilation error. `expr` will be only called once.
 *
 * @see oe::enforce_not_thrown
 *
 * @tparam F The expression function type.
 * @param expr The expression packed with functions.
 * @param msg Messages to output when panics.
 * @param loc The source location of the caller.
 */
template <typename F>
constexpr OE_API void
enforce_thrown(F&& expr, const char* msg,
               const source_location& loc = source_location::current()) noexcept {
    static_assert(oe::is_invocable_r_v<void, F>,
                  "The parameter `F` of expression is not valid. `F` should "
                  "match the function definition `void()`");

    try {
        invoke(expr);
        oe::enforce(false, msg, loc);
    } catch (...) {
        /* does nothing. */
    }
}

/**
 * @brief Checks whether the given function throws an exception, and panics if
 * it doesn't throw. Only asserts if OE_IS_DEBUG == 1, or does nothing. Can be
 * used in constant evaluated contexts if condition is `true`. if the condition
 * is `false`, the compiler will give a compilation error. `expr` will be only
 * called once.
 *
 * @see oe::assert_not_thrown
 *
 * @tparam F The expression function type.
 * @param expr The expression packed with functions.
 * @param msg Messages to output when panics.
 * @param loc The source location of the caller.
 */
template <typename F>
constexpr OE_API void
assert_thrown(F&& expr, const char* msg,
              const source_location& loc = source_location::current()) noexcept {
    static_assert(details::is_valid_assertion_expr_v<F>,
                  "The parameter `F` of expression is not valid. `F` should "
                  "match the function definition `void()`");

#if OE_IS_DEBUG
    return enforce_thrown(expr, msg, loc);
#endif
}

/**
 * @brief Checks whether the given function throws an exception, and panics if
 * it throws. Always asserts. Can be used in constant evaluated contexts
 * if condition is `true`. if the condition is `false`, the compiler will give a
 * compilation error. `expr` will be only called once.
 *
 * @see oe::enforce_thrown
 *
 * @tparam F The expression function type.
 * @param expr The expression packed with functions.
 * @param msg Messages to output when panics.
 * @param loc The source location of the caller.
 */
template <typename F>
constexpr OE_API void
enforce_not_thrown(F&& expr, const char* msg,
                   const source_location& loc = source_location::current()) noexcept {
    static_assert(oe::is_invocable_r_v<void, F>,
                  "The parameter `F` of expression is not valid. `F` should "
                  "match the function definition `void()`");

    try {
        invoke(expr);
    } catch (...) {
        enforce(false, msg, loc);
    }
}

/**
 * @brief Checks whether the given function throws an exception, and panics if
 * it throws. Only asserts if OE_IS_DEBUG == 1, or does nothing. Can be
 * used in constant evaluated contexts if condition is `true`. if the condition
 * is `false`, the compiler will give a compilation error. `expr` will be only
 * called once.
 *
 * @see oe::assert_thrown
 *
 * @tparam F The expression function type.
 * @param expr The expression packed with functions.
 * @param msg Messages to output when panics.
 * @param loc The source location of the caller.
 */
template <typename F>
constexpr OE_API void
assert_not_thrown(F&& expr, const char* msg,
                  const source_location& loc = source_location::current()) noexcept {
    static_assert(oe::is_invocable_r_v<void, F>,
                  "The parameter `F` of expression is not valid. `F` should "
                  "match the function definition `void()`");

#if OE_IS_DEBUG
    enforce_not_thrown(expr, msg, loc);
#endif
}

/**
 * @brief Wraps a function that won't throw anytime but has no `noexcept`
 * attribute to a function with a `noexcept` attribute. If the function exactly
 * throws, the wrapper you called will panic.
 *
 * @tparam F The expression function type.
 * @param expr The functions to wrap
 * @param msg Messages to output when panics.
 * @param loc The source location of the caller.
 * @return The wrapped function that with a `noexcept` attribute.
 */
template <typename F>
OE_API auto
assume_wont_thrown(F&& expr,
                   const char* msg = "assume_wont_thrown: the wrapped function exactly throws",
                   const source_location& loc = source_location::current()) noexcept {
    return [&]<typename... Args>(Args... args) noexcept {
        try {
            return invoke(expr, oe::forward<Args>(args)...);
        } catch (...) {
            enforce(false, msg, loc);
        }
    };
}
} // namespace oe
