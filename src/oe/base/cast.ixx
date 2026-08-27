/**
 * @file cast.ixx
 * @brief A basic unified conversion help set. No additional casts define.
 *
 * Provides `oe::base::cast`
 *
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/api.h>

export module oe.base.cast;

import oe.base.meta.traits;

export namespace oe::base {
/**
 * @brief Casts a value from one type to another.
 *
 * @tparam DestType The destination type.
 * @tparam SourceType The source type.
 * @param value The value to cast.
 * @return The cast value.
 */
template <typename DestType, typename SourceType>
constexpr OE_API DestType cast(SourceType value) noexcept {
    return static_cast<DestType>(value);
}

/**
 * @brief The same as std::forward, converts a value to a reference type.
 *
 * @tparam T The type to forward.
 * @param val The value to convert.
 * @return The converted value.
 */
template <typename T> constexpr OE_API T&& forward(remove_reference_t<T>& val) noexcept {
    return cast<T&&>(val);
}

/**
 * @brief The same as std::forward, converts a value to a reference type.
 *
 * @tparam T The type to forward.
 * @param val The value to convert.
 * @return The converted value.
 */
template <typename T> constexpr OE_API T&& forward(remove_reference_t<T>&& val) noexcept {
    static_assert(!is_lvalue_reference_v<T>, "Bad forward");

    return cast<T&&>(val);
}

/**
 * @brief Converts a value to xvalue.
 *
 * @tparam T The value type.
 * @param val The value.
 * @return The converted xvalue.
 */
template <typename T> constexpr OE_API remove_reference_t<T>&& to_xvalue(T&& val) noexcept {
    return static_cast<remove_reference_t<T>&&>(val);
}
} // namespace oe::base
