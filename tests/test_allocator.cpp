#include <gtest/gtest.h>
#include <oe/allocator.hpp>

OE_DEFINE_ALLOCATOR(test_allocator)
oe::pvoid test_allocator::allocate(oe::usize size,
                                   oe::memory_alignment alignment) noexcept {
    return malloc(size);
}

void test_allocator::deallocate(oe::pvoid ptr,
                                oe::memory_alignment alignment) noexcept {
    free(ptr);
}

oe::pvoid test_allocator::remap(oe::pvoid ptr, oe::memory_alignment alignment,
                                oe::usize new_size) noexcept {
    return nullptr;
}

bool test_allocator::resize(oe::pvoid ptr, oe::memory_alignment alignment,
                            oe::usize new_size) noexcept {
    return false;
}

TEST(allocator_test, traits) {
    static_assert(
        oe::is_allocator_v<test_allocator>,
        "Bad OE_DEFINE_ALLOCATOR/is_allocator_v: static allocator failed the "
        "is_allocator_v test");

    static_assert(
        oe::is_allocator_v<dyn_test_allocator>,
        "Bad OE_DEFINE_ALLOCATOR/is_allocator_v: dynamic allocator failed the "
        "is_allocator_v test");
}

TEST(allocator_test, dynamic_allocator) {
    auto impl = new dyn_test_allocator;
    oe::dyn_allocator a{impl};

    ASSERT_EQ(a.vtable(), impl); // vtable must be equal to the impl

    auto impl2 = new dyn_test_allocator;
    a.vtable() = impl2;

    ASSERT_EQ(a.vtable(), impl2); // vtable can be changed
}

TEST(allocator_test, interfaces) {
    oe::allocator<test_allocator> a;
    auto mem = a.allocate<int>(10);
    ASSERT_EQ(mem.size(), 10);

    ASSERT_NE(mem.ptr(), nullptr);
    a.deallocate(mem);
}

TEST(allocator_test, c_allocator) {
    oe::allocator<oe::c_allocator> a;
    auto mem = a.allocate<int>(10);
    ASSERT_EQ(mem.size(), 10);
    ASSERT_NE(mem.ptr(), nullptr);

    bool test = a.resize<int>(mem.ptr(), 20);
    ASSERT_EQ(test, false); // unsupported
    ASSERT_EQ(mem.size(), 10);
    ASSERT_NE(mem.ptr(), nullptr);

    auto mem2 = a.remap<int>(mem.ptr(), 30);
    ASSERT_EQ(mem2.size(), 30);
    ASSERT_NE(mem2.ptr(), nullptr);

    auto mem3 = a.remap<int>(mem2.ptr(), 0);
    ASSERT_EQ(mem3.size(), 0);
    ASSERT_EQ(mem3.ptr(), mem2.ptr());
}
