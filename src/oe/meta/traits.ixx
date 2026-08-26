/**
 * @file traits.ixx
 * @brief The OE traits for meta library, requires C++11 or newer
 * @note See cppreference for deprecated traits. All the deprecated traits at
 * your standard will not define.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
module;

#include <type_traits>
#include <utility>
#include <oe/detections.h>

#if OE_CPP_STANDARD < OE_CPP11_ID
#error "oe.meta.traits only supports C++11 or newer"
#endif

export module oe.meta.traits;

export namespace oe {
using std::integral_constant;

#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::bool_constant;
#endif
using std::false_type;
using std::true_type;

// primary type categories
using std::is_array;
using std::is_class;
using std::is_enum;
using std::is_floating_point;
using std::is_function;
using std::is_integral;
using std::is_lvalue_reference;
using std::is_member_function_pointer;
using std::is_member_object_pointer;
using std::is_null_pointer;
using std::is_pointer;
using std::is_rvalue_reference;
using std::is_union;
using std::is_void;

// composite type categories
using std::is_arithmetic;
using std::is_compound;
using std::is_fundamental;
using std::is_member_pointer;
using std::is_object;
using std::is_reference;
using std::is_scalar;

// type properties
using std::is_abstract;
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::is_aggregate;
#endif
#if OE_CPP_STANDARD < OE_CPP20_ID
using std::is_pod;
#endif
using std::is_const;
using std::is_empty;
#if OE_CPP_STANDARD < OE_CPP17_ID
using std::is_literal_type;
#endif
#if OE_CPP_STANDARD >= OE_CPP17_ID && OE_CPP_STANDARD <= OE_CPP26_ID
using std::is_trivial;
#endif
#if OE_CPP_STANDARD >= OE_CPP14_ID
using std::is_final;
#endif
using std::is_polymorphic;
using std::is_standard_layout;
#if OE_CPP_STANDARD >= OE_CPP23_ID
using std::is_implicit_lifetime;
#endif
using std::is_trivially_copyable;
using std::is_volatile;

#if OE_CPP_STANDARD >= OE_CPP20_ID
using std::is_bounded_array;
using std::is_unbounded_array;
#endif
#if OE_CPP_STANDARD >= OE_CPP23_ID
using std::is_scoped_enum;
#endif
using std::is_signed;
using std::is_unsigned;

using std::is_assignable;
using std::is_constructible;
using std::is_copy_assignable;
using std::is_copy_constructible;
using std::is_default_constructible;
using std::is_destructible;
using std::is_move_assignable;
using std::is_move_constructible;
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::is_swappable;
using std::is_swappable_with;
#endif
using std::is_trivially_assignable;
using std::is_trivially_constructible;
using std::is_trivially_copy_assignable;
using std::is_trivially_copy_constructible;
using std::is_trivially_default_constructible;
using std::is_trivially_destructible;
using std::is_trivially_move_assignable;
using std::is_trivially_move_constructible;

using std::is_nothrow_assignable;
using std::is_nothrow_constructible;
using std::is_nothrow_copy_assignable;
using std::is_nothrow_copy_constructible;
using std::is_nothrow_default_constructible;
using std::is_nothrow_destructible;
using std::is_nothrow_move_assignable;
using std::is_nothrow_move_constructible;
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::is_nothrow_swappable;
using std::is_nothrow_swappable_with;
#endif

using std::has_virtual_destructor;

#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::has_unique_object_representations;
#endif

#if OE_CPP_STANDARD >= OE_CPP23_ID
using std::reference_constructs_from_temporary;
using std::reference_converts_from_temporary;
#endif
// type property queries
using std::alignment_of;
using std::extent;
using std::rank;

// type relations
using std::is_base_of;
using std::is_convertible;
#if OE_CPP_STANDARD >= OE_CPP20_ID
using std::is_layout_compatible;
using std::is_nothrow_convertible;
using std::is_pointer_interconvertible_base_of;
#endif
using std::is_same;
#if OE_CPP_STANDARD >= OE_CPP26_ID
using std::is_virtual_base_of;
#endif

#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::is_invocable;
using std::is_invocable_r;

using std::is_nothrow_invocable;
using std::is_nothrow_invocable_r;
#endif

// const-volatile modifications
using std::add_const;
using std::add_cv;
using std::add_volatile;
using std::remove_const;
using std::remove_cv;
using std::remove_volatile;

#if OE_CPP_STANDARD >= OE_CPP14_ID
using std::add_const_t;
using std::add_cv_t;
using std::add_volatile_t;
using std::remove_const_t;
using std::remove_cv_t;
using std::remove_volatile_t;
#endif

// reference modifications
using std::add_lvalue_reference;
using std::add_rvalue_reference;
using std::remove_reference;

#if OE_CPP_STANDARD >= OE_CPP14_ID
using std::add_lvalue_reference_t;
using std::add_rvalue_reference_t;
using std::remove_reference_t;
#endif

// sign modifications
using std::make_signed;
using std::make_unsigned;

#if OE_CPP_STANDARD >= OE_CPP14_ID
using std::make_signed_t;
using std::make_unsigned_t;
#endif

// array modifications
using std::remove_all_extents;
using std::remove_extent;

#if OE_CPP_STANDARD >= OE_CPP14_ID
using std::remove_all_extents_t;
using std::remove_extent_t;
#endif

// Pointer modifications
using std::add_pointer;
using std::remove_pointer;

#if OE_CPP_STANDARD >= OE_CPP14_ID
using std::add_pointer_t;
using std::remove_pointer_t;
#endif

// other transformations
#if OE_CPP_STANDARD < OE_CPP23_ID
using std::aligned_storage;
using std::aligned_union;
#endif
#if OE_CPP_STANDARD >= OE_CPP14_ID && OE_CPP_STANDARD < OE_CPP23_ID
using std::aligned_storage_t;
using std::aligned_union_t;
#endif
#if OE_CPP_STANDARD >= OE_CPP20_ID
using std::basic_common_reference;
using std::common_reference;
#endif
using std::common_type;
using std::conditional;
using std::decay;
using std::enable_if;
#if OE_CPP_STANDARD < OE_CPP17_ID
using std::result_of;
#endif
#if OE_CPP_STANDARD >= OE_CPP14_ID && OE_CPP_STANDARD < OE_CPP17_ID
using std::result_of_t;
#endif
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::invoke_result;
using std::invoke_result_t;
using std::void_t;
#endif
#if OE_CPP_STANDARD >= OE_CPP20_ID
using std::common_reference_t;
using std::remove_cvref;
using std::remove_cvref_t;
using std::type_identity;
using std::type_identity_t;
using std::unwrap_ref_decay;
using std::unwrap_ref_decay_t;
using std::unwrap_reference;
using std::unwrap_reference_t;
#endif
using std::underlying_type;

#if OE_CPP_STANDARD >= OE_CPP14_ID
using std::common_type_t;
using std::conditional_t;
using std::decay_t;
using std::enable_if_t;
using std::underlying_type_t;
#endif

// logical operator traits
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::conjunction;
using std::disjunction;
using std::negation;
#endif

// primary type categories
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::is_array_v;
using std::is_class_v;
using std::is_enum_v;
using std::is_floating_point_v;
using std::is_function_v;
using std::is_integral_v;
using std::is_lvalue_reference_v;
using std::is_member_function_pointer_v;
using std::is_member_object_pointer_v;
using std::is_null_pointer_v;
using std::is_pointer_v;
using std::is_rvalue_reference_v;
using std::is_union_v;
using std::is_void_v;
#endif

// composite type categories
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::is_arithmetic_v;
using std::is_compound_v;
using std::is_fundamental_v;
using std::is_member_pointer_v;
using std::is_object_v;
using std::is_reference_v;
using std::is_scalar_v;
#endif

// type properties
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::has_unique_object_representations_v;
using std::is_abstract_v;
using std::is_aggregate_v;
using std::is_const_v;
using std::is_empty_v;
using std::is_final_v;
#endif

using std::is_assignable_v;
#if OE_CPP_STANDARD >= OE_CPP20_ID
using std::is_bounded_array_v;
using std::is_unbounded_array_v;
#endif
#if OE_CPP_STANDARD < OE_CPP20_ID
using std::is_pod_v;
#endif
#if OE_CPP_STANDARD >= OE_CPP17_ID && OE_CPP_STANDARD < OE_CPP17_ID
using std::is_literal_type_v;
#endif

#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::has_virtual_destructor_v;
using std::is_constructible_v;
using std::is_copy_assignable_v;
using std::is_copy_constructible_v;
using std::is_default_constructible_v;
using std::is_destructible_v;
using std::is_move_assignable_v;
using std::is_move_constructible_v;
using std::is_nothrow_assignable_v;
using std::is_nothrow_constructible_v;
using std::is_nothrow_copy_assignable_v;
using std::is_nothrow_copy_constructible_v;
using std::is_nothrow_default_constructible_v;
using std::is_nothrow_destructible_v;
using std::is_nothrow_move_assignable_v;
using std::is_nothrow_move_constructible_v;
using std::is_nothrow_swappable_v;
using std::is_nothrow_swappable_with_v;
using std::is_polymorphic_v;
using std::is_signed_v;
using std::is_standard_layout_v;
using std::is_swappable_v;
using std::is_swappable_with_v;
using std::is_unsigned_v;
#endif
#if OE_CPP_STANDARD >= OE_CPP23_ID
using std::is_implicit_lifetime_v;
using std::is_scoped_enum_v;
#endif

#if OE_CPP_STANDARD >= OE_CPP17_ID && OE_CPP_STANDARD <= OE_CPP26_ID
using std::is_trivial_v;
#endif
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::is_trivially_assignable_v;
using std::is_trivially_constructible_v;
using std::is_trivially_copy_assignable_v;
using std::is_trivially_copy_constructible_v;
using std::is_trivially_copyable_v;
using std::is_trivially_default_constructible_v;
using std::is_trivially_destructible_v;
using std::is_trivially_move_assignable_v;
using std::is_trivially_move_constructible_v;
#endif

using std::is_volatile_v;
#if OE_CPP_STANDARD >= OE_CPP23_ID
using std::reference_constructs_from_temporary_v;
using std::reference_converts_from_temporary_v;
#endif

// type property queries
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::alignment_of_v;
using std::extent;
using std::rank_v;
#endif

// type relations
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::is_base_of_v;
using std::is_convertible_v;
using std::is_invocable_r_v;
using std::is_invocable_v;
using std::is_nothrow_invocable_r_v;
using std::is_nothrow_invocable_v;
using std::is_same_v;
#endif
#if OE_CPP_STANDARD >= OE_CPP20_ID
using std::is_layout_compatible_v;
using std::is_nothrow_convertible_v;
using std::is_pointer_interconvertible_base_of_v;
#endif
#if OE_CPP_STANDARD >= OE_CPP26_ID
using std::is_virtual_base_of_v;
#endif

// logical operator traits
#if OE_CPP_STANDARD >= OE_CPP17_ID
using std::conjunction_v;
using std::disjunction_v;
using std::negation_v;
#endif

// member relationships
// FIXME: Doesn't work on clang with Microsoft STL
#if OE_CPP_STANDARD >= OE_CPP20_ID &&                                          \
    (OE_COMPILER_SINGLE != OE_COMPILER_CLANG && OE_HAS_MSVC_COMPILER_ID)
using std::is_corresponding_member;
using std::is_pointer_interconvertible_with_class;
#endif

// constant evaluation context

#if OE_CPP_STANDARD >= OE_CPP20_ID
using std::is_constant_evaluated;
#endif
#if OE_CPP_STANDARD >= OE_CPP26_ID
using std::is_within_lifetime;
#endif

using std::declval;
} // namespace oe
