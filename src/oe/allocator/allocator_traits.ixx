/**
 * @file allocator_traits.ixx
 * @brief The allocator traits. Gives the allocator specs check.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.allocator.allocator_traits;

import oe.types.basic_types;
import oe.allocator.allocator_types;

export namespace oe {
/**
 * @brief Checks if a type follows the allocator interface specs.
 *
 * The implemented allocator should have these following interfaces:
 * - oe::pvoid allocate(oe::usize size, oe::memory_alignment alignment) noexcept;
 * - void deallocate(oe::pvoid ptr, oe::memory_alignment alignment) noexcept;
 * - bool resize(oe::pvoid ptr, oe::memory_alignment alignment, oe::usize new_size) noexcept;
 * - oe::pvoid remap(oe::pvoid ptr, oe::memory_alignment alignment, oe::usize new_size) noexcept;
 *
 * The returned result should be *convertible* to these own return types.
 *
 * @see oe::oe::allocator
 * @see oe::oe::dyn_allocator
 *
 * @tparam T The type to check
 * @return true if the type follows the allocator interface specs, false
 * otherwise
 */
template <typename T>
concept is_allocator =
    requires(T& t, oe::pvoid ptr, oe::usize size, oe::memory_alignment alignment) {
        { t.allocate(size, alignment) } noexcept -> oe::convertible_to<oe::pvoid>;
        { t.deallocate(ptr, alignment) } noexcept;
        { t.resize(ptr, alignment, size) } noexcept -> oe::convertible_to<bool>;
        { t.remap(ptr, alignment, new_size) } noexcept -> oe::convertible_to<oe::pvoid>;
    };

} // namespace oe