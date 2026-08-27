/**
 * @file iterator_wrapper.ixx
 * @brief A modern C++20 iterator library with concepts and a generic wrapper.
 *
 * This library defines a set of concepts to detect iterator operations,
 * an enumeration for iterator categories, a sentinel type, and a generic
 * `iterator` class. This template that wraps a user-provided implementation and
 * automatically provides all standard operators based on the supported operations.
 *
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.iterator.iterator_wrapper;

import oe.meta;
import oe.types;
import oe.base.cast;
import oe.iterator.iterator_traits;

export namespace oe {
/**
 * @brief Sentinel type used to mark the end of a range.
 *
 * A `sentinel` object can be compared with an iterator to check for
 * termination. It does not provide any iterator operations.
 */
struct sentinel {};

/**
 * @concept has_iterator_data
 * @brief Checks that an iterator provides `data()` for reading the current element.
 *
 * Requires both const and non-const overloads of `data()` with non-const override to exist and
 * return a reference to the value type (const for const, non‑const for non‑const).
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_data = requires(T& t) {
    { t.data() } -> convertible_to<typename iterator_traits_accessor<T>::reference_type>;
};

/**
 * @concept has_iterator_cdata
 * @brief Checks that an iterator provides `data()` with const override for reading the current
 * element.
 *
 * Requires both const and non-const overloads of `data()` to exist and
 * return a reference to the value type (const for const, non‑const for non‑const).
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_cdata =
    iterator_traits_checker<T>::has_reference_type && requires(const T& ct) {
        { ct.data() } -> convertible_to<const typename iterator_traits_accessor<T>::reference_type>;
    };

/**
 * @concept has_iterator_set
 * @brief Checks that an iterator provides `set()` to assign a value to the current element.
 *
 * This is the write operation, typically available only for non‑const iterators.
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_set = iterator_traits_checker<T>::has_value_type &&
                           requires(T& t, const typename T::value_type& v) { t.set(v); };

/**
 * @concept has_iterator_next
 * @brief Checks that an iterator provides a single‑step `next()` operation.
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_next = requires(T& t) { t.next(); };

/**
 * @concept has_iterator_next_n
 * @brief Checks that an iterator provides a multi‑step `next(n)` operation.
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_next_n = requires(T& t, usize n) { t.next(n); };

/**
 * @concept has_iterator_prev
 * @brief Checks that an iterator provides a single‑step `prev()` operation.
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_prev = requires(T& t) { t.prev(); };

/**
 * @concept has_iterator_prev_n
 * @brief Checks that an iterator provides a multi‑step `prev(n)` operation.
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_prev_n = requires(T& t, usize n) { t.prev(n); };

/**
 * @concept has_iterator_distance_to
 * @brief Checks that an iterator can compute the distance to another iterator efficiently.
 *
 * The `distance_to(other)` method should return a signed difference type.
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_distance_to = requires(const T& a, const T& b) {
    { a.distance_to(b) } -> convertible_to<ssize>;
};

/**
 * @concept has_iterator_equal
 * @brief Checks that an iterator supports equality comparison via `equal_to()`.
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_equal = requires(const T& a, const T& b) {
    { a.equal_to(b) } -> convertible_to<bool>;
};

template <typename T>
concept has_iterator_equal_with_sentinel = requires(const T& a) {
    { a.equal_to(sentinel{}) } -> convertible_to<bool>;
};

/**
 * @concept has_iterator_lt
 * @brief Checks that an iterator supports ordering via `less_than()`.
 * @tparam T The iterator type.
 */
template <typename T>
concept has_iterator_lt = requires(const T& a, const T& b) {
    { a.less_than(b) } -> convertible_to<bool>;
};

/**
 * @concept is_input_iterator
 * @brief Defines the requirements for an input iterator.
 *
 * An input iterator must provide read access (`data()` with const or non-const override) and
 * single‑step forward movement (`next()`).
 * @tparam T The iterator type.
 */
template <typename T>
concept is_input_iterator = (has_iterator_data<T> || has_iterator_cdata<T>) && has_iterator_next<T>;

/**
 * @concept is_output_iterator
 * @brief Defines the requirements for an output iterator.
 *
 * An output iterator only needs to support write access (`set()`).
 * @tparam T The iterator type.
 */
template <typename T>
concept is_output_iterator = has_iterator_set<T>;

