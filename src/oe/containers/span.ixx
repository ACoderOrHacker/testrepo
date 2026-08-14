/**
 * @file span.ixx
 * @brief A lightweight, non-owning wrapper for contiguous memory.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.containers.span;

import oe.types.basic_types;
import oe.conv.cast;

export namespace oe {
constexpr inline oe::ssize span_dynamic_size = -1; //!< Mark the `span` as dynamic,
                                                   //!< Enable this, `span` will add a size property
                                                   //!< so that can get a dynamic size view.
                                                   //!< @see oe::span
} // namespace oe

namespace oe::details {
template <typename T, oe::usize Size, bool IsDynamicSpan> struct span_data {
    static_assert(false, "bad span_data call"); // Never get here.
};

/// Span data for fixed-span
template <typename T, oe::usize Size> struct span_data<T, Size, false> {
    constexpr oe::usize m_size = Size; //!< The size of the span.
    T* m_ptr;                          //!< The storage raw pointer.
};

/// Span data for dynamic-size span.
template <typename T, oe::usize Size> struct span_data<T, Size, true> {
    oe::usize m_size; //!< The size of the span.
    T* m_ptr;         //!< The storage raw pointer.
};

/// Checks if the span is dynamic-size.
/// @return True if the span is dynamic, false if the span is fixed-size.
constexpr bool is_dynamic_span(const oe::ssize sz) noexcept { return sz == oe::span_dynamic_size; }
} // namespace oe::details

export namespace oe {

/**
 * @brief A lightweight, non-owning wrapper for contiguous memory.
 *
 * Serves as a safe and convenient alternative to raw pointer (T*) and
 * size_t pairs. Supports range-based iteration, sub-view slicing, and
 * optional bounds checking, full constexpr supports.
 * If you set `size` to `span_dynamic_size`, the `span` will add
 * a `size` attribute to store the dynamic length, and it can accept variable-length data.
 *
 * @see oe::span_dynamic_size
 *
 * @tparam T The span type.
 * @tparam Size The size of the span view.
 */
template <typename T, oe::ssize Size = span_dynamic_size>
struct span : details::span_data<T, oe::cast<oe::usize>(Size), details::is_dynamic_span(Size)> {
    constexpr static bool is_dynamic =
        details::is_dynamic_span(Size); //!< True if the span is a `dynamic` span, false if the span
                                        //!< is fixed size.

    explicit span(T* ptr) noexcept
        requires !is_dynamic
        : m_ptr{ptr} /* , m_size{0} */ {}

    explicit span(T* ptr, const oe::usize size) noexcept
        requires is_dynamic
        : m_ptr{ptr}, m_size{size} {}

  private:
    T* m_ptr;         //!< The storage raw pointer.
    oe::usize m_size; //!< The size of the
};
} // namespace oe
