/**
 * @file test_iterator.cpp
 * @brief The `iterator` test
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */

#include <base_test.hpp>

import oe.types;
import oe.iterator.iterator_traits;
import oe.iterator.iterator_wrapper;

using namespace oe;

// -------------------------
// Helper iterator implementations used by tests
// -------------------------

// ImplA: exposes nested types and kind inside the implementation
struct ImplA {
    using difference_type = ssize;
    using value_type = int;
    using reference_type = int&;
    constexpr static oe::iterator_kind kind = oe::iterator_kind::input;

    int m_value{0};
    constexpr const reference_type data() const noexcept {
        return const_cast<ImplA*>(this)->m_value;
    }
    constexpr reference_type data() noexcept { return m_value; }
    constexpr void next() noexcept { ++m_value; }
    constexpr bool equal_to(const ImplA& other) const noexcept { return m_value == other.m_value; }
    constexpr bool equal_to(sentinel) const noexcept { return m_value == -1; }
};

// ImplB: does NOT provide nested types; define specialization of iterator_traits for it
struct ImplB {
    // implementation does data/next
    int index{0};
    int* storage{nullptr};
    constexpr const int& data() const noexcept { return storage[index]; }
    constexpr int& data() noexcept { return storage[index]; }
    constexpr void next() noexcept { ++index; }
    constexpr bool equal_to(const ImplB& other) const noexcept {
        return index == other.index && storage == other.storage;
    }
    constexpr bool equal_to(sentinel) const noexcept {
        return storage == nullptr || storage[index] == -1;
    }
};

// Provide iterator_traits specialization for ImplB
template <> struct oe::iterator_traits<ImplB> {
    using difference_type = ssize;
    using value_type = int;
    using reference_type = int&;
    constexpr static oe::iterator_kind kind = oe::iterator_kind::input;
};

// Random access implementation with full operations
struct ImplRandom {
    using difference_type = ssize;
    using value_type = int;
    using reference_type = int&;
    constexpr static oe::iterator_kind kind = oe::iterator_kind::random;

    int* data_ptr{nullptr};
    usize idx{0};

    constexpr reference_type data() noexcept { return data_ptr[idx]; }
    constexpr const reference_type data() const noexcept { return data_ptr[idx]; }

    constexpr void next() noexcept { ++idx; }
    constexpr void next(usize n) noexcept { idx += n; }
    constexpr void prev() noexcept { --idx; }
    constexpr void prev(usize n) noexcept { idx -= n; }

    constexpr bool equal_to(const ImplRandom& o) const noexcept {
        return data_ptr == o.data_ptr && idx == o.idx;
    }
    constexpr bool equal_to(sentinel) const noexcept { return data_ptr == nullptr; }

    constexpr bool less_than(const ImplRandom& o) const noexcept { return idx < o.idx; }
    constexpr ssize distance_to(const ImplRandom& o) const noexcept {
        return static_cast<ssize>(o.idx) - static_cast<ssize>(idx);
    }
};

// ImplNoNextN: provides next() but not next(n) to test fallback looping
struct ImplNoNextN {
    using difference_type = ssize;
    using value_type = int;
    using reference_type = int&;
    constexpr static oe::iterator_kind kind = oe::iterator_kind::forward;

    int* data_ptr{nullptr};
    usize idx{0};

    constexpr reference_type data() noexcept { return data_ptr[idx]; }
    constexpr void next() noexcept { ++idx; }
    // no next(n)
    constexpr bool equal_to(const ImplNoNextN& o) const noexcept {
        return data_ptr == o.data_ptr && idx == o.idx;
    }
    constexpr bool equal_to(sentinel) const noexcept { return data_ptr == nullptr; }
    constexpr void next_n_counter(usize) noexcept {} // dummy
};

// -------------------------
// Tests for iterator_traits accessor/checker
// -------------------------

TEST(iterator_traits_test, accessor_prefers_impl_types) {
    // ImplA exposes nested types; accessor should use them
    static_assert(iterator_traits_checker<ImplA>::has_difference_type_in_impl,
                  "ImplA must have difference_type");
    static_assert(iterator_traits_checker<ImplA>::has_value_type_in_impl,
                  "ImplA must have value_type");
    static_assert(iterator_traits_checker<ImplA>::has_reference_type_in_impl,
                  "ImplA must have reference_type");
    static_assert(iterator_traits_checker<ImplA>::has_kind_in_impl, "ImplA must have kind");

    using acc = iterator_traits_accessor<ImplA>;
    static_assert(std::is_same_v<acc::difference_type, ImplA::difference_type>);
    static_assert(std::is_same_v<acc::value_type, ImplA::value_type>);
    static_assert(std::is_same_v<acc::reference_type, ImplA::reference_type>);
    static_assert(acc::kind == ImplA::kind);
}

TEST(iterator_traits_test, accessor_uses_traits_specialization) {
    // ImplB does not expose nested types but has iterator_traits specialization
    static_assert(!iterator_traits_checker<ImplB>::has_value_type_in_impl,
                  "ImplB should not have value_type in impl");
    static_assert(iterator_traits_checker<ImplB>::has_value_type_in_traits,
                  "iterator_traits specialization should provide value_type");

    using acc = iterator_traits_accessor<ImplB>;
    static_assert(std::is_same_v<acc::value_type, int>);
    static_assert(acc::kind == iterator_kind::input);
}

// -------------------------
// Tests for iterator wrapper behavior
// -------------------------

