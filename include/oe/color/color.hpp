/**
 * @file color.hpp
 * @brief Color utilities.
 */
#pragma once

#include <oe/types.hpp>

namespace oe {
namespace impl {
namespace color {

/**
 * @brief Represents a grayscale color.
 */
struct gray_color {
    /**
     * @brief Constructs a grayscale color with the specified value.
     * @param value The grayscale value.
     */
    constexpr explicit gray_color(oe::u8 value) : gray_scale(value) {}

    oe::u8 gray_scale; //!< The grayscale value.
};

/**
 * @brief Represents a CMY color.
 */
struct cmy {
    /**
     * @brief Constructs a CMY color with the specified cyan, magenta, and
     * yellow values.
     * @param c The cyan component.
     * @param m The magenta component.
     * @param y The yellow component.
     */
    constexpr cmy(float c, float m, float y) : c(c), m(m), y(y) {}

    float c; //!< The cyan component. In range [0.0, 1.0]
    float m; //!< The magenta component. In range [0.0, 1.0]
    float y; //!< The yellow component. In range [0.0, 1.0]
};

/**
 * @brief Represents a CMYK color.
 */
struct cmyk {
    /**
     * @brief Constructs a CMYK color with the specified cyan, magenta, yellow,
     * and key values.
     * @param c The cyan component.
     * @param m The magenta component.
     * @param y The yellow component.
     * @param k The key component.
     */
    constexpr cmyk(float c, float m, float y, float k)
        : c(c), m(m), y(y), k(k) {}

    float c; //!< The cyan component. In range [0.0, 1.0]
    float m; //!< The magenta component. In range [0.0, 1.0]
    float y; //!< The yellow component. In range [0.0, 1.0]
    float k; //!< The key component. In range [0.0, 1.0]
};

template <typename ColorType> ColorType from_color_string(const char*)

} // namespace color
} // namespace impl
} // namespace oe

#ifndef OE_COLOR_USE_MODULES
namespace oe {
using namespace impl::color;
}
#endif
