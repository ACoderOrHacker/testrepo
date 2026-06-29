#pragma once

#include <oe/types.hpp>

namespace oe {
namespace impl {
namespace color {

/**
 * @brief Represents an RGB color.
 */
struct rgb_color {
    /**
     * @brief Constructs an RGB color with the specified red, green, and
     * blue values.
     * @param r The red component.
     * @param g The green component.
     * @param b The blue component.
     */
    constexpr rgb_color(oe::u8 r, oe::u8 g, oe::u8 b) : r(r), g(g), b(b) {}

    oe::u8 r; //!< The red component.
    oe::u8 g; //!< The green component.
    oe::u8 b; //!< The blue component.
};

// 16-Colors Definition

constexpr rgb_color black{0, 0, 0};
constexpr rgb_color white{255, 255, 255};
constexpr rgb_color green{0, 255, 0};
constexpr rgb_color blue{0, 0, 255};
constexpr rgb_color red{255, 0, 0};
constexpr rgb_color yellow{255, 255, 0};
constexpr rgb_color cyan{0, 255, 255};
constexpr rgb_color magenta{255, 0, 255};
constexpr rgb_color grey{128, 128, 128};
constexpr rgb_color dark_red{128, 0, 0};
constexpr rgb_color dark_blue{0, 0, 128};
constexpr rgb_color dark_green{0, 128, 0};
constexpr rgb_color purple{128, 0, 128};
constexpr rgb_color orange{255, 165, 0};
constexpr rgb_color brown{165, 42, 42};
constexpr rgb_color dark_grey{64, 64, 64};

template

} // namespace color
} // namespace impl
} // namespace oe
