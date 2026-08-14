#include <gtest/gtest.h>
#include <oe/statusor.hpp>

using oe::status;
using oe::status_or;

TEST(statusor_test, status) {
    status a(oe::default_status::ok);
    EXPECT_EQ(a.error(), oe::default_status::ok);
}
