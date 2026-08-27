/**
 * @file type_sequence.ixx
 * @brief A sequence of multiple types for compile-time reading, usually used in compile-time tags.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.meta.type_sequence;

import oe.base.basic_types;
import oe.base.meta.traits;

// Declaration
export namespace oe {
    template<typename... Types>
    class type_sequence;
}

namespace oe::details {
    template<oe::base::usize I, typename List>
    struct type_of_impl;

    template<oe::base::usize I, typename Head, typename... Tail>
    struct type_of_impl<I, type_sequence<Head, Tail...> > {
        using type = typename type_of_impl<I - 1, type_sequence<Tail...> >::type;
    };

    template<typename Head, typename... Tail>
    struct type_of_impl<0, type_sequence<Head, Tail...> > {
        using type = Head;
    };
} // namespace oe::details

export namespace oe {
    /**
     * @brief The sequence that contains multiple types for compile-time tags.
     *
     * You should give multiple of types, and the result type is a class with the given types.
     * You can access the types by `type_of` with an index of the type. And `has` with a type that needs
     * to check if the type is available in current `type_sequence`.
     *
     * This structure is usually used for a set of tags of one type, representing different tags by
     * defining several empty structs with different type IDs.
     *
     * @tparam Types The types that `type_sequence` should contain.
     */
    template<typename... Types>
    class type_sequence {
        constexpr static oe::base::usize size = sizeof...(Types);

        template<oe::base::usize idx>
        using type_of = details::type_of_impl<idx, type_sequence>::type;

        // TODO: add `has` implemented by meta foreach
        // TODO: add meta helpers
    };
} // namespace oe