/**
 * @concept is_forward_iterator
 * @brief Defines the requirements for a forward iterator.
 *
 * A forward iterator is an input iterator that also supports multi‑step
 * forward movement (`next(n)`).
 * @tparam T The iterator type.
 */
template <typename T>
concept is_forward_iterator = is_input_iterator<T>;

/**
 * @concept is_bidirectional_iterator
 * @brief Defines the requirements for a bidirectional iterator.
 *
 * A bidirectional iterator is a forward iterator that also supports
 * backward movement (`prev()` and `prev(n)`).
 * @tparam T The iterator type.
 */
template <typename T>
concept is_bidirectional_iterator =
    is_forward_iterator<T> && has_iterator_prev<T> && has_iterator_prev_n<T>;

/**
 * @concept is_random_access_iterator
 * @brief Defines the requirements for a random‑access iterator.
 *
 * A random‑access iterator is a bidirectional iterator that also supports
 * ordering (`less_than`) and efficient distance computation (`distance_to`).
 * @tparam T The iterator type.
 */
template <typename T>
concept is_random_access_iterator =
    is_bidirectional_iterator<T> && has_iterator_lt<T> && has_iterator_distance_to<T>;

/**
 * @concept is_contiguous_iterator
 * @brief Defines the requirements for a contiguous iterator.
 *
 * @see iterator_kind
 *
 * A contiguous iterator is a random‑access iterator that additionally
 * provides a kind `contiguous` in `oe::iterator_kind` to indicate that elements are
 * stored contiguously in memory.
 * @tparam T The iterator type.
 */
template <typename T>
concept is_contiguous_iterator =
    is_random_access_iterator<T> && iterator_traits_checker<T>::has_kind &&
    (iterator_traits_accessor<T>::kind == iterator_kind::contiguous);

/**
 * @brief A generic iterator wrapper that adapts a user‑provided implementation.
 *
 * This class template takes an implementation type `Impl`. It statically asserts that the
 * implementation satisfies the required concept for that category. It then provides all standard
 * iterator operators (dereference, increment, decrement, arithmetic, comparison, subscript) by
 * delegating to the underlying implementation. If an efficient operation (e.g., `next(n)`) is
 * missing, it falls back to a loop of single steps.
 *
 * @tparam Impl The user‑provided iterator implementation type.
 */
