/**
 * @file char_define.ixx
 * @brief The internal module for types.char_define. Easy definator for OE char
 * types.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.types.char_types:char_define;

import oe.meta;

namespace oe::details {
/**
 * @brief Detailed definition of a character type.
 * @tparam IntType The integer type used to store the character data.
 * @tparam StdCharType The standard character type, `void` if none.
 */
template <typename IntType, typename StdCharType = void> struct define_char {
  private:
    constexpr inline static bool has_std_char_type =
        oe::is_same_v<StdCharType, void>;

  public:
    /**
     * @brief Constructor from an integer type.
     * @param data The integer value to store.
     */
    explicit define_char(IntType data) noexcept : m_data(data) {}

    define_char(define_char&&) = default;
    define_char(const define_char&) = default;

    /**
     * @brief Constructor from a standard character type.
     * @param ch The character to store.
     */
    constexpr /* implicit */ define_char(StdCharType ch) noexcept
        requires has_std_char_type
        : m_data{static_cast<IntType>(ch)} {}

    /**
     * @brief Addition operator.
     * @param other The integer value to add.
     * @return A new `define_char` with the result.
     */
    constexpr define_char operator+(IntType other) const noexcept {
        return define_char(m_data + other);
    }
    /**
     * @brief Subtraction operator.
     * @param other The integer value to subtract.
     * @return A new `define_char` with the result.
     */
    constexpr define_char operator-(IntType other) const noexcept {
        return define_char(m_data - other);
    }

    /**
     * @brief Pre-increment operator.
     * @return A reference to the incremented `define_char`.
     */
    constexpr define_char& operator++() noexcept {
        ++m_data;
        return *this;
    }

    /**
     * @brief Post-increment operator.
     * @return A copy of the `define_char` before incrementing.
     */
    constexpr define_char operator++(int) noexcept {
        define_char temp(*this);
        ++m_data;
        return temp;
    }

    /**
     * @brief Pre-decrement operator.
     * @return A reference to the decremented `define_char`.
     */
    constexpr define_char& operator--() noexcept {
        --m_data;
        return *this;
    }

    /**
     * @brief Post-decrement operator.
     * @return A copy of the `define_char` before decrementing.
     */
    constexpr define_char operator--(int) noexcept {
        define_char temp(*this);
        --m_data;
        return temp;
    }

    /**
     * @brief Equality operator.
     * @return `true` if the `define_char` values are equal, `false` otherwise.
     */
    constexpr bool operator==(define_char other) const noexcept {
        return m_data == other.m_data;
    }

    /**
     * @brief Inequality operator.
     * @return `true` if the `define_char` values are not equal, `false`
     * otherwise.
     */
    constexpr bool operator!=(define_char other) const noexcept {
        return m_data != other.m_data;
    }

    /**
     * @brief Less-than operator.
     * @return `true` if the `define_char` value is less than the other, `false`
     * otherwise.
     */
    constexpr bool operator<(define_char other) const noexcept {
        return m_data < other.m_data;
    }

    /**
     * @brief Greater-than operator.
     * @return `true` if the `define_char` value is greater than the other,
     * `false` otherwise.
     */
    constexpr bool operator>(define_char other) const noexcept {
        return m_data > other.m_data;
    }

    /**
     * @brief Less-than-or-equal operator.
     * @return `true` if the `define_char` value is less than or equal to the
     * other, `false` otherwise.
     */
    constexpr bool operator<=(define_char other) const noexcept {
        return m_data <= other.m_data;
    }

    /**
     * @brief Greater-than-or-equal operator.
     * @return `true` if the `define_char` value is greater than or equal to the
     * other, `false` otherwise.
     */
    constexpr bool operator>=(define_char other) const noexcept {
        return m_data >= other.m_data;
    }

    /**
     * @brief Bitwise AND operator.
     * @return The result of the bitwise AND operation.
     */
    constexpr define_char operator&(define_char other) const noexcept {
        return define_char(m_data & other.m_data);
    }

    /**
     * @brief Bitwise OR operator.
     * @return The result of the bitwise OR operation.
     */
    constexpr define_char operator|(define_char other) const noexcept {
        return define_char(m_data | other.m_data);
    }

    /**
     * @brief Bitwise XOR operator.
     * @return The result of the bitwise XOR operation.
     */
    constexpr define_char operator^(define_char other) const noexcept {
        return define_char(m_data ^ other.m_data);
    }

    /**
     * @brief Bitwise NOT operator.
     * @return The result of the bitwise NOT operation.
     */
    constexpr define_char operator~() const noexcept {
        return define_char(~m_data);
    }

    /**
     * @brief Left shift operator.
     * @return The result of the left shift operation.
     */
    constexpr define_char operator<<(IntType other) const noexcept {
        return define_char(m_data << other);
    }

    /**
     * @brief Right shift operator.
     * @return The result of the right shift operation.
     */
    constexpr define_char operator>>(IntType other) const noexcept {
        return define_char(m_data >> other);
    }

    /**
     * @brief Bitwise AND assignment operator.
     * @return A reference to the `define_char` after the operation.
     */
    constexpr define_char operator&=(define_char other) noexcept {
        m_data &= other.m_data;
        return *this;
    }

    /**
     * @brief Bitwise OR assignment operator.
     * @return A reference to the `define_char` after the operation.
     */
    constexpr define_char operator|=(define_char other) noexcept {
        m_data |= other.m_data;
        return *this;
    }

    /**
     * @brief Bitwise XOR assignment operator.
     * @return A reference to the `define_char` after the operation.
     */
    constexpr define_char operator^=(define_char other) noexcept {
        m_data ^= other.m_data;
        return *this;
    }

    /**
     * @brief Left shift assignment operator.
     * @return A reference to the `define_char` after the operation.
     */
    constexpr define_char operator<<=(IntType other) noexcept {
        m_data <<= other;
        return *this;
    }

    /**
     * @brief Right shift assignment operator.
     * @return A reference to the `define_char` after the operation.
     */
    constexpr define_char operator>>=(IntType other) noexcept {
        m_data >>= other;
        return *this;
    }

    /**
     * @brief Assignment operator.
     * @return A reference to the `define_char` after the operation.
     */
    constexpr define_char& operator=(define_char other) noexcept {
        m_data = other.m_data;
        return *this;
    }

    /**
     * @brief Assignment operator.
     * @return A reference to the `define_char` after the operation.
     */
    constexpr define_char& operator=(IntType other) noexcept {
        m_data = other;
        return *this;
    }

    /**
     * @brief Conversion operator to the standard character type.
     * @return The character value as a `StdCharType`.
     */
    constexpr /* implicit */ operator StdCharType() const noexcept
        requires has_std_char_type
    {
        return static_cast<StdCharType>(m_data);
    }

  private:
    IntType m_data; //!< The data
};
} // namespace oe::details
