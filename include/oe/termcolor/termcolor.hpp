#pragma once

#include <oe/platforms/posix_headers.hpp>
#include <oe/platforms/windows_headers.hpp>
#include <oe/types.hpp>

namespace ox {
namespace details {
struct rgb_color {
    oe::i8 red;
    oe::i8 green;
    oe::i8 blue;
};

struct legacy_color {
    oe::i8 code;
};
} // namespace details

template <std::uint8_t r, std::uint8_t g, std::uint8_t b> struct rgb_type {
  public:
    inline rgb_type() : color{r, g, b} {}

    inline operator details::rgb_color() { return color; }

    details::rgb_color color;
};

struct rgb {
    inline rgb(std::uint8_t r, std::uint8_t g, std::uint8_t b)
        : color{r, g, b} {}

    inline operator details::rgb_color() const { return color; }

    details::rgb_color color;
};

template <std::uint8_t code> struct legacy16_type {
    inline legacy16_type() : color{code} {}

    inline operator details::legacy_color() { return color; }

    details::legacy_color color;
};

struct legacy16 {
    inline legacy16(std::uint8_t code) : color{code} {}

    inline operator details::legacy_color() { return color; }

    details::legacy_color color;
};

struct on_rgb {
    inline on_rgb(std::uint8_t r, std::uint8_t g, std::uint8_t b)
        : color{r, g, b} {}

    inline on_rgb(details::rgb_color rgb_color) : color(rgb_color) {}

    details::rgb_color color;
};

template <std::uint8_t r, std::uint8_t g, std::uint8_t b> struct on_rgb_type {
    inline on_rgb_type() {}

    inline operator on_rgb() { return on_rgb(color); }

    rgb_type<r, g, b> color;
};

namespace details {
inline FILE* get_standard_stream(const std::ostream& stream) {
    if (&stream == &std::cout)
        return stdout;
    else if (&stream == &std::cerr || &stream == &std::clog)
        return stderr;

    return nullptr;
}
inline FILE* get_standard_stream(const std::wostream& stream) {
    if (&stream == &std::wcout)
        return stdout;
    else if (&stream == &std::wcerr || &stream == &std::wclog)
        return stderr;

    return nullptr;
}

#ifdef _WIN32
inline DWORD get_standard_handle(const std::ostream& stream) {
    if (&stream == &std::cout)
        return STD_OUTPUT_HANDLE;
    else if (&stream == &std::cerr || &stream == &std::clog)
        return STD_ERROR_HANDLE;

    return 0;
}
inline DWORD get_standard_handle(const std::wostream& stream) {
    if (&stream == &std::wcout)
        return STD_OUTPUT_HANDLE;
    else if (&stream == &std::wcerr || &stream == &std::wclog)
        return STD_ERROR_HANDLE;

    return 0;
}
#endif

template <typename Stream> inline bool is_atty(Stream& stream) {
    FILE* std_stream = get_standard_stream(stream);

    if (!std_stream)
        return false;

#ifdef OX_POSIX
    return ::isatty(fileno(std_stream));
#elif defined(_WIN32)
    return ::_isatty(_fileno(std_stream));
#else
#error "Unsupported platform"
#endif
}

#ifdef _WIN32
//! Convert ansi code to windows color constants
//! It is a internal function
//! I know it's ugly. But it's windows :)
inline WORD AnsiToWindowsColor(int code, WORD current) {
    static const int ansi_map[8] = {
        0, // black
        4, // red
        2, // green
        6, // yellow
        1, // blue
        5, // magenta
        3, // cyan
        7, // white
    };

    if (code == 0) {
        return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }

    if (code >= 30 && code <= 37) {
        int index = code - 30;
        return ((current & 0xFFF0) | ansi_map[index]);
    } else if (code >= 90 && code <= 97) {
        int index = code - 90;
        return ((current & 0xFFF0) | ansi_map[index] | FOREGROUND_INTENSITY);
    }

    if (code >= 40 && code <= 47) {
        int index = code - 40;
        return ((current & 0xFF0F) | (ansi_map[index] << 4));
    } else if (code >= 100 && code <= 107) {
        int index = code - 100;
        WORD bg = (ansi_map[index] | FOREGROUND_INTENSITY) << 4;
        return ((current & 0xFF0F) | bg);
    }

    return current;
}

#endif

template <typename Stream> inline bool detect_rgb(Stream& stream) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(details::get_standard_handle(stream));
    if (hConsole == INVALID_HANDLE_VALUE)
        return false;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hConsole, &dwMode))
        return false;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hConsole, dwMode))
        return false;
#endif
    return details::is_atty(stream);
}

template <typename Stream>
inline void _set_color(Stream& stream, rgb_color color, bool is_bg) {
    const char* mode = is_bg ? "\033[48;2;" : "\033[38;2;";
    stream << mode << static_cast<int>(color.red) << ";"
           << static_cast<int>(color.green) << ";"
           << static_cast<int>(color.blue) << "m";
}

template <typename Stream>
inline void _set_color(Stream& stream, legacy_color c) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(details::get_standard_handle(stream));

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;

    WORD current = csbi.wAttributes;
    WORD color = AnsiToWindowsColor(c.code, current);

    SetConsoleTextAttribute(hConsole, color);
#else
    stream << "\033[" << static_cast<int>(c.code) << "m";
#endif
}

template <typename Stream>
inline void set_color(Stream& stream, rgb_color color) {
    if (!detect_rgb(stream))
        return;

    _set_color(stream, color, false);
}

template <typename Stream>
inline void set_color(Stream& stream, legacy_color color) {
    _set_color(stream, color);
}

template <typename Stream> inline void set_color(Stream& stream, on_rgb color) {
    if (!detect_rgb(stream))
        return;

    _set_color(stream, color.color, true);
}

/// Legacy16 color defines
#define C(color, ansi)                                                         \
    typedef ::ox::legacy16_type<(ansi)> color;                                 \
    typedef ::ox::legacy16_type<(ansi) + 10> on_##color;                       \
    typedef ::ox::legacy16_type<(ansi) + 60> bright_##color;                   \
    typedef ::ox::legacy16_type<(ansi) + 70> on_bright_##color;

#define STYLE(style, ansi) typedef ::ox::legacy16_type<(ansi)> style;
} // namespace details

C(reset, 0)
C(grey, 30)
C(red, 31)
C(green, 32)
C(yellow, 33)
C(blue, 34)
C(magenta, 35)
C(cyan, 36)
C(white, 37)
STYLE(bold, 1)
STYLE(dark, 2)
STYLE(italic, 3)
STYLE(underline, 4)
STYLE(blink, 5)
STYLE(reverse, 7)
STYLE(concealed, 8)
STYLE(crossed, 9)

typedef rgb_type<0, 0, 0> rgb_reset;
typedef on_rgb_type<0, 0, 0> on_rgb_reset;

#undef STYLE
#undef C
} // namespace ox

#ifndef OX_TERMCOLOR_NO_STD
#include "types/std.hpp"
#endif

#ifdef OX_POSIX
#undef OX_POSIX
#endif
