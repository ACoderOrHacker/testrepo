/**
 * @file allocator_types.ixx
 * @brief The types for allocator.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <new>

export module oe.allocator.allocator_types;

export namespace oe {
using memory_alignment = std::align_val_t; //!< Memory alignment type.
using std::nothrow;                        //!< `nothrow` tag for `operator new`.

using std::launder; //!< Mark the old pointer as valid if evaluates `placeholder new`.

} // namespace oe
