/**
 * @file requires.hpp
 * @brief The `requires` macro definition for below C++20.
 * @deprecated OE uses C++20, doesn't need this file.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
#ifndef OE_META_REQUIRES_HPP
#define OE_META_REQUIRES_HPP

/**
 * @def OE_REQUIRES
 * @brief Enables a function template only if the condition is true.
 * @details This macro uses `oe::enable_if_t` to enable a function template only
 * if the condition is true. Just a simpler way to SFINAE.
 * Usage:
 * @code{.cpp}
 * template <class T, OE_REQUIRES(is_same_v<T, int>)>
 * void foo(T t) {}
 * @endcode
 * @deprecated OE uses C++20, doesn't need this macro.
 * @param condition The condition to check.
 */
#define OE_REQUIRES(condition) typename = oe::enable_if_t<(condition)>

#endif // !OE_META_REQUIRES_HPP
