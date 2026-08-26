/**
 * @file char_types.ixx
 * @brief Char types for UTF-8, UTF-16, UTF-32 for OE types library.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.types.char_types;

import oe.types.basic_types;
import :char_define;

export namespace oe {
#ifdef __cpp_char8_t
/**
 * @brief The UTF-8 Code Unit type.
 * @details Can be converted from or to char8_t in C++20 or later.
 * Supports bit operations, comparison, and arithmetic(only `plus` and `minus`).
 */
using c8 = oe::details::define_char<oe::u8, char8_t>;
#else
/**
 * @brief The UTF-8 Code Unit type.
 * @details Can be converted from or to char8_t in C++20 or later.
 * Supports bit operations, comparison, and arithmetic(only `plus` and `minus`).
 */
using c8 = oe::details::define_char<oe::u8, void>;
#endif

/**
 * @brief The UTF-16 Code Unit type.
 * @details Can be converted from or to char16_t in C++11 or later.
 * Supports bit operations, comparison, and arithmetic(only `plus` and `minus`).
 */
using c16 = oe::details::define_char<oe::u16, char16_t>;

/**
 * @brief The UTF-32 Code Unit type.
 * @details Can be converted from or to char32_t in C++11 or later.
 * Supports bit operations, comparison, and arithmetic(only `plus` and `minus`).
 */
using c32 = oe::details::define_char<oe::u32, char32_t>;
} // namespace oe
