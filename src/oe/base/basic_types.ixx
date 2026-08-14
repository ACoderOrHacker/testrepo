/**
 * @file basic_types.ixx
 * @brief The basic types used in the OE library.
 * @details This module contains the basic types used in the OE library.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <cstddef> // for size_t, ...
#include <cstdint> // for std fixed-size integer types
#include <limits>  // for std::numeric_limits

export module oe.base.basic_types;

import oe.base.meta.concepts;

export namespace oe::base {
using i8 = std::int8_t;    //!< 8-bit signed integer.
using i16 = std::int16_t;  //!< 16-bit signed integer.
using i32 = std::int32_t;  //!< 32-bit signed integer.
using i64 = std::int64_t;  //!< 64-bit signed integer.
using u8 = std::uint8_t;   //!< 8-bit unsigned integer.
using u16 = std::uint16_t; //!< 16-bit unsigned integer.
using u32 = std::uint32_t; //!< 32-bit unsigned integer.
using u64 = std::uint64_t; //!< 64-bit unsigned integer.

using int_least8_t = std::int_least8_t;     //!< least 8-bit integer.
using int_least16_t = std::int_least16_t;   //!< least 16-bit integer.
using int_least32_t = std::int_least32_t;   //!< least 32-bit integer.
using int_least64_t = std::int_least64_t;   //!< least 64-bit integer.
using uint_least8_t = std::uint_least8_t;   //!< least 8-bit unsigned integer.
using uint_least16_t = std::uint_least16_t; //!< least 16-bit unsigned integer.
using uint_least32_t = std::uint_least32_t; //!< least 32-bit unsigned integer.
using uint_least64_t = std::uint_least64_t; //!< least 64-bit unsigned integer.

using int_fast8_t = std::int_fast8_t;     //!< fast 8-bit integer.
using int_fast16_t = std::int_fast16_t;   //!< fast 16-bit integer.
using int_fast32_t = std::int_fast32_t;   //!< fast 32-bit integer.
using int_fast64_t = std::int_fast64_t;   //!< fast 64-bit integer.
using uint_fast8_t = std::uint_fast8_t;   //!< fast 8-bit unsigned integer.
using uint_fast16_t = std::uint_fast16_t; //!< fast 16-bit unsigned integer.
using uint_fast32_t = std::uint_fast32_t; //!< fast 32-bit unsigned integer.
using uint_fast64_t = std::uint_fast64_t; //!< fast 64-bit unsigned integer.

using iptr = std::intptr_t;     //!< integer pointer type.
using uptr = std::uintptr_t;    //!< unsigned integer pointer type.
using ptrdiff = std::ptrdiff_t; //!< pointer difference type.
using usize = std::size_t;      //!< size type.
using ssize = ptrdiff;          //!< signed size type.
//     ^
//     |
// https://cplusplus.github.io/LWG/issue2251 They say ptrdiff_t is for ssize_t, all right.

using f32 = float;         //!< Single-precision floating-point number, maybe not 32-bit.
using f64 = double;        //!< Double-precision floating-point number, maybe not 64-bit.
using flong = long double; //!< Long double floating-point number.

using byte = std::byte; //!< Byte definition.

using max_align = std::max_align_t; //!< Maximum alignment type.

using pvoid = void*; //!< void* alias.

using nullptr_t = std::nullptr_t; //!< The type of nullptr.

template <typename T> using limits = std::numeric_limits<T>; //!< Limits of type T.
using float_round_style = std::float_round_style;            //!< Float round style.
using float_denorm_style = std::float_denorm_style;          //!< Float denorm style.

using c8 = char8_t;   //!< UTF-8 Character.
using c16 = char16_t; //!< UTF-16 Character.
using c32 = char32_t; //!< UTF-32 Character.
} // namespace oe::base