TEST(iterator_wrapper_test, random_access_basic_ops) {
    int arr[5] = {10, 11, 12, 13, 14};
    ImplRandom a{arr, 0};
    ImplRandom b{arr, 3};

    iterator<ImplRandom> it{a};
    iterator<ImplRandom> it3{b};

    // dereference
    EXPECT_EQ(*it, 10);

    // advance by +n using next(n)
    auto it2 = it + 3u;
    EXPECT_EQ(*it2, 13);

    // operator[]
    EXPECT_EQ(it[2], 12);

    // comparisons
    EXPECT_TRUE(it < it3);
    EXPECT_EQ(distance(it, it3), 3);

    // increment / decrement
    ++it;
    EXPECT_EQ(*it, 11);
    it++;
    EXPECT_EQ(*it, 12);
    --it;
    EXPECT_EQ(*it, 11);
    it--;
    EXPECT_EQ(*it, 10);
}

TEST(iterator_wrapper_test, advance_fallback_calls_next_many_times) {
    int arr[4] = {0, 1, 2, 3};
    ImplNoNextN impl{arr, 0};
    iterator<ImplNoNextN> it{impl};

    auto it2 = it + 3u; // should loop calling next() three times
    EXPECT_EQ(*it2, 3);
    // original it must be unchanged
    EXPECT_EQ(*it, 0);
}

TEST(iterator_wrapper_test, distance_fallback_counts_steps) {
    int arr[4] = {0, 1, 2, 3};
    ImplNoNextN a{arr, 0};
    ImplNoNextN b{arr, 3};
    iterator<ImplNoNextN> it1{a};
    iterator<ImplNoNextN> it2{b};

    // distance should loop until equal and return 3
    EXPECT_EQ(distance(it1, it2), 3);
}

TEST(iterator_wrapper_test, equality_with_sentinel) {
    ImplA x;
    x.m_value = -1; // sentinel condition for ImplA
    iterator<ImplA> it{x};
    EXPECT_TRUE(it == sentinel{});
}

// -------------------------
// Tests for natural pointer-like iterators
// -------------------------

// Adapter wrapping a raw pointer to behave like a contiguous iterator implementation
struct ImplPtr {
    using difference_type = ssize;
    using value_type = int;
    using reference_type = int&;
    constexpr static oe::iterator_kind kind = oe::iterator_kind::contiguous;

    int* p{nullptr};

    constexpr reference_type data() noexcept { return *p; }
    constexpr const reference_type data() const noexcept { return *p; }

    constexpr void next() noexcept { ++p; }
    constexpr void next(usize n) noexcept { p += n; }
    constexpr void prev() noexcept { --p; }
    constexpr void prev(usize n) noexcept { p -= n; }

    constexpr bool equal_to(const ImplPtr& o) const noexcept { return p == o.p; }
    constexpr bool equal_to(sentinel) const noexcept { return p == nullptr; }
    constexpr bool less_than(const ImplPtr& o) const noexcept { return p < o.p; }
    constexpr ssize distance_to(const ImplPtr& o) const noexcept { return static_cast<ssize>(o.p - p); }
};

TEST(pointer_iterator_test, pointer_like_basic_ops) {
    int arr[6] = {5, 6, 7, 8, 9, 10};
    ImplPtr a{arr};
    ImplPtr b{arr + 5};

    iterator<ImplPtr> it{a};
    iterator<ImplPtr> it_end{b};

    // dereference
    EXPECT_EQ(*it, 5);

    // operator[] using contiguous behavior
    EXPECT_EQ(it[3], 8);

    // distance computed by provided distance_to
    EXPECT_EQ(distance(it, it_end), 5);

    // advance by n
    auto it2 = it + 4u;
    EXPECT_EQ(*it2, 9);

    // comparisons
    EXPECT_TRUE(it < it_end);
    EXPECT_FALSE(it_end < it);

    // increment and decrement
    ++it;
    EXPECT_EQ(*it, 6);
    it++;
    EXPECT_EQ(*it, 7);
    --it;
    EXPECT_EQ(*it, 6);
}


TEST(pointer_native_test, raw_pointer_mutable) {
    int arr[6] = {5, 6, 7, 8, 9, 10};
    // construct iterator directly from raw pointer
    iterator<int*> it{arr};
    iterator<int*> it_end{arr + 5};

    EXPECT_EQ(*it, 5);
    EXPECT_EQ(it[3], 8);
    EXPECT_EQ(distance(it, it_end), 5);

    auto it2 = it + 4u;
    EXPECT_EQ(*it2, 9);

    // comparisons
    EXPECT_TRUE(it < it_end);

    // increment / decrement
    ++it;
    EXPECT_EQ(*it, 6);
    it++;
    EXPECT_EQ(*it, 7);
    --it;
    EXPECT_EQ(*it, 6);

    // set through iterator (mutable pointer specialization provides set)
    it.set(123);
    EXPECT_EQ(*it, 123);
}

TEST(pointer_native_test, raw_pointer_const) {
    const int arr[4] = {1, 2, 3, 4};
    iterator<const int*> it{arr};
    iterator<const int*> it2{arr + 2};

    EXPECT_EQ(*it, 1);
    EXPECT_EQ(*it2, 3);
    EXPECT_EQ(it[2], 3);

    EXPECT_EQ(distance(it, it2), 2);

    ++it;
    EXPECT_EQ(*it, 2);

    // cannot call set on const iterator - compile-time check: ensure expression is not well-formed
    // (we cannot static_assert ill-formed in runtime; this comment documents expected behavior)
}

TEST(pointer_native_test, null_pointer_equals_sentinel) {
    iterator<int*> it{nullptr};
    EXPECT_TRUE(it == sentinel{});
}

// End of tests
