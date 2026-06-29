#pragma once

#include <oe/termcolor/termcolor.hpp>
#include <ostream>

std::ostream& operator<<(std::ostream& os, ox::details::rgb_color c) {
    ox::details::set_color(os, c);
    return os;
}

std::ostream& operator<<(std::ostream& os, ox::details::legacy_color c) {
    ox::details::set_color(os, c);
    return os;
}

std::ostream& operator<<(std::ostream& os, ox::on_rgb c) {
    ox::details::set_color(os, c);
    return os;
}