template <typename Impl> class iterator {
  public:
    constexpr static iterator_kind kind =
        iterator_traits_accessor<Impl>::kind; //!< The kind of the itertor implementation.
    using value_type =
        iterator_traits_accessor<Impl>::value_type; //!< The value type of the elements.
    using difference_type =
        iterator_traits_accessor<Impl>::difference_type; //!< Signed difference type.
    using reference_type =
        iterator_traits_accessor<Impl>::reference_type; //!< The reference type of the elements.
  public:
    // Ensure that the implementation satisfies the required concept.
    static_assert((kind == iterator_kind::input)           ? is_input_iterator<Impl>
                  : (kind == iterator_kind::output)        ? is_output_iterator<Impl>
                  : (kind == iterator_kind::forward)       ? is_forward_iterator<Impl>
                  : (kind == iterator_kind::bidirectional) ? is_bidirectional_iterator<Impl>
                  : (kind == iterator_kind::random)        ? is_random_access_iterator<Impl>
                  : (kind == iterator_kind::contiguous)    ? is_contiguous_iterator<Impl>
                                                           : true,
                  "Iterator Implementation `Impl` does not satisfy the required iterator concept "
                  "for the given iterator_kind.");

    /**
     * @brief Default constructor. Default‑initialises the implementation.
     */
    constexpr iterator() = default;

    /**
     * @brief Constructs an iterator from a given implementation object.
     * @param impl The implementation object to wrap.
     */
    constexpr explicit iterator(Impl impl) : m_impl(base::to_xvalue(impl)) {}

    /**
     * @brief Returns a const reference to the underlying implementation.
     * @return const reference to the implementation.
     */
    constexpr const Impl& base() const noexcept { return m_impl; }

    /**
     * @brief Returns a mutable reference to the underlying implementation.
     * @return mutable reference to the implementation.
     */
    constexpr Impl& base() noexcept { return m_impl; }

    // ---------- data (operator*) ----------

    /**
     * @brief Reads the current element (const overload).
     * @return A reference (possibly const) to the current element.
     * @pre The implementation provides `data()` that is callable on const.
     */
    constexpr decltype(auto) data() const
        requires requires(const Impl& i) { i.data(); }
    {
        return m_impl.data();
    }

    /**
     * @brief Reads the current element (non‑const overload).
     * @return A reference to the current element.
     * @pre The implementation provides `data()` that is callable on non‑const.
     */
    constexpr decltype(auto) data()
        requires requires(Impl& i) { i.data(); }
    {
        return m_impl.data();
    }

    /**
     * @brief Dereference operator (const overload).
     * @return A reference to the current element (read‑only).
     * @pre The implementation provides `data()`.
     */
    constexpr decltype(auto) operator*() const
        requires requires(const Impl& i) { i.data(); }
    {
        return data();
    }

    /**
     * @brief Dereference operator (non‑const overload).
     * @return A reference to the current element (read/write).
     * @pre The implementation provides `data()`.
     */
    constexpr decltype(auto) operator*()
        requires requires(Impl& i) { i.data(); }
    {
        return data();
    }

    // ---------- set (write) ----------

    /**
     * @brief Assigns a value to the current element.
     * @param v The value to write.
     * @pre The implementation provides `set()`.
     */
    constexpr void set(const value_type& v)
        requires requires(Impl& i, const value_type& val) { i.set(val); }
    {
        m_impl.set(v);
    }

    // ---------- next() ----------

    /**
     * @brief Advances the iterator by one position.
     * @return Reference to `*this`.
     * @pre The implementation provides `next()`.
     */
    constexpr iterator& next()
        requires requires(Impl& i) { i.next(); }
    {
        m_impl.next();
        return *this;
    }

    /**
     * @brief Pre‑increment operator.
     * @return Reference to `*this` after advancing.
     * @pre The implementation provides `next()`.
     */
    constexpr iterator& operator++()
        requires requires(Impl& i) { i.next(); }
    {
        next();
        return *this;
    }

    /**
     * @brief Post‑increment operator.
     * @return A copy of the iterator before advancement.
     * @pre The implementation provides `next()`.
     */
    constexpr iterator operator++(int)
        requires requires(Impl& i) { i.next(); }
    {
        auto tmp = *this;
        next();
        return tmp;
    }

    // ---------- next(n) ----------

    /**
     * @brief Advances the iterator by `n` positions.
     *
     * If the implementation provides `next(n)`, it is used; otherwise,
     * `next()` is called in a loop.
     * @param n Number of positions to advance (must be non‑negative).
     * @return Reference to `*this`.
     */
    constexpr iterator& advance(usize n) {
        if constexpr (has_iterator_next_n<Impl>) {
            m_impl.next(n);
        } else {
            for (usize i = 0; i < n; ++i)
                m_impl.next();
        }
        return *this;
    }

    /**
     * @brief Returns a copy of the iterator advanced by `n` positions.
     * @param n Number of steps forward.
     * @return A new iterator advanced by `n`.
     */
    constexpr iterator operator+(usize n) const {
        auto copy = *this;
        copy.advance(n);
        return copy;
    }

    /**
     * @brief Advances the iterator by `n` positions and returns reference.
     * @param n Number of steps forward.
     * @return Reference to `*this`.
     */
    constexpr iterator& operator+=(const usize n) { return advance(n); }

    // ---------- prev() ----------

    /**
     * @brief Moves the iterator backward by one position.
     * @return Reference to `*this`.
     * @pre The implementation provides `prev()`.
     */
    constexpr iterator& prev()
        requires requires(Impl& i) { i.prev(); }
    {
        m_impl.prev();
        return *this;
    }

    /**
     * @brief Pre‑decrement operator.
     * @return Reference to `*this` after moving backward.
     * @pre The implementation provides `prev()`.
     */
    constexpr iterator& operator--()
        requires requires(Impl& i) { i.prev(); }
    {
        prev();
        return *this;
    }

    /**
     * @brief Post‑decrement operator.
     * @return A copy of the iterator before moving backward.
     * @pre The implementation provides `prev()`.
     */
    constexpr iterator operator--(int)
        requires requires(Impl& i) { i.prev(); }
    {
        auto tmp = *this;
        prev();
        return tmp;
    }

    // ---------- prev(n) ----------

    /**
     * @brief Moves the iterator backward by `n` positions.
     *
     * If the implementation provides `prev(n)`, it is used; otherwise,
     * `prev()` is called in a loop.
     * @param n Number of positions to move backward.
     * @return Reference to `*this`.
     */
    constexpr iterator& retreat(usize n) {
        if constexpr (has_iterator_prev_n<Impl>) {
            m_impl.prev(n);
        } else {
            for (usize i = 0; i < n; ++i)
                m_impl.prev();
        }
        return *this;
    }

    /**
     * @brief Returns a copy of the iterator moved backward by `n` positions.
     * @param n Number of steps backward.
     * @return A new iterator moved backward by `n`.
     */
    constexpr iterator operator-(usize n) const {
        auto copy = *this;
        copy.retreat(n);
        return copy;
    }

    /**
     * @brief Moves the iterator backward by `n` positions and returns reference.
     * @param n Number of steps backward.
     * @return Reference to `*this`.
     */
    constexpr iterator& operator-=(const usize n) { return retreat(n); }

    // ---------- equal_to ----------

    /**
     * @brief Checks equality with another iterator.
     * @param other The other iterator to compare with.
     * @return `true` if both iterators point to the same position, `false` otherwise.
     * @pre The implementation provides `equal_to()`.
     */
    constexpr bool equal_to(const iterator& other) const
        requires requires(const Impl& a, const Impl& b) { a.equal_to(b); }
    {
        return m_impl.equal_to(other.m_impl);
    }

    /**
     * @brief Checks equality with the sentinel.
     * @param sentinel The sentinel to compare
     * @return `true` if both iterators point to the same position, `false` otherwise.
     * @pre The implementation provides `equal_to()`.
     */
    [[nodiscard]] constexpr bool equal_to(const sentinel sentinel) const
        requires requires(const Impl& a) { a.equal_to(sentinel); }
    {
        return m_impl.equal_to(sentinel);
    }

    /**
     * @brief Equality operator.
     * @param other The other iterator.
     * @return `true` if equal, `false` otherwise.
     * @pre The implementation provides `equal_to()`.
     */
    constexpr bool operator==(const iterator& other) const
        requires requires(const Impl& a, const Impl& b) { a.equal_to(b); }
    {
        return equal_to(other);
    }

    /**
     * @brief Equality operator.
     * @param sentinel The sentinel placeholder.
     * @return `true` if equal, `false` otherwise.
     * @pre The implementation provides `equal_to()`.
     */
    constexpr bool operator==(const sentinel sentinel) const
        requires requires(const Impl& a) { a.equal_to(sentinel); }
    {
        return equal_to(sentinel);
    }

    /**
     * @brief Inequality operator.
     * @param other The other iterator.
     * @return `true` if not equal, `false` otherwise.
     * @pre The implementation provides `equal_to()`.
     */
    constexpr bool operator!=(const iterator& other) const
        requires requires(const Impl& a, const Impl& b) { a.equal_to(b); }
    {
        return !(*this == other);
    }

    // ---------- less_than ----------

    /**
     * @brief Checks if this iterator is less than another.
     * @param other The other iterator.
     * @return `true` if this comes before `other`, `false` otherwise.
     * @pre The implementation provides `less_than()`.
     */
    constexpr bool less_than(const iterator& other) const
        requires requires(const Impl& a, const Impl& b) { a.less_than(b); }
    {
        return m_impl.less_than(other.m_impl);
    }

    /**
     * @brief Less‑than operator.
     * @param other The other iterator.
     * @return `true` if this < other, `false` otherwise.
     * @pre The implementation provides `less_than()`.
     */
    constexpr bool operator<(const iterator& other) const
        requires requires(const Impl& a, const Impl& b) { a.less_than(b); }
    {
        return less_than(other);
    }

    /**
     * @brief Greater‑than operator.
     * @param other The other iterator.
     * @return `true` if this > other, `false` otherwise.
     * @pre The implementation provides `less_than()`.
     */
    constexpr bool operator>(const iterator& other) const
        requires requires(const Impl& a, const Impl& b) { a.less_than(b); }
    {
        return other < *this;
    }

    /**
     * @brief Less‑than‑or‑equal operator.
     * @param other The other iterator.
     * @return `true` if this <= other, `false` otherwise.
     * @pre The implementation provides `less_than()` and `equal_to`.
     */
    constexpr bool operator<=(const iterator& other) const
        requires requires(const Impl& a, const Impl& b) { a.less_than(b); }
    {
        return !(other > *this);
    }

    /**
     * @brief Greater‑than‑or‑equal operator.
     * @param other The other iterator.
     * @return `true` if this >= other, `false` otherwise.
     * @pre The implementation provides `less_than()`.
     */
    constexpr bool operator>=(const iterator& other) const
        requires requires(const Impl& a, const Impl& b) { a.less_than(b); }
    {
        return !(*this < other);
    }

    // ---------- distance ----------

    /**
     * @brief Computes the distance from this iterator to another.
     *
     * If the implementation provides `distance_to()`, it is used.
     * Otherwise, it counts steps by repeated increment (O(n) complexity).
     * @param other The target iterator.
     * @return The number of positions from `*this` to `other` (signed).
     */
    constexpr ssize distance_to(const iterator& other) const {
        if constexpr (has_iterator_distance_to<Impl>) {
            return m_impl.distance_to(other.m_impl);
        } else {
            // Default O(n) loop counting
            ssize count = 0;
            auto it = *this;
            while (it != other) {
                ++it;
                ++count;
            }
            return count;
        }
    }

    // ---------- operator[] ----------

    /**
     * @brief Subscript operator for random access.
     * @param n Offset from the current position.
     * @return A reference to the element at offset `n`.
     * @pre The implementation provides `data()` (to read the element after advancing).
     * @note This performs `*(*this + n)` and is only meaningful for random‑access iterators.
     */
    constexpr decltype(auto) operator[](usize n) const
        requires requires(const Impl& i) { i.data(); }
    {
        return *(*this + n);
    }

  private:
    Impl m_impl; //!< The underlying implementation object.
};

