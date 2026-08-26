/**
 * @file char_traits_define.ixx
 * @brief The internal module for types.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#ifdef OE_CONFIG_TYPES_COMPATIBLE_WITH_STD
#include <cwchar>
#include <ios>
#endif

export module oe.types.char_traits:char_traits_define;

import oe.types.basic_types;
import oe.meta.concepts;
import oe.memory.c_apis;

namespace oe::details {
/**
 * @brief The basic char traits auto definition template
 * @tparam CharType The character type.
 * @tparam IntType The integer type.
 * @tparam EofValue The EOF value.
 */
template <typename CharType, typename IntType, IntType EofValue>
    requires oe::integral<IntType>
struct define_char_traits {
    using char_type = CharType; //!< The char type.
    using int_type = IntType;   //!< The integer type to storage the `char_type`

#ifdef OE_CONFIG_TYPES_COMPATIBLE_WITH_STD
    using off_type = std::streamoff;
    using pos_type = std::streampos;
    using state_type = std::mbstate_t;
#endif

    static constexpr inline bool eq(char_type a, char_type b) noexcept {
        return eq_int_type(to_int_type(a), to_int_type(b));
    }

    static constexpr inline bool eq_int_type(int_type a, int_type b) noexcept {
        return a == b;
    }

    static constexpr inline bool lt(char_type a, char_type b) noexcept {
        return to_int_type(a) < to_int_type(b);
    }

    static constexpr inline int compare(const char_type* a, const char_type* b,
                                        oe::usize n) noexcept {
        return oe::memcmp(a, b, n);
    }

    static constexpr inline const char_type*
    find(const char_type* s, oe::usize n, char_type c) noexcept {
        // TODO: a faster way?
        for (const char_type* p = s; p < s + n; ++p) {
            if (*p == c) {
                return p;
            }
        }
        return nullptr;
    }

    static constexpr inline char_type*
    copy(char_type* dest, const char_type* src, oe::usize n) noexcept {
        return oe::memcpy(dest, src, n);
    }

    static constexpr inline char_type*
    move(char_type* dest, const char_type* src, oe::usize n) noexcept {
        return oe::memmove(dest, src, n);
    }

    static constexpr inline void assign(char_type& c,
                                        char_type value) noexcept {
        c = value;
    }

    static constexpr inline char_type* assign(char_type* dest, oe::usize n,
                                              char_type c) noexcept {
        // TODO: a faster way?
        for (oe::usize i = 0; i < n; ++i) {
            assign(dest[i], c);
        }
        return dest;
    }

    static constexpr inline oe::usize length(const char_type* s) noexcept {
        oe::usize sz = 0;
        while (s[sz] != 0) {
            ++sz;
        }
        return sz;
    }

    static constexpr inline int_type to_int_type(char_type c) noexcept {
        return static_cast<int_type>(c);
    }

    static constexpr inline char_type to_char_type(int_type i) noexcept {
        return static_cast<char_type>(i);
    }

    static constexpr inline int_type eof() noexcept { return EofValue; }

    static constexpr inline int_type not_eof(int_type i) noexcept {
        return i != eof() ? i : eof();
    }
};
} // namespace oe::details