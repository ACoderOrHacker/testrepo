#include <gtest/gtest.h>
#include <oe/conv.hpp>

TEST(conv_test, to) {
    int i;
    void* j = &i;
    int* l = oe::to<int*>(j).unwrap();
    int* k = oe::to<int*>(j).unwrap();
    EXPECT_EQ(k, j);
}