/// Specialization for mutable pointer T*
template <typename T> class iterator<T*> {
  public:
    constexpr static iterator_kind kind = iterator_kind::contiguous;
    using value_type = T;
    using difference_type = ssize;
    using reference_type = T&;

    constexpr iterator() = default;
    constexpr explicit iterator(T* p) : m_ptr(p) {}

    constexpr T* base() noexcept { return m_ptr; }
    constexpr const T* base() const noexcept { return m_ptr; }

    constexpr auto& data() noexcept { return *m_ptr; }
    constexpr const auto& data() const noexcept { return *m_ptr; }
    constexpr decltype(auto) operator*() const { return data(); }
    constexpr decltype(auto) operator*() { return data(); }

    constexpr void set(const value_type& v) { *m_ptr = v; }

    constexpr iterator& next() noexcept {
        ++m_ptr;
        return *this;
    }
    constexpr iterator& operator++() noexcept { return next(); }
    constexpr iterator operator++(int) noexcept {
        auto tmp = *this;
        ++m_ptr;
        return tmp;
    }

    constexpr iterator& advance(usize n) noexcept {
        m_ptr += static_cast<difference_type>(n);
        return *this;
    }
    constexpr iterator operator+(usize n) const noexcept {
        iterator copy = *this;
        copy.advance(n);
        return copy;
    }
    constexpr iterator& operator+=(const usize n) noexcept { return advance(n); }

    constexpr iterator& prev() noexcept {
        --m_ptr;
        return *this;
    }
    constexpr iterator& operator--() noexcept { return prev(); }
    constexpr iterator operator--(int) noexcept {
        auto tmp = *this;
        --m_ptr;
        return tmp;
    }

    constexpr iterator& retreat(usize n) noexcept {
        m_ptr -= static_cast<difference_type>(n);
        return *this;
    }
    constexpr iterator operator-(const usize n) const noexcept {
        iterator copy = *this;
        copy.retreat(n);
        return copy;
    }
    constexpr iterator& operator-=(const usize n) noexcept { return retreat(n); }

    constexpr bool equal_to(const iterator& other) const noexcept { return m_ptr == other.m_ptr; }
    [[nodiscard]] constexpr bool equal_to(const sentinel) const noexcept {
        return m_ptr == nullptr;
    }
    constexpr bool operator==(const iterator& other) const noexcept { return equal_to(other); }
    constexpr bool operator==(const sentinel s) const noexcept { return equal_to(s); }
    constexpr bool operator!=(const iterator& other) const noexcept { return !(*this == other); }

    constexpr bool less_than(const iterator& other) const noexcept { return m_ptr < other.m_ptr; }
    constexpr bool operator<(const iterator& other) const noexcept { return less_than(other); }
    constexpr bool operator>(const iterator& other) const noexcept { return other < *this; }
    constexpr bool operator<=(const iterator& other) const noexcept { return !(other > *this); }
    constexpr bool operator>=(const iterator& other) const noexcept { return !(*this < other); }

    constexpr ssize distance_to(const iterator& other) const noexcept {
        return static_cast<ssize>(other.m_ptr - m_ptr);
    }

    constexpr decltype(auto) operator[](usize n) const noexcept {
        return *(m_ptr + static_cast<difference_type>(n));
    }

  private:
    T* m_ptr{nullptr};
};

