/**
 * @file static_allocator.ixx
 * @brief The static allocator implementation.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/api.h>

export module oe.allocator.static_allocator;

import oe.allocator.allocator_traits;
export import oe.allocator.allocator_types;
export import oe.types.basic_types;
export import oe.containers.span;

export namespace oe {
/**
 * @brief The static allocator implementation.
 * This allocator uses the static allocator type T to allocate memory.
 * It is a simple wrapper around the static allocator type T.
 */
template <typename Allocator> struct OE_API allocator {
    static_assert(oe::is_allocator<Allocator>,
                  "Allocator requires an allocator type, must follow the "
                  "oe::is_allocator");

    /**
     * @brief Allocates memory of the given size and alignment, using just the
     * allocator implementation.
     * @note Should be freed with raw_deallocate
     * @see oe::raw_deallocate
     * @pre The size must be greater than 0
     * @pre The alignment must be a power of 2
     * @param[in] size The size of the memory to allocate
     * @param[in] alignment The alignment of the memory to allocate
     * @return A pointer to the allocated memory, nullptr if the allocation
     * fails
     */
    inline oe::pvoid raw_allocate(oe::usize size, oe::memory_alignment alignment) {
        return Allocator::allocate(size, alignment);
    }

    /**
     * @brief Frees the memory allocated by raw_allocate
     * @details This function should only be used to free memory allocated by
     * raw_allocate, if the ptr is a nullptr, the function does nothing.
     * @see oe::raw_allocate
     * @pre The alignment must be a power of 2
     * @param[in] ptr The pointer to the memory to free
     * @param[in] alignment The alignment of the memory to free
     */
    inline void raw_deallocate(oe::pvoid ptr, oe::memory_alignment alignment) noexcept {
        Allocator::deallocate(ptr, alignment);
    }

    /**
     * @brief Resize the memory at the given pointer to the given size and
     * alignment
     * @details If the ptr is nullptr, this function returns false.
     * If the new size is 0, this function deallocates the memory and returns
     * true. It is certain not to move the pointer. So the allocator implementation
     * can refuse this operation and return false.
     * @see oe::raw_remap
     * @param[in] ptr The pointer to the memory to resize
     * @param[in] alignment The alignment of the memory to resize
     * @param[in] new_size The new size of the memory
     * @return The status of the resize operation. False if the resize fails,
     * true otherwise.
     */
    inline bool raw_resize(oe::pvoid ptr, oe::memory_alignment alignment,
                           oe::usize new_size) noexcept {
        return Allocator::resize(ptr, alignment, new_size);
    }

    /**
     * @brief Remap the memory at the given pointer to the given size and
     * alignment
     * @details If the ptr is nullptr, this function does nothing.
     * If the new size is 0, this function deallocates the memory and returns
     * the old pointer (freed). It may move the pointer and copy the old data to
     * the new location.
     * @see oe::raw_resize
     * @param[in] ptr The pointer to the memory to resize
     * @param[in] alignment The alignment of the memory to resize
     * @param[in] new_size The new size of the memory
     * @return The reallocated pointer, nullptr if the allocation fails, the old
     * pointer (freed) if new_size is 0
     */
    inline oe::pvoid raw_remap(oe::pvoid ptr, oe::memory_alignment alignment,
                               oe::usize new_size) noexcept {
        return Allocator::remap(ptr, alignment, new_size);
    }

    /**
     * @brief Allocates memory for the type T with the given alignment
     * @see oe::deallocate
     * @pre alignment must be a power of 2
     * @pre sizeof(T) * n cannot overflow
     * @tparam T The type of the memory to allocate
     * @param[in] n The number of elements to allocate, default is 1
     * @param[in] alignment The alignment of the memory to allocate, default is
     * alignof(T)
     * @return An array to the allocated memory, ptr() == nullptr if the
     * allocation fails
     */
    template <typename T>
    inline oe::span<T> allocate(oe::usize n = 1,
                                oe::memory_alignment alignment = alignof(T)) noexcept {
        return oe::span<T>{static_cast<T*>(this->raw_allocate(sizeof(T) * n, alignment)), n};
    }

    /**
     * @brief Frees the memory allocated by allocate
     * @details This function should only be used to free memory allocated by
     * allocate, if the ptr is a nullptr, the function does nothing.
     * @see oe::allocate
     * @tparam T The type of the memory to free
     * @param[out] data The data to free, the ptr() is unknown after this call
     * @param[in] alignment The alignment of the memory to free
     */
    template <typename T>
    inline void deallocate(oe::span<T> data, oe::memory_alignment alignment = alignof(T)) noexcept {
        this->raw_deallocate(data.ptr(), alignment);
    }

    /**
     * @brief Resize the memory at the given pointer to the given size
     * @details If the ptr is nullptr, this function returns false.
     * If the n is 0, this function deallocates the memory and returns
     * true. It is certain not to move the pointer. So the allocator implementation
     * can refuse this operation and return false.
     * @see oe::raw_resize
     * @pre sizeof(T) * n cannot overflow
     * @tparam T The type of the memory to resize
     * @param[in] ptr The pointer to resize
     * @param[in] n The new size of the memory to resize
     * @param[in] alignment The alignment of the memory to resize
     * @return The status of the resize operation. False if the resize fails,
     * true otherwise.
     */
    template <typename T>
    inline bool resize(oe::pvoid ptr, oe::usize n,
                       oe::memory_alignment alignment = alignof(T)) noexcept {
        return this->raw_resize(ptr, alignment, sizeof(T) * n);
    }

    /**
     * @brief Remap the memory at the given pointer to the given size
     * @details If the ptr is nullptr, this function returns nullptr.
     * If the n is 0, this function deallocates the memory and returns
     * the old pointer (freed). It may move the pointer and copy the old data to
     * the new location.
     * @see oe::raw_remap
     * @pre sizeof(T) * n cannot overflow
     * @param[in] ptr The pointer to remap
     * @param[in] n The number of elements to remap
     * @param[in] alignment The alignment of the memory to remap
     * @return The reallocated data, ptr() == nullptr if the allocation fails,
     * ptr() == the old pointer (freed) if n is 0
     */
    template <typename T>
    inline oe::span<T> remap(oe::pvoid ptr, oe::usize n,
                             oe::memory_alignment alignment = alignof(T)) noexcept {
        return oe::span<T>{static_cast<T*>(this->raw_remap(ptr, alignment, sizeof(T) * n)), n};
    }

    /**
     * @brief Reallocates the memory allocated by allocate
     * @details if the ptr is a nullptr, the function allocates a new block of
     * memory. This function can only fail on out-of-memory.
     * @see oe::allocate remap
     * @pre sizeof(T) * n cannot overflow
     * @param[in] ptr The pointer to reallocate
     * @param[in] n The number of elements to reallocate
     * @param[in] alignment The alignment of the memory to reallocate
     * @return A data array to the reallocated memory, ptr() == nullptr if the
     * reallocation fails, ptr() == the old pointer (freed) if data.size() is 0
     */
    template <typename T>
    inline oe::span<T> reallocate(oe::pvoid ptr, oe::usize n,
                                  oe::memory_alignment alignment = alignof(T)) noexcept {
        T* new_ptr = this->remap<T>(ptr, n, alignment);
        if (new_ptr != nullptr)
            return new_ptr;
        return this->allocate<T>(n, alignment);
    }
};
} // namespace oe
