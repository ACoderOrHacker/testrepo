/**
 * @file test_types.cpp
 * @brief The `types` test
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */

import oe.types;

#include <base_test.hpp>

TEST(test_types, byte_ops) {
    oe::byte b{0xF0};
    EXPECT_EQ(static_cast<oe::u8>(b), 0xF0);

    oe::byte a{0x0F};
    EXPECT_EQ(static_cast<oe::u8>(a | b), 0xFF);

    oe::byte d{1};
    d <<= 2;
    EXPECT_EQ(static_cast<oe::u8>(d), 4);

    oe::byte e = b >> 4;
    EXPECT_EQ(static_cast<oe::u8>(e), static_cast<oe::u8>(0xF0 >> 4));

    int v = static_cast<int>(oe::byte{5});
    EXPECT_EQ(v, 5);
}

TEST(test_types, define_char_ops) {
    oe::c16 x{5};
    oe::c16 y = x + 3;
    EXPECT_EQ(y, oe::c16{8});

    ++x;
    EXPECT_EQ(x, oe::c16{6});
    x++;
    EXPECT_EQ(x, oe::c16{7});

    EXPECT_TRUE(oe::c16{10} > oe::c16{1});

    oe::c16 p{0x00FF};
    oe::c16 q = p & oe::c16{0x0F0F};
    EXPECT_EQ(q, oe::c16{0x000F});

    oe::c32 r{1};
    r = r + 2;
    EXPECT_EQ(r, oe::c32{3});
}

TEST(test_types, char_traits_concept) {
    EXPECT_TRUE(oe::is_char_traits_v<oe::char_traits<char>>);
    EXPECT_TRUE(oe::is_char_traits_v<oe::char_traits<wchar_t>>);
    EXPECT_TRUE(oe::is_char_traits_v<oe::char_traits<char16_t>>);
    EXPECT_TRUE(oe::is_char_traits_v<oe::char_traits<char32_t>>);
#if OE_CPP_STANDARD >= OE_CPP20_ID
    EXPECT_TRUE(oe::is_char_traits_v<oe::char_traits<char8_t>>);
#endif
    EXPECT_TRUE(oe::is_char_traits_v<oe::char_traits<oe::c8>>);
    EXPECT_TRUE(oe::is_char_traits_v<oe::char_traits<oe::c16>>);
    EXPECT_TRUE(oe::is_char_traits_v<oe::char_traits<oe::c32>>);
}