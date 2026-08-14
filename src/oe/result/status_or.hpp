/**
 * @file status_or.hpp
 * @brief status_or structure definition
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/oe/api.h>
#include <oe/statusor/status.hpp>
#include <oe/utility.hpp>

namespace oe {
/**
 * @brief Represents a status_or with a value type and status type.
 * @tparam ValueType The type of the value.
 * @tparam StatusType The type of the status.
 */
template <typename ValueType, typename StatusType = default_status> struct OE_API status_or : status<StatusType> {
    static_assert(oe::is_default_constructible_v<ValueType>, "`ValueType` must be default constructible");

    using value_type = ValueType;   //!< The type of the value.
    using status_type = StatusType; //!< The type of the status.
    using status_storage_type =
        typename oe::status<status_type>::status_storage_type; //!< The storage type for the status value.

    constexpr inline static bool is_status_enum = status<status_type>::is_status_enum; //!< Checks if StatusType
                                                                                       //!< has a status enum tag.

    inline status_or() noexcept : status<status_type>{}, m_data{} {}
    inline status_or(value_type&& value) noexcept : status<status_type>{}, m_data{value} {}
    inline status_or(const status<status_type>& value) noexcept : status<status_type>{value}, m_data{} {}
    inline status_or(status<status_type>&& value) noexcept : status<status_type>{std::move(value)}, m_data{} {}
    inline status_or(const value_type& value) noexcept : status<status_type>{}, m_data{value} {}

    inline status_or(const status_or& other) noexcept = default;
    inline status_or(status_or&& other) noexcept = default;

    /**
     * @brief Assigns the status value from another status.
     * @param other The status to assign from.
     * @return A reference to this status.
     */
    inline status_or& operator=(const status_or& other) noexcept = default;

    /**
     * @brief Move-assigns the status value from another status.
     * @param other The status to move-assign from.
     * @return A reference to this status.
     */
    inline status_or& operator=(status_or&& other) noexcept = default;

    /**
     * @brief Returns a reference to the value of the status_or.
     * @pre is_ok() or the function will panic
     * @param msg The panic message
     * @return A reference to the value of the status_or.
     */
    inline value_type& expect(const char* msg) & noexcept {
        if (this->is_err())
            panic(msg);
        return m_data;
    }

    /**
     * @brief Returns a reference to the value of the status_or.
     * @pre is_ok() or the function will panic
     * @param msg The panic message
     * @return A reference to the value of the status_or.
     */
    inline value_type expect(const char* msg) && noexcept {
        if (this->is_err())
            panic(msg);
        return m_data;
    }

    /**
     * @brief Returns a reference to the value of the status_or.
     * @pre is_ok() or the function will panic
     * @param msg The panic message
     * @return A reference to the value of the status_or.
     */
    inline const value_type& expect(const char* msg) const& noexcept {
        if (this->is_err())
            panic(msg);
        return m_data;
    }

    /**
     * @brief Returns a reference to the value of the status_or.
     * @pre is_ok() or the function will panic
     * @param msg The panic message
     * @return A reference to the value of the status_or.
     */
    inline value_type expect(const char* msg) const&& noexcept {
        if (this->is_err())
            panic(msg);
        return m_data;
    }

    /**
     * @brief Returns the status(error) of the status_or.
     * @pre is_err() or the function will panic
     * @param msg The panic message
     * @return A status(error) of the status_or.
     */
    inline status_storage_type expect_err(const char* msg) const noexcept {
        if (this->is_ok())
            panic(msg);
        return this->error();
    }

    /**
     * @brief Returns a reference to the value of the status_or.
     * @pre is_ok() or the function will panic
     * @return A reference to the value of the status_or.
     */
    inline const value_type& unwrap() const& noexcept {
        if (this->is_err())
            panic("Attempt to access value of an error status_or");
        return m_data;
    }

    /**
     * @brief Returns a reference to the value of the status_or.
     * @pre is_ok() or the function will panic
     * @return A reference to the value of the status_or.
     */
    inline value_type unwrap() const&& noexcept {
        if (this->is_err())
            panic("Attempt to access value of an error status_or");
        return m_data;
    }

    /**
     * @brief Returns a reference to the value of the status_or.
     * @pre is_ok() or the function will panic
     * @return A reference to the value of the status_or.
     */
    inline value_type& unwrap() & noexcept {
        if (this->is_err())
            panic("Attempt to access value of an error status_or");
        return m_data;
    }

    /**
     * @brief Returns a reference to the value of the status_or.
     * @pre is_ok() or the function will panic
     * @return A reference to the value of the status_or.
     */
    inline value_type unwrap() && noexcept {
        if (this->is_err())
            panic("Attempt to access value of an error status_or");
        return m_data;
    }

    /**
     * @brief Returns the status(error) of the status_or.
     * @pre is_err() or the function will panic
     * @return A status(error) of the status_or.
     */
    inline status_storage_type unwrap_err() noexcept {
        if (this->is_ok())
            panic("Attempt to access the error of a ok status");
        return this->error();
    }

    /**
     * @brief Evaluate the function if is_ok() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_err() or the new
     * status_or processed by the function if is_ok()
     */
    template <typename F> inline auto and_then(F&& func) const& noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_ok() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_err() or the new
     * status_or processed by the function if is_ok()
     */
    template <typename F> inline auto and_then(F&& func) & noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_ok() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_err() or the new
     * status_or processed by the function if is_ok()
     */
    template <typename F> inline auto and_then(F&& func) const&& noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_ok() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_err() or the new
     * status_or processed by the function if is_ok()
     */
    template <typename F> inline auto and_then(F&& func) && noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_err() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_ok() or the new
     * status_or processed by the function if is_err()
     */
    template <typename F> inline auto or_else(F&& func) const& noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_err() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_ok() or the new
     * status_or processed by the function if is_err()
     */
    template <typename F> inline auto or_else(F&& func) & noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_err() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_ok() or the new
     * status_or processed by the function if is_err()
     */
    template <typename F> inline auto or_else(F&& func) const&& noexcept {
        if (is_err())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_err() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_ok() or the new
     * status_or processed by the function if is_err()
     */
    template <typename F> inline auto or_else(F&& func) && noexcept {
        if (is_err())
            return func(*this);
        return *this;
    }

    /**
     * @brief Returns the value of the status_or, or the default value if
     * is_err().
     *
     * @param default_value The default value to return if is_err().
     * @return The value of the status_or, or the default value if is_err().
     */
    value_type unwrap_or(oe::remove_cv_t<value_type>&& default_value) const& noexcept {
        return is_ok() ? m_data.value : default_value;
    }

    /**
     * @brief Returns the value of the status_or, or the default value if
     * is_err().
     *
     * @param default_value The default value to return if is_err().
     * @return The value of the status_or, or the default value if is_err().
     */
    value_type unwrap_or(oe::remove_cv_t<value_type>&& default_value) && noexcept {
        return is_ok() ? m_data.value : default_value;
    }

    /**
     * @brief Returns the error of the status_or, or the default value if
     * is_ok().
     *
     * @param default_value The default value to return if is_ok().
     * @return The error of the status_or, or the default value if is_ok().
     */
    status_storage_type error_or(status_storage_type&& default_value) const& noexcept {
        return is_err() ? error() : default_value;
    }

    /**
     * @brief Returns the error of the status_or, or the default value if
     * is_ok().
     *
     * @param default_value The default value to return if is_ok().
     * @return The error of the status_or, or the default value if is_ok().
     */
    status_storage_type error_or(status_storage_type&& default_value) && noexcept { return is_err() ? error() : default_value; }

  private:
    value_type m_data; //!< The value of the status_or.
};

/**
 * @brief Represents a status_or with a void value type.
 * Just the same as oe::status<StatusType>
 *
 * @tparam StatusType The type of the status.
 */
template <typename StatusType> struct OE_API status_or<void, StatusType> : status<StatusType> {
    using value_type = void;                                                       //!< The type of the value. Always `void`.
    using status_type = StatusType;                                                //!< The type of the status.
    using status_storage_type = typename status<status_type>::status_storage_type; //!< The storage type for the status value.

    constexpr inline static bool is_status_enum = status<status_type>::is_status_enum; //!< Checks if StatusType
                                                                                       //!< has a status enum tag.

    static_assert(!oe::is_same_v<value_type, status_type>, "value_type cannot be the same as status_type");

    inline status_or() noexcept : status<status_type>{} {}

    /**
     * @brief Constructs a status with the given status value.
     * @param stat The status value.
     */
    inline status_or(status_storage_type&& stat) noexcept : status<status_type>{stat} {}

    inline status_or(const status_or& other) noexcept = default;
    inline status_or(status_or&& other) noexcept = default;

    /**
     * @brief Assigns the status value from another status.
     * @param other The status to assign from.
     * @return A reference to this status.
     */
    inline status_or& operator=(const status_or& other) noexcept = default;

    /**
     * @brief Move-assigns the status value from another status.
     * @param other The status to move-assign from.
     * @return A reference to this status.
     */
    inline status_or& operator=(status_or&& other) noexcept = default;

    /**
     * @brief Panics if the status is an error.
     * @param msg The message to panic with.
     */
    inline void expect(const char* msg) noexcept {
        if (this->is_err())
            oe::panic(msg);
    }

    /**
     * @brief Panics if the status is not an error.
     * @param msg The message to panic with.
     */
    inline void expect_err(const char* msg) noexcept {
        if (this->is_ok())
            oe::panic(msg);
    }

    /**
     * @brief Panics if the status is an error.
     */
    inline void unwrap() const { expect("Attempted to unwrap an error status_or"); }

    /**
     * @brief Panics if the status is not an error.
     */
    inline void unwrap_err() const { expect_err("Attempted to unwrap a success status_or"); }

    /**
     * @brief Returns the error of the status_or, or the default value if
     * is_ok().
     *
     * @param default_value The default value to return if is_ok().
     * @return The error of the status_or, or the default value if is_ok().
     */
    status_storage_type error_or(status_storage_type&& default_value) const& noexcept {
        return is_err() ? error() : default_value;
    }

    /**
     * @brief Returns the error of the status_or, or the default value if
     * is_ok().
     *
     * @param default_value The default value to return if is_ok().
     * @return The error of the status_or, or the default value if is_ok().
     */
    status_storage_type error_or(status_storage_type&& default_value) && noexcept { return is_err() ? error() : default_value; }

    /**
     * @brief Evaluate the function if is_ok() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_err() or the new
     * status_or processed by the function if is_ok()
     */
    template <typename F> inline auto and_then(F&& func) const& noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_ok() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_err() or the new
     * status_or processed by the function if is_ok()
     */
    template <typename F> inline auto and_then(F&& func) & noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_ok() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_err() or the new
     * status_or processed by the function if is_ok()
     */
    template <typename F> inline auto and_then(F&& func) const&& noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_ok() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_err() or the new
     * status_or processed by the function if is_ok()
     */
    template <typename F> inline auto and_then(F&& func) && noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_err() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_ok() or the new
     * status_or processed by the function if is_err()
     */
    template <typename F> inline auto or_else(F&& func) const& noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_err() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_ok() or the new
     * status_or processed by the function if is_err()
     */
    template <typename F> inline auto or_else(F&& func) & noexcept {
        if (is_ok())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_err() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_ok() or the new
     * status_or processed by the function if is_err()
     */
    template <typename F> inline auto or_else(F&& func) const&& noexcept {
        if (is_err())
            return func(*this);
        return *this;
    }

    /**
     * @brief Evaluate the function if is_err() and return the status_or.
     *
     * @tparam F The function type, passed a current status_or
     * @param func The function
     * @return The new status_or. The current status_or if is_ok() or the new
     * status_or processed by the function if is_err()
     */
    template <typename F> inline auto or_else(F&& func) && noexcept {
        if (is_err())
            return func(*this);
        return *this;
    }
};

} // namespace oe