/// Specialization for const pointer const T*
template <typename T> class iterator<const T*> {
  public:
    constexpr static iterator_kind kind = iterator_kind::contiguous;
    using value_type = T;
    using difference_type = ssize;
    using reference_type = const T&;

    constexpr iterator() = default;
    constexpr explicit iterator(const T* p) : m_ptr(p) {}

    constexpr const T* base() const noexcept { return m_ptr; }

    constexpr reference_type data() const noexcept { return *m_ptr; }
    constexpr decltype(auto) operator*() const { return data(); }

    constexpr iterator& next() noexcept {
        ++m_ptr;
        return *this;
    }
    constexpr iterator& operator++() noexcept { return next(); }
    constexpr iterator operator++(int) noexcept {
        auto tmp = *this;
        ++m_ptr;
        return tmp;
    }

    constexpr iterator& advance(usize n) noexcept {
        m_ptr += static_cast<difference_type>(n);
        return *this;
    }
    constexpr iterator operator+(usize n) const noexcept {
        iterator copy = *this;
        copy.advance(n);
        return copy;
    }
    constexpr iterator& operator+=(const usize n) noexcept { return advance(n); }

    constexpr iterator& prev() noexcept {
        --m_ptr;
        return *this;
    }
    constexpr iterator& operator--() noexcept { return prev(); }
    constexpr iterator operator--(int) noexcept {
        auto tmp = *this;
        --m_ptr;
        return tmp;
    }

    constexpr iterator& retreat(const usize n) noexcept {
        m_ptr -= static_cast<difference_type>(n);
        return *this;
    }
    constexpr iterator operator-(const usize n) const noexcept {
        iterator copy = *this;
        copy.retreat(n);
        return copy;
    }
    constexpr iterator& operator-=(const usize n) noexcept { return retreat(n); }

    constexpr bool equal_to(const iterator& other) const noexcept { return m_ptr == other.m_ptr; }
    [[nodiscard]] constexpr bool equal_to(const sentinel) const noexcept {
        return m_ptr == nullptr;
    }
    constexpr bool operator==(const iterator& other) const noexcept { return equal_to(other); }
    constexpr bool operator==(const sentinel s) const noexcept { return equal_to(s); }
    constexpr bool operator!=(const iterator& other) const noexcept { return !(*this == other); }

    constexpr bool less_than(const iterator& other) const noexcept { return m_ptr < other.m_ptr; }
    constexpr bool operator<(const iterator& other) const noexcept { return less_than(other); }
    constexpr bool operator>(const iterator& other) const noexcept { return other < *this; }
    constexpr bool operator<=(const iterator& other) const noexcept { return !(other > *this); }
    constexpr bool operator>=(const iterator& other) const noexcept { return !(*this < other); }

    constexpr ssize distance_to(const iterator& other) const noexcept {
        return static_cast<ssize>(other.m_ptr - m_ptr);
    }

    constexpr decltype(auto) operator[](usize n) const noexcept {
        return *(m_ptr + static_cast<difference_type>(n));
    }

  private:
    const T* m_ptr{nullptr};
};

/**
 * @brief Computes the distance between two iterators.
 *
 * This is a convenience wrapper around `iterator::distance_to()`.
 * @tparam Impl The implementation type.
 * @param left The first iterator.
 * @param right The second iterator.
 * @return The signed distance from `left` to `right`.
 */
template <typename Impl>
constexpr ssize distance(const iterator<Impl>& left, const iterator<Impl>& right) {
    return left.distance_to(right);
}

} // namespace oe
