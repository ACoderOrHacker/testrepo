/**
 * @file flags.ixx
 * @brief The bit flags definitions.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.flags.flags;

import oe.types.basic_types;
import oe.meta.traits;
import oe.conv.cast;
export import oe.flags.flags_traits;

export namespace oe {

/**
 * @brief Returns the nth flag (1 << n) for the given bit position n.
 *
 * @see oe::flags
 *
 * @param n The bit position.
 * @return The nth flag as an unsigned 64-bit integer.
 */
constexpr inline auto nth_flag(const auto n) { return (1 << n); }

/**
 * @brief The flags' definition. Provides a convenient way to use bit flags.
 *
 * You should enable the flags with `oe::enable_flags`.
 *
 * @code{.cpp}
 * import oe.flags;
 *
 * enum Flags {
 *      // Add this enumeration value to enable
 *      flags_enabled = oe::enable_flags(),
 *
 *      flag_a = oe::nth_flag(0),
 *      flag_b = oe::nth_flag(1)
 * };
 *
 * oe::flags<Flags> f; // This is OK.
 * @endcode
 *
 * Or use the specified template argument of `oe::flags`:
 *
 * @code{.cpp}
 * import oe.flags;
 *
 * enum Flags {
 *      // No `flags_enable`.
 *      // flags_enabled = oe::enable_flags(),
 *
 *      flag_a = oe::nth_flag(0),
 *      flag_b = oe::nth_flag(1)
 * };
 *
 * oe::flags<Flags, true> f; // This is also OK.
 * // Sets `true` to `IgnoreEnabledCheck`.
 * @endcode
 *
 * This is useful to use other flags that doesn't use `oe::flags` to compatible with other flags.
 * But it's dangerous if the enumeration can not be a `flags`(The binary bits of each flag overlap).
 *
 * @see oe::enable_flags
 * @see oe::nth_flag
 *
 * @tparam FlagsEnum The flags enum type.
 * @tparam IgnoreEnabledCheck True if the `oe::flags` should ignore the check of `oe::is_flags`,
 * default to false, and it will check this enumeration by `oe::is_flags`.
 */
