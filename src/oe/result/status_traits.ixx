/**
 * @file status_traits.ixx
 * @brief Defines the status check traits for the result library.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.result.status_traits;

import oe.meta;

export namespace oe {
/**
 * @brief Checks if the given type has an `ok` member.
 */
template <typename T>
concept has_ok = requires { T::ok; };

/**
 * @brief Tag struct used to identify enum status type.
 */
struct status_enum_tag {};

/**
 * @brief Checks if the given type has a status enum tag.
 * @tparam T The type to check.
 */
template <class T> using has_status_enum_tag = oe::is_base_of<oe::status_enum_tag, T>;

/**
 * @brief Checks if the given type has a status enum tag.
 * @tparam T The type to check.
 * @return `true` if the type has a status enum tag, `false` otherwise.
 */
template <class T> constexpr inline bool has_status_enum_tag_v = has_status_enum_tag<T>::value;

/**
 * @brief Tag struct used to identify object(struct/class) status type.
 */
struct status_object_tag {};

/**
 * @brief Checks if the given type has a status object tag.
 * @tparam T The type to check.
 */
template <class T> using has_status_object_tag = oe::is_base_of<oe::status_object_tag, T>;

/**
 * @brief Checks if the given type has a status enum tag.
 * @tparam T The type to check.
 * @return `true` if the type has a status enum tag, `false` otherwise.
 */
template <class T> constexpr inline bool has_status_object_tag_v = has_status_object_tag<T>::value;
} // namespace oe