/**
 * @file char_traits.ixx
 * @brief char_traits definition for types library.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/detections.h>
#include <cwchar> // for WEOF
#include <cstdio> // for EOF

export module oe.types.char_traits;

import oe.meta;
import oe.types.basic_types;
import oe.types.char_types;
import :basic_char_traits;
import :char_traits_define;

export namespace oe {
/**
 * @brief The char_traits struct provides character traits for a given type.
 * Compatible with std::char_traits.
 * To extend these traits, you can specialize it for your own char type.
 * @details You should specialize this struct for your own char type to provide
 * custom character traits. Copies the following code snippet:
 * @code {.cpp}
 * using char_type = <tp>; // The character type for these traits.
 * using int_type = <tp>; // The integer type for these traits.
 * using off_type = <tp>; // The stream offset type for these traits.
 * using pos_type = <tp>; // The stream position type for these traits.
 * using state_type = <tp>; // The state type for these traits.
 *
 * /// Checks if two characters are equal.
 * static bool eq(char_type c, char_type d) noexcept {
 *      return eq_int_type(to_int_type(c), to_int_type(d));
 * }
 *
 * /// Checks if two integer types are equal.
 * static bool eq_int_type(int_type e, int_type f) noexcept {
 *      // Your code
 * }
 *
 * /// Checks if one character is less than another.
 * static bool lt(char_type c, char_type d) noexcept {
 *      // Your code
 * }
 *
 * /// Compares two characters.
 * /// For each integer in range `[p, p + n)`, eq(p[i], q[i]) == true, then
 * returns 0.
 * /// Otherwise, returns the difference between the first pair of non-equal
 * characters. static int compare(const char_type* p, const char_type* q,
 * oe::usize n) noexcept {
 *      // Your code
 * }
 *
 * /// Finds the first occurrence of `c` in range `[p, p + n)`, and returns a
 * pointer to it.
 * /// Returns `nullptr` if `c` is not found.
 * static const char_type* find(const char_type* p, oe::usize n, char_type c)
 * noexcept {
 *      // Your code
 * }
 *
 * /// Copies `n` characters from `p` to `s`, and returns `s`.
 * /// The behavior is undefined if `p` and `s` overlap.
 * static char_type* copy(char_type* s, const char_type* p, oe::usize n)
 * noexcept {
 *      // Your code
 * }
 *
 * /// Moves `n` characters from `p` to `s`, and returns `s`.
 * static char_type* move(char_type* s, const char_type* p, oe::usize n)
 * noexcept {
 *      // Your code
 * }
 *
 * /// Assigns `d` to `r`.
 * static void assign(char_type& r, char_type d) noexcept {
 *      // Your code
 * }
 *
 * /// Fills `n` characters in `s` with `c`, and returns `s`.
 * static char_type* assign(char_type* s, oe::usize n, char_type c) noexcept {
 *      // Your code
 * }
 *
 * /// Returns the length of the string `p`.
 * /// The result is the minimum `i` that satisfies `eq(p[i], char_type()) ==
 * true`. static oe::usize length(const char_type* p) noexcept {
 *      // Your code
 * }
 *
 * /// Converts a character to an integer type.
 * /// Meet the conditions: to_char_type(to_int_type(c)) == c
 * static int_type to_int_type(char_type c) noexcept {
 *      // Your code
 * }
 *
 * /// Converts an integer type to a character type.
 * /// Meet the conditions: to_int_type(to_char_type(e)) == e
 * static char_type to_char_type(int_type e) noexcept {
 *      // Your code
 * }
 *
 * /// Returns the end-of-file character.
 * /// The result is the integer value `i` that to any character `c`,
 * /// to_int_type(c) != i.
 * static int_type eof() noexcept {
 *      // Your code
 * }
 *
 * /// Returns the integer value `e` that is not equal to the end-of-file
 * character.
 * /// If `e` is equal to the end-of-file character, returns another one that is
 * not equal to the end-of-file character.
 * /// Otherwise, returns `e`.
 * static int_type not_eof(int_type e) noexcept {
 *      // Your code
 * }
 *
 * @endcode
 */
template <typename _> struct char_traits {
    static_assert(false, "Unknown char_traits");
};

// Standard char traits

template <>
struct char_traits<char> : oe::details::define_char_traits<char, int, EOF> {};
template <>
struct char_traits<wchar_t>
    : oe::details::define_char_traits<wchar_t, wint_t, WEOF> {};
template <>
struct char_traits<char16_t>
    : oe::details::define_char_traits<char16_t, int, EOF> {};
template <>
struct char_traits<char32_t>
    : oe::details::define_char_traits<char32_t, int, EOF> {};

#if OE_CPP_STANDARD >= OE_CPP20_ID
// C++20 only
template <>
struct char_traits<char8_t>
    : oe::details::define_char_traits<char8_t, int, EOF> {};
#endif

// OE char traits
template <>
struct char_traits<oe::c8>
    : details::define_char_traits<oe::c8, oe::u8, limits<oe::u8>::max()> {};
template <>
struct char_traits<oe::c16>
    : details::define_char_traits<oe::c16, oe::u16, limits<oe::u16>::max()> {};
template <>
struct char_traits<oe::c32>
    : details::define_char_traits<oe::c32, oe::u32, limits<oe::u32>::max()> {};

/**
 * @brief Checks if the given type satisfies the `char_traits` concept.
 *
 * @tparam Traits The type to check.
 */
template <typename Traits>
using is_char_traits = oe::conjunction<
    oe::details::has_eq<Traits>, oe::details::has_eq_int_type<Traits>,
    oe::details::has_lt<Traits>, oe::details::has_compare<Traits>,
    oe::details::has_copy<Traits>, oe::details::has_move<Traits>,
    oe::details::has_find<Traits>, oe::details::has_assign<Traits>,
    oe::details::has_assign_n<Traits>, oe::details::has_length<Traits>,
    oe::details::has_to_char_type<Traits>, oe::details::has_to_int_type<Traits>,
    oe::details::has_eof<Traits>, oe::details::has_not_eof<Traits>>;

/**
 * @brief Checks if the given type satisfies the `char_traits` concept.
 *
 * @tparam Traits The type to check.
 * @return `true` if the type satisfies the `char_traits` concept, `false`
 * otherwise.
 */
template <typename Traits>
constexpr inline bool is_char_traits_v = is_char_traits<Traits>::value;

} // namespace oe