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
#include <utility> // for std::move

export module oe.types.basic_types;

import oe.meta;

export namespace oe {
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

using usize = size_t;      //!< size type.
using iptr = intptr_t;     //!< integer pointer type.
using uptr = uintptr_t;    //!< unsigned integer pointer type.
using ptrdiff = ptrdiff_t; //!< pointer difference type.

using f32 =
    float; //!< Single-precision floating-point number, maybe not 32-bit.
using f64 =
    double; //!< Double-precision floating-point number, maybe not 64-bit.
using flong = long double; //!< Long double floating-point number.

using max_align = std::max_align_t; //!< Maximum alignment type.

/**
 * @brief Represents a byte (8-bit unsigned integer) with bitwise operations.
 */
struct byte {
  public:
    /**
     * @brief Constructs a byte with the given value.
     * @param value The value to initialize the byte with.
     */
    explicit constexpr byte(const u8 value) : value(value) {}

    /**
     * @brief Converts the byte to an unsigned 8-bit integer.
     * @return The value of the byte as an unsigned 8-bit integer.
     */
    explicit constexpr operator u8() const { return value; }

    /**
     * @brief Left-shifts the byte by the given amount.
     *
     * @tparam IntType the integer type of the shift.
     * @param shift The number of bits to shift.
     * @return A reference to the modified byte.
     */
    template <typename IntType>
    constexpr byte& operator<<=(IntType shift) noexcept
        requires oe::integral<IntType>
    {
        value = value << shift;
        return *this;
    }

    /**
     * @brief Right-shifts the byte by the given amount.
     *
     * @tparam IntType the integer type of the shift.
     * @param shift The number of bits to shift.
     * @return A reference to the modified byte.
     */
    template <typename IntType>
    constexpr byte& operator>>=(IntType shift) noexcept
        requires oe::integral<IntType>
    {
        value = value >> shift;
        return *this;
    }

    /**
     * @brief Bitwise AND assignment operator.
     *
     * @tparam IntType the integer type of the shift.
     * @param shift The value to AND with.
     * @return A reference to the modified byte.
     */
    template <typename IntType>
    constexpr byte& operator&=(IntType shift) noexcept
        requires oe::integral<IntType>
    {
        value = value & shift;
        return *this;
    }

    /**
     * @brief Bitwise OR assignment operator.
     *
     * @tparam IntType the integer type of the shift.
     * @param shift The value to OR with.
     * @return A reference to the modified byte.
     */
    template <typename IntType>
    constexpr byte& operator|=(IntType shift) noexcept
        requires oe::integral<IntType>
    {
        value = value | shift;
        return *this;
    }

    /**
     * @brief Bitwise XOR assignment operator.
     *
     * @tparam IntType the integer type of the shift.
     * @param shift The value to XOR with.
     * @return A reference to the modified byte.
     */
    template <typename IntType>
    constexpr byte& operator^=(IntType shift) noexcept
        requires oe::integral<IntType>
    {
        value = value ^ shift;
        return *this;
    }

    /**
     * @brief Left-shifts the byte by the given amount.
     *
     * @tparam IntType the integer type of the shift.
     * @param shift The number of bits to shift.
     * @return The shifted byte.
     */
    template <typename IntType>
    constexpr byte operator<<(IntType shift) const noexcept
        requires oe::integral<IntType>
    {
        return byte(value << shift);
    }

    /**
     * @brief Right-shifts the byte by the given amount.
     *
     * @tparam Integer the integer type of the shift.
     * @param shift The number of bits to shift.
     * @return The shifted byte.
     */
    template <typename Integer>
    constexpr byte operator>>(Integer shift) const noexcept
        requires oe::integral<Integer>
    {
        return byte(value >> shift);
    }

    /**
     * @brief Bitwise AND operator.
     *
     * @param other The byte to AND with.
     * @return The result of the bitwise AND operation.
     */
    constexpr byte operator&(const byte other) const noexcept {
        return byte(value & other.value);
    }

    /**
     * @brief Bitwise OR operator.
     * @param other The byte to OR with.
     * @return The result of the bitwise OR operation.
     */
    constexpr byte operator|(const byte other) const noexcept {
        return byte(value | other.value);
    }

    /**
     * @brief Bitwise XOR operator.
     * @param other The byte to XOR with.
     * @return The result of the bitwise XOR operation.
     */
    constexpr byte operator^(const byte other) const noexcept {
        return byte(value ^ other.value);
    }

    /**
     * @brief Bitwise NOT operator.
     * @return The result of the bitwise NOT operation.
     */
    constexpr byte operator~() const noexcept { return byte(~value); }

    /**
     * @brief Conversion operator to integral type.
     * @tparam IntType The integral type to convert to.
     * @return The value of the byte as an integral type.
     */
    template <typename IntType>
    constexpr /* implicit */ operator IntType() const noexcept
        requires oe::integral<IntType>
    {
        return static_cast<IntType>(value);
    }

  private:
    u8 value; //!< The value of the byte.
};

using pvoid = void*; //!< void* alias.

using nullptr_t = std::nullptr_t; //!< The type of nullptr.

template <typename T>
using limits = std::numeric_limits<T>;              //!< Limits of type T.
using float_round_style = std::float_round_style;   //!< Float round style.
using float_denorm_style = std::float_denorm_style; //!< Float denorm style.

using std::move;
} // namespace oe