template <typename FlagsEnum, bool IgnoreEnabledCheck = false> struct flags {
    static_assert(
        (!IgnoreEnabledCheck) && oe::is_flags_v<FlagsEnum>,
        "`oe::flags` requires a enumeration that with `flags_enabled` member in the enumeration.\n"
        "If you are sure that this enumeration is valid, you can add the code in the enumeration:\n"
        "   flags_enabled = oe::enable_flags()\n"
        "Or sets the `IgnoreEnabledCheck` to true to ignore the check if you are sure that this "
        "can be used in `oe::flags` and you cannot add the code to the enumeration.");

    using flags_type = FlagsEnum; //!< The flags enum type.
    using flags_underlying_type = oe::underlying_type_t<FlagsEnum>;

    constexpr inline flags() noexcept = default;

    /**
     * @brief Constructs a bit_flags object with the specified flags.
     * @tparam FlagsType The flags to set.
     */
    template <typename... FlagsType> constexpr explicit inline flags(FlagsType... flags) noexcept {
        ((*this |= flags), ...);
    }

    constexpr inline flags(const flags&) noexcept = default;
    constexpr inline flags(flags&&) noexcept = default;
    constexpr inline flags& operator=(const flags&) noexcept = default;
    constexpr inline flags& operator=(flags&&) noexcept = default;

    constexpr inline flags operator|(flags_type flags) const noexcept {
        return flags(m_flags | oe::cast<flags_underlying_type>(flags.m_flags));
    }

    /**
     * @brief Adds the specified flags to the current flags, returning the
     * result.
     * @param flags The flags to add.
     * @return The result of the addition.
     */
    constexpr inline flags operator|(const flags& flags) const noexcept {
        return flags(m_flags | oe::cast<flags_underlying_type>(flags.m_flags));
    }

    /**
     * @brief Adds the specified flags to the current flags, returning the
     * result.
     * @param flags The flags to add.
     * @return The result of the addition.
     */
    constexpr inline flags operator|(flags&& flags) const noexcept {
        return flags(m_flags | oe::cast<flags_underlying_type>(flags.m_flags));
    }

    /**
     * @brief Sets the specified flag in the bit_flags object.
     * @param flag The flag to set.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& operator|=(flags_type flag) noexcept {
        m_flags = *this | flag;
        return *this;
    }

    /**
     * @brief Adds the specified flags to the current flags, modifying
     * the current flags in place.
     * @param flags The flags to add.
     * @return A reference to the modified flags object.
     */
    constexpr inline flags& operator|=(const flags& flags) noexcept {
        *this = *this + flags;
        return *this;
    }

    /**
     * @brief Adds the specified flags to the current flags, modifying
     * the current flags in place.
     * @param flags The flags to add.
     * @return A reference to the modified flags object.
     */
    constexpr inline flags& operator|=(flags&& flags) noexcept {
        *this = *this + oe::to_xvalue(flags);
        return *this;
    }

    /**
     * @brief Remove the `flag` from the current flags, returning the result.
     * @param flag The flag to remove.
     * @return The result of the removal.
     */
    constexpr inline flags operator&(flags_type flag) const noexcept {
        return (m_flags & ~oe::cast<flags_underlying_type>(flag));
    }

    /**
     * @brief Subtracts the specified flags from the current flags, returning
     * the result.
     * @param flags The flags to subtract.
     * @return The result of the subtraction.
     */
    constexpr inline flags operator&(const flags& flags) const noexcept {
        return flags_type(m_flags & ~oe::cast<flags_underlying_type>(flags.m_flags));
    }

    /**
     * @brief Subtracts the specified flags from the current flags, returning
     * the result.
     * @param flags The flags to subtract.
     * @return The result of the subtraction.
     */
    constexpr inline flags operator&(flags&& flags) const noexcept {
        return flags_type(m_flags & ~oe::cast<flags_underlying_type>(flags.m_flags));
    }

    /**
     * @brief Clears the specified flag in the bit_flags object.
     * @param flag The flag to clear.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& operator&=(flags_type flag) noexcept {
        m_flags = *this & flag;
        return *this;
    }

    /**
     * @brief Subtracts the specified flags from the current flags, modifying
     * the current flags in place.
     * @param flags The flags to subtract.
     * @return A reference to the modified flags object.
     */
    constexpr inline flags& operator&=(const flags& flags) noexcept {
        *this = *this - flags;
        return *this;
    }

    /**
     * @brief Subtracts the specified flags from the current flags, modifying
     * the current flags in place.
     * @param flags The flags to subtract.
     * @return A reference to the modified flags object.
     */
    constexpr inline flags& operator&=(flags&& flags) noexcept {
        *this = *this - oe::to_xvalue(flags);
        return *this;
    }

    /**
     * @brief Returns the bitwise negation of the current flags.
     * @return The bitwise negation of the current flags.
     */
    constexpr inline flags operator!() const noexcept { return flags(~m_flags); }

    /**
     * @brief Compares two flags objects for equality.
     * @param flags The flags to compare with.
     * @return True if the flags are equal, false otherwise.
     */
    constexpr inline bool operator==(const flags& flags) const noexcept {
        return m_flags == flags.m_flags;
    }

    /**
     * @brief Compares two flags objects for inequality.
     * @param flags The flags to compare with.
     * @return True if the flags are not equal, false otherwise.
     */
    constexpr inline bool operator!=(const flags& flags) const noexcept {
        return !(*this == flags);
    }

    /**
     * @brief Checks if the specified flag is set in the bit_flags object.
     * @param flag The flag to check.
     * @return True if the flag is set, false otherwise.
     */
    constexpr inline bool has(flags_type flag) const noexcept { return *this & flag; }

    /**
     * @brief Checks if the specified flags are set in the bit_flags object.
     * @param flags The flags to check.
     * @return True if the flags are set, false otherwise.
     */
    constexpr inline bool has(const flags& flags) const noexcept { return *this & flags; }

    /**
     * @brief Checks if the specified flags are set in the bit_flags object.
     * @param flags The flags to check.
     * @return True if the flags are set, false otherwise.
     */
    constexpr inline bool has(flags&& flags) const noexcept { return *this & oe::to_xvalue(flags); }

    /**
     * @brief Adds the specified flag in the bit_flags object.
     * @param flag The flag to add.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& add(flags_type flag) noexcept {
        *this |= flag;
        return *this;
    }

    /**
     * @brief Adds the specified flags in the bit_flags object.
     * @param flags The flags to add.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& add(const flags& flags) noexcept {
        *this += flags;
        return *this;
    }

    /**
     * @brief Adds the specified flags in the bit_flags object.
     * @param flags The flags to add.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& add(flags&& flags) noexcept {
        *this += oe::to_xvalue(flags);
        return *this;
    }

    /**
     * @brief Removes the specified flags from the bit_flags object.
     * @param flag The flags to remove.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& remove(flags_type flag) noexcept {
        *this &= flag;
        return *this;
    }

    /**
     * @brief Removes the specified flags from the bit_flags object.
     * @param flags The flags to remove.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& remove(flags&& flags) noexcept {
        *this &= oe::to_xvalue(flags);
        return *this;
    }

    /**
     * @brief Subtracts the specified flag from the bit_flags object.
     * @param flags The flag to subtract.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& remove(const flags& flags) noexcept {
        *this &= flags;
        return *this;
    }

    /**
     * @brief Sets the specified flag in the bit_flags object.
     * @warning This method clears all flags first, then sets the specified
     * flag.
     * @param flag The flag to set.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& set(flags_type flag) noexcept { return clear().add(flag); }

    /**
     * @brief Sets the specified flags in the bit_flags object.
     * @param flags The flags to set.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& set(const flags& flags) noexcept {
        *this = flags;
        return *this;
    }

    /**
     * @brief Sets the specified flags in the bit_flags object.
     * @param flags The flags to set.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& set(flags&& flags) noexcept {
        *this = oe::to_xvalue(flags);
        return *this;
    }

    /**
     * @brief Clears all flags in the bit_flags object.
     * @return A reference to the modified bit_flags object.
     */
    constexpr inline flags& clear() noexcept {
        m_flags = 0;
        return *this;
    }

    /**
     * @brief Returns the raw flags storage value.
     * @return The raw flags storage value.
     */
    constexpr inline flags_type raw() const noexcept { return m_flags; }

  private:
    flags_underlying_type m_flags{0}; //!< The data storage for the flags.
};
} // namespace oe
