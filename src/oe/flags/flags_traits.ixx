/**
 * @file flags_traits.ixx
 * @brief The flags traits definition. Provides type traits for flags enums.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.flags.flags_traits;

import oe.meta.traits;
import oe.types.basic_types;

export namespace oe {
/**
 * @brief Enable a `flags`.
 *
 * You should enable the flags with this function.
 * By adding this in the enumeration:
 * @code{.cpp}
 * flags_enabled = oe::enable_flags()
 * @endcode
 *
 * @see oe::flags
 *
 * @warning This function is used to enable a `flags` but you should never use the returned value.
 * It's meaningless and just for check.
 *
 * @return The enabled integer.
 */
consteval auto enable_flags() noexcept { return 0x2A; }

/**
 * @brief Checks if the enumeration is a valid `flags`.
 *
 * @tparam Flags the flags to check.
 */
template <typename Flags>
concept is_flags = requires { Flags::flags_enabled == enable_flags(); };

} // namespace oe
