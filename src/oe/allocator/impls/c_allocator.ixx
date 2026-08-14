/**
 * @file c_allocator.ixx
 * @brief A C allocator implementation that uses the standard C library.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/allocator/allocator_define.hpp>
#include <oe/detections/compiler_detections.h>
#ifdef OE_HAS_MSVC_COMPILER_ID
// MSVC CRT headers
#    include <malloc.h>
#else
#    include <cstdlib>
#endif

export module oe.allocator.impls.c_allocator;

import oe.types.basic_types;
import oe.allocator.allocator_types;
import oe.allocator.dynamic_allocator;
import oe.conv.cast;

export namespace oe {
OE_DEFINE_ALLOCATOR(c_allocator)

inline oe::pvoid c_allocator::allocate(oe::usize size, oe::memory_alignment alignment) noexcept {
#if OE_HAS_MSVC_COMPILER_ID
    // an unstandard function
    // see cppreference for more details.
    // MSVC CRT has not defined std::aligned_malloc but defined _aligned_malloc
    return _aligned_malloc(size, oe::cast<oe::usize>(alignment));
#else
    return std::aligned_alloc(alignment, size);
#endif
}

inline void c_allocator::deallocate(oe::pvoid ptr,
                                    [[maybe_unused]] oe::memory_alignment alignment) noexcept {
#if defined(OE_HAS_MSVC_COMPILER_ID)
    _aligned_free(ptr);
#else
    std::free(ptr);
#endif
}

inline bool c_allocator::resize([[maybe_unused]] oe::pvoid ptr,
                                [[maybe_unused]] oe::memory_alignment alignment,
                                [[maybe_unused]] oe::usize new_size) noexcept {
    return false; // C Allocator does not support resize
}

inline oe::pvoid c_allocator::remap(oe::pvoid ptr, [[maybe_unused]] oe::memory_alignment alignment,
                                    oe::usize new_size) noexcept {
    if (new_size == 0)
        return ptr;
#ifdef OE_HAS_MSVC_COMPILER_ID
    // an unstandard function
    // see cppreference for more details.
    // MSVC CRT has not defined std::aligned_realloc but defined
    // _aligned_realloc
    return _aligned_realloc(ptr, new_size, oe::cast<oe::usize>(alignment));
#else
    return std::realloc(ptr, new_size);
#endif
}
} // namespace oe