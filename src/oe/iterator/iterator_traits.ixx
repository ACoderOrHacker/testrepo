/**
 * @file iterator_traits.ixx
 * @brief Traits to access the requirements of the iterator.
 *
 * Provides a `iterator_traits` template to define a trait for the passed iterator.
 * You can create a specialization for the template to create the trait.
 * @code{.cpp}
 * import oe.iterator;
 * import TheUserDefinedIteratorImpl;
 *
 * template <>
 * struct oe::iterator_traits<IteratorYouDefined> {
 *      using difference_type = DiffType;      // The difference type between two iterators.
 *      using value_type = ValueType;          // The value type.
 *      using reference_type = value_type&;    // The reference type to an iterator value.
 *      using kind = oe::iterator_kind::input; // The kind of the iterator.
 * };
 * @endcode
 *
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.iterator.iterator_traits;

import oe.meta;

export namespace oe {
/**
 * @enum iterator_kind
 * @brief Enumerates the possible iterator categories.
 *
 * These correspond to the standard iterator concepts (input, output,
 * forward, bidirectional, random access, contiguous).
 */
enum class iterator_kind {
    input,         //!< Input iterator (read-only, single pass)
    output,        //!< Output iterator (write-only)
    forward,       //!< Forward iterator (multi-pass, read/write)
    bidirectional, //!< Bidirectional iterator (forward + backward)
    random,        //!< Random access iterator (constant-time jumps)
    contiguous     //!< Contiguous iterator (elements in contiguous memory)
};

/**
 * @brief Traits definitions for iterators.
 * Defined by users.
 *
 * Using `iterator_traits_accessor` to access the traits.
 * If you are creating a class iterator, then you just need to define traits inside the class.
 * `iterator_traits_accessor` can correctly recognize them.
 *
 * @see oe::iterator_traits_accessor
 *
 * @par Traits that need to define:
 * - difference_type: The type of the difference between two iterators.
 * - value_type: The type of the value pointed to by the iterator.
 * - reference_type: The type of the reference to the value pointed to by the iterator.
 * - kind (a constexpr variable typed `oe::iterator_kind`): The flags of the
 * iterator.
 *
 */
template <typename> struct iterator_traits {};

/**
 * @brief The checker for the iterator traits.
 *
 * Checks if the iterator traits is available. Although they are not defined, this checker will also
 * not throw a compile-time error but just give the status.
 *
 * @tparam IteratorImpl The implementation of the iterator
 */
template <typename IteratorImpl> struct iterator_traits_checker {
    constexpr static bool has_difference_type_in_impl = requires {
        typename IteratorImpl::difference_type;
    }; //!< Checks if `difference_type` is defined in `IteratorImpl`.

    constexpr static bool has_value_type_in_impl = requires {
        typename IteratorImpl::value_type;
    }; //!< Checks if `value_type` is defined in `IteratorImpl`.

    constexpr static bool has_reference_type_in_impl = requires {
        typename IteratorImpl::reference_type;
    }; //!< Checks if `reference_type` is defined in `IteratorImpl`.

    constexpr static bool has_kind_in_impl = requires {
        requires IteratorImpl::kind == IteratorImpl::kind; // Checks if the `kind`
                                                           // is constexpr.

        { IteratorImpl::kind } -> convertible_to<iterator_kind>;
    };

    constexpr static bool has_difference_type_in_traits = requires {
        typename iterator_traits<IteratorImpl>::difference_type;
    }; //!< Checks if `difference_type` is defined in `iterator_traits<IteratorImpl>`.

    constexpr static bool has_value_type_in_traits = requires {
        typename iterator_traits<IteratorImpl>::value_type;
    }; //!< Checks if `value_type` is defined in `iterator_traits<IteratorImpl>`.

    constexpr static bool has_reference_type_in_traits = requires {
        typename iterator_traits<IteratorImpl>::reference_type;
    }; //!< Checks if `reference_type` is defined in `iterator_traits<IteratorImpl>`.

    constexpr static bool has_kind_in_traits = requires {
        requires iterator_traits<IteratorImpl>::kind ==
                     iterator_traits<IteratorImpl>::kind; // Checks if the `kind`
                                                          // is constexpr.

        { iterator_traits<IteratorImpl>::kind } -> convertible_to<iterator_kind>;
    };

    constexpr static bool has_difference_type =
        has_difference_type_in_impl ||
        has_difference_type_in_traits; //!< Checks if `difference_type` is available to read by
                                       //!< `oe::iterator_traits_accessor`.

    constexpr static bool has_value_type =
        has_value_type_in_impl ||
        has_value_type_in_traits; //!< Checks if `value_type` is available to read by
                                  //!< `oe::iterator_traits_accessor`.

    constexpr static bool has_reference_type =
        has_reference_type_in_impl ||
        has_reference_type_in_traits; //!< Checks if `reference_type` is available to read by
                                      //!< `oe::iterator_traits_accessor`.

    constexpr static bool has_kind =
        has_kind_in_impl || has_kind_in_traits; //!< Checks if `kind` is available to read by
                                                //!< `oe::iterator_traits_accessor`.
};

