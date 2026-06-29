#include <gtest/gtest.h>
#include <oe/statusor.hpp>

using oe::status_or;
namespace {
TEST(status_or_test, sample) {
    status_or<int> result = 42;
    EXPECT_EQ(result.value(), 42);
}
} // namespace
