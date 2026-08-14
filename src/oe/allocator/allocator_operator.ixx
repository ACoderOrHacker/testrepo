/**
 * @file allocator_operator.ixx
 * @brief The allocator operators for `operator new` and `operator delete`.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <new>
#include <oe/api.h>

export module oe.allocator.allocator_operator;

import oe.types.basic_types;
export import oe.allocator.static_allocator;
export import oe.allocator.dynamic_allocator;
export import oe.allocator.allocator_types;

export namespace oe {
using std::get_new_handler; //!< Get the current `new_handler` function.
using std::new_handler;     //!< `new_handler` function type.
using std::set_new_handler; //!< Set the `new_handler` function.

template <typename Allocator>
using use_allocator_t = allocator<Allocator>; //!< The type of `oe::use_allocator`

/**
 * @brief A tag used to indicate the allocator to use.
 *
 * Used in `new` and `delete` expression.
 * @code{.cpp}
 * import oe.allocator;
 *
 * int main() {
 *      int *ptr = new(oe::use_allocator<oe::c_allocator>) int; // Using oe::c_allocator to
 * allocate.
 *
 *      // Using `ptr`...
 *
 *      delete(oe::use_allocator<oe::c_allocator>) ptr;
 *      return 0;
 * }
 * @endcode
 */
template <typename Allocator> inline constexpr use_allocator_t use_allocator{};
} // namespace oe

/**
 * @brief `operator new` implementation for OE allocator.
 *
 * Allocates aligned memory using the specified allocator.
 * No exceptions are thrown although the allocation is failed.
 *
 * @see oe::allocator
 *
 * @tparam Allocator The allocator type.
 */
export template <typename Allocator>
static inline OE_API void* operator new(oe::usize size, oe::memory_alignment alignment,
                                        oe::use_allocator_t<Allocator> allocator) noexcept {
    return allocator.raw_allocate(size, alignment);
}

/**
 * @brief `operator new` implementation for OE allocator.
 *
 * Allocates memory using the specified allocator.
 * No exceptions are thrown although the allocation is failed.
 *
 * @see oe::allocator
 *
 * @tparam Allocator The allocator type.
 */
export template <typename Allocator>
static inline OE_API void* operator new(oe::usize size,
                                        oe::use_allocator_t<Allocator> allocator) noexcept {
    return allocator.raw_allocate(size);
}

/**
 * @brief `operator new` implementation for OE allocator.
 *
 * Allocates multiple aligned memory using the specified allocator.
 * No exceptions are thrown although the allocation is failed.
 *
 * @see oe::allocator
 *
 * @tparam Allocator The allocator type.
 */
export template <typename Allocator>
static inline OE_API void* operator new[](oe::usize size, oe::memory_alignment alignment,
                                          oe::use_allocator_t<Allocator> allocator) noexcept {
    return allocator.raw_allocate(size, alignment);
}

/**
 * @brief `operator new` implementation for OE allocator.
 *
 * Allocates multiple memory using the specified allocator.
 * No exceptions are thrown although the allocation is failed.
 *
 * @see oe::allocator
 *
 * @tparam Allocator The allocator type.
 */
export template <typename Allocator>
static inline OE_API void* operator new[](oe::usize size,
                                          oe::use_allocator_t<Allocator> allocator) noexcept {
    return allocator.raw_allocate(size);
}

/**
 * @brief `operator delete` implementation for OE allocator.
 *
 * Deallocates aligned memory using the specified allocator.
 * No exceptions are thrown although the deallocation is failed.
 *
 * @see oe::allocator
 *
 * @tparam Allocator The allocator type.
 */
export template <typename Allocator>
static inline OE_API void operator delete(void* ptr, oe::memory_alignment alignment,
                                          oe::use_allocator_t<Allocator> allocator) noexcept {
    allocator.deallocate(ptr, alignment);
}

/**
 * @brief `operator delete` implementation for OE allocator.
 *
 * Deallocates memory using the specified allocator.
 * No exceptions are thrown although the deallocation is failed.
 *
 * @see oe::allocator
 *
 * @tparam Allocator The allocator type.
 */
export template <typename Allocator>
static inline OE_API void operator delete(void* ptr,
                                          oe::use_allocator_t<Allocator> allocator) noexcept {
    allocator.deallocate(ptr);
}

/**
 * @brief `operator delete` implementation for OE allocator.
 *
 * Deallocates multiple aligned memory using the specified allocator.
 * No exceptions are thrown although the deallocation is failed.
 *
 * @see oe::allocator
 *
 * @tparam Allocator The allocator type.
 */
export template <typename Allocator>
static inline OE_API void operator delete[](void* ptr, oe::memory_alignment alignment,
                                            oe::use_allocator_t<Allocator> allocator) noexcept {
    allocator.deallocate(ptr, alignment);
}

/**
 * @brief `operator delete` implementation for OE allocator.
 *
 * Deallocates multiple memory using the specified allocator.
 * No exceptions are thrown although the deallocation is failed.
 *
 * @see oe::allocator
 *
 * @tparam Allocator The allocator type.
 */
export template <typename Allocator>
static inline OE_API void operator delete[](void* ptr,
                                            oe::use_allocator_t<Allocator> allocator) noexcept {
    allocator.deallocate(ptr);
}
