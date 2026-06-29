/**
 * @file string.hpp
 * @brief
 */
#pragma once

#if defined(OE_USE_STD_MODULES) || defined(OE_STRING_USE_MODULES)
import std;
#else
#include <cstring>
#endif
#include <oe/types.hpp>

namespace oe {
namespace details {
namespace string {
/**
 * @brief Get Length of a c-style string.
 */
template <typename SizeType, typename CharType>
inline constexpr SizeType strlen(const CharType* str) {
#if !defined(OE_NOT_USE_STD_LIBS) && !defined(OE_TYPES_NOT_USE_STD_LIBS)
    return static_cast<SizeType>(std::strlen(str));
#else
    // TODO: add a more fast way
    const char* s = str;
    while (*s)
        s++;
    return static_cast<SizeType>(s - str);
#endif
}

/**
 * @brief Basic string definition.
 */
template <typename T> struct basic_string {
  public:
    using value_type = T;
    using size_type = oe::usize;

    /**
     * @brief Construct a basic_string from a c-style string or a string
     * literal.
     *
     * @param str The c-style string or string literal to construct from.
     */
    explicit constexpr basic_string(const value_type* str)
        : m_data{str, oe::details::string::strlen(str)} {}

    /**
     * @brief Get the c-style string representation of this string.
     *
     * @return The c-style string representation of this string.
     */
    constexpr value_type* c_str() { return m_data.c_str(); }

    /**
     * @brief Get the length of this string.
     *
     * @return The length of this string.
     */
    constexpr size_type length() { return m_data.length; }

  private:
    // m_data's T* is the front of the string
    // then the size follows
    // can be used directly to c-style string operations
    struct {
        T* data;
        size_type length;

        char* c_str() { return static_cast<char*>(data); }
    } m_data;
};
} // namespace string
} // namespace details

namespace impl {
namespace string {
using u8string = oe::details::string::basic_string<c8>;
using u16string = oe::details::string::basic_string<c16>;
using u32string = oe::details::string::basic_string<c32>;
} // namespace string
} // namespace impl
} // namespace oe

#ifndef OE_STRING_USE_MODULES
namespace oe {
using namespace impl::string;
}
#endif
