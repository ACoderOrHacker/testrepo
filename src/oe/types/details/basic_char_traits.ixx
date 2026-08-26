/**
 * @file basic_char_traits.ixx
 * @brief The internal module for types. Provides char_traits checker details.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/meta/has_member_define.hpp>

export module oe.types.char_traits:basic_char_traits;

import oe.meta;
import oe.types.basic_types;

namespace oe::details {
OE_DEFINE_HAS_TYPE(has_char_type, char_type);
OE_DEFINE_HAS_TYPE(has_int_type, int_type);
OE_DEFINE_HAS_TYPE(has_off_type, off_type);
OE_DEFINE_HAS_TYPE(has_pos_type, pos_type);
OE_DEFINE_HAS_TYPE(has_state_type, state_type);
OE_DEFINE_HAS_FUNCTION_MEMBER(has_eq, eq, bool, typename CheckType::char_type,
                              typename CheckType::char_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_eq_int_type, eq_int_type, bool,
                              typename CheckType::int_type,
                              typename CheckType::int_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_lt, lt, bool, typename CheckType::char_type,
                              typename CheckType::char_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_compare, compare, int,
                              const typename CheckType::char_type*,
                              const typename CheckType::char_type*, oe::usize)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_find, find,
                              const typename CheckType::char_type*,
                              const typename CheckType::char_type*, oe::usize,
                              typename CheckType::char_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_copy, copy, typename CheckType::char_type*,
                              typename CheckType::char_type*,
                              const typename CheckType::char_type*, oe::usize)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_move, move, typename CheckType::char_type*,
                              typename CheckType::char_type*,
                              const typename CheckType::char_type*, oe::usize)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_assign, assign, void,
                              typename CheckType::char_type&,
                              typename CheckType::char_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_assign_n, assign,
                              typename CheckType::char_type*,
                              typename CheckType::char_type*, oe::usize,
                              typename CheckType::char_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_length, length, oe::usize,
                              const typename CheckType::char_type*)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_to_char_type, to_char_type,
                              typename CheckType::char_type,
                              typename CheckType::int_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_to_int_type, to_int_type,
                              typename CheckType::int_type,
                              typename CheckType::char_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_eof, eof, typename CheckType::int_type)
OE_DEFINE_HAS_FUNCTION_MEMBER(has_not_eof, not_eof,
                              typename CheckType::int_type,
                              typename CheckType::int_type)
} // namespace oe::details