/**
 * @brief Accessor for the iterator traits.
 * @warning Don't use `oe::iterator_traits` to access the traits.
 *
 * The accessor of the iterator traits.
 * You can access the following traits:
 * @par Iterator Traits
 * - difference_type: The type of the difference between two iterators.
 * - value_type: The type of the value pointed to by the iterator.
 * - reference_type: The type of the reference to the value pointed to by the iterator.
 * - kind (a constexpr variable typed `oe::iterator_kind`): The flags of the
 * iterator.
 *
 * @see oe::iterator_traits
 *
 *
 * @tparam IteratorImpl The implementation of the iterator
 */
template <typename IteratorImpl> struct iterator_traits_accessor {
  private:
  public:
    static_assert(
        iterator_traits_checker<IteratorImpl>::has_difference_type,
        "No difference_type in either the iterator impl `IteratorImpl` or the "
        "`oe::iterator_traits`. Add `using difference_type = <your-iterator-difference-type>;` in "
        "`oe::iterator_traits<IteratorImpl>` or just in your iterator implementation "
        "`IteratorImpl` to "
        "fix this issue.");

    static_assert(iterator_traits_checker<IteratorImpl>::has_value_type,
                  "No value_type in either the iterator impl `IteratorImpl` or the "
                  "`oe::iterator_traits`. Add `using value_type = <your-iterator-value-type>;` in "
                  "`oe::iterator_traits<IteratorImpl>` or just in your iterator implementation "
                  "`IteratorImpl` to "
                  "fix this issue.");

    static_assert(
        iterator_traits_checker<IteratorImpl>::has_reference_type,
        "No reference_type in either the iterator impl `IteratorImpl` or the "
        "`oe::iterator_traits`. Add `using reference_type = <your-iterator-reference-type>;` in "
        "`oe::iterator_traits<IteratorImpl>` or just in your iterator implementation "
        "`IteratorImpl` to "
        "fix this issue.");

    static_assert(iterator_traits_checker<IteratorImpl>::has_kind,
                  "No iterator_kind in either the iterator impl `IteratorImpl` or the "
                  "`oe::iterator_traits`. Add `constexpr static oe::iterator_kind kind = "
                  "<your-iterator-kind>;` in "
                  "`oe::iterator_traits<IteratorImpl>` or just in your iterator implementation "
                  "`IteratorImpl` to "
                  "fix this issue. And make SURE `kind` is constexpr.");

    using difference_type =
        oe::conditional_t<iterator_traits_checker<IteratorImpl>::has_difference_type_in_impl,
                          typename IteratorImpl::difference_type,
                          typename iterator_traits<IteratorImpl>::difference_type>;

    using value_type =
        oe::conditional_t<iterator_traits_checker<IteratorImpl>::has_value_type_in_impl,
                          typename IteratorImpl::value_type,
                          typename iterator_traits<IteratorImpl>::value_type>;
    using reference_type =
        oe::conditional_t<iterator_traits_checker<IteratorImpl>::has_reference_type_in_impl,
                          typename IteratorImpl::reference_type,
                          typename iterator_traits<IteratorImpl>::reference_type>;

    constexpr static oe::iterator_kind kind =
        iterator_traits_checker<IteratorImpl>::has_kind_in_impl
            ? IteratorImpl::kind
            : iterator_traits<IteratorImpl>::kind;
};
} // namespace oe
