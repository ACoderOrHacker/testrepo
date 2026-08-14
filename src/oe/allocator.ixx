/**
 * @file allocator.ixx
 * @brief The `allocator` module for memory allocation, deallocation, remapping, etc.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.allocator;

export import oe.allocator.allocator_types;
export import oe.allocator.allocator_traits;
export import oe.allocator.dynamic_allocator;
export import oe.allocator.static_allocator;
export import oe.allocator.allocator_operator;

// Impls

export import oe.allocator.impls.c_allocator;
