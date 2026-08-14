/**
 * @file status.ixx
 * @brief Defines the status type for the result library.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
module;

#include <oe/result/status_define.hpp>

export module oe.result.status;

import oe.types;
import oe.result.status_traits;

export namespace oe {
/**
 * @brief Represents the basic status of an expected/unexpected value.
 */
OE_RESULT_STATUS_ENUM_DEFINE(basic_status, internal_error, unknown_error, invalid_argument_error,
                             no_memory_error, not_found_error, already_exists_error,
                             permission_denied_error, overflow_error, out_of_range_error,
                             unsupported_error)

using default_status = basic_status; //!< The default status type. Includes the most used statuses

/**
 * @brief Represents the status of an expected/unexpected value.
 * It passes the StatusType by value.
 * The StatusType should be created from OE_RESULT_STATUS_ENUM_<...>, extends
 * from them or a pointer to exactly the object created in heap by shared
 * pointer. You CAN NOT modify the status value after it is created.
 * @tparam StatusType The status-enum/large-object type.
 */
template <typename StatusType = default_status> struct OE_API status {
    static_assert(oe::has_status_object_tag_v<StatusType> || oe::has_status_enum_tag_v<StatusType>,
                  "StatusType must be a status enum or a status object.");

    constexpr static inline bool is_status_enum =
        oe::has_status_enum_tag_v<StatusType>; //!< Checks if StatusType
                                               //!< has a status enum tag.

    using status_storage_type = oe::conditional_t<is_status_enum, oe::iptr, StatusType*>;
    //!< The storage type for the status value.
    // TODO: Use xxx_ptr?

    static_assert(sizeof(oe::iptr) == sizeof(StatusType*),
                  "Compilation failed: StatusType* must be the same size as "
                  "oe::iptr, please report this issue");

    static_assert(oe::conditional_t<!is_status_enum, oe::has_ok<StatusType>, oe::true_type>::value,
                  "StatusType must have an `ok` member when used as a status enum.");

    constexpr static inline status_storage_type ok_value =
        oe::conditional_t<is_status_enum, oe::integral_constant<oe::iptr, StatusType::ok>,
                          oe::integral_constant<oe::nullptr_t, nullptr>>::value;
    //!< The ok status value.
    // Using this but not
    // @code{.cpp}
    // is_status_enum ? StatusType::ok : nullptr;
    // @endcode
    // to avoid the compilation error of incompatible types

    /**
     * @brief Constructs a status with the ok status.
     */
    inline status() noexcept : m_status{ok_value} {}

    /**
     * @brief Constructs a status with the given status value.
     * @param stat The status value.
     */
    inline /* implicit */ status(status_storage_type&& stat) noexcept : m_status{stat} {}

    inline status(const status& other) noexcept = default;
    inline status(status&& other) noexcept = default;

    /**
     * @brief Assigns the status value from another status.
     * @param other The status to assign from.
     * @return A reference to this status.
     */
    inline status& operator=(const status& other) noexcept = default;

    /**
     * @brief Move-assigns the status value from another status.
     * @param other The status to move-assign from.
     * @return A reference to this status.
     */
    inline status& operator=(status&& other) noexcept = default;

    /**
     * @brief Returns whether the status is ok status.
     * @return True if the status is `ok`, false otherwise.
     */
    [[nodiscard]]
    inline bool is_ok() const noexcept {
        return m_status == ok_value;
    }

    /**
     * @brief Returns whether the status is error status.
     * @return True if the status is not `ok`, false otherwise.
     */
    [[nodiscard]]
    inline bool is_err() const noexcept {
        return !is_ok();
    }

    /**
     * @brief Returns whether the status is ok status.
     * @return True if the status is `ok`, false otherwise.
     */
    inline explicit operator bool() const noexcept { return is_ok(); }

    /**
     * @brief Returns the current status/error value.
     * @note Actually, it returns the status value directly.
     * Not only the error, if ok(), then return the ok status.
     * Name it as `error` because you should check `ok()` first before calling
     * this.
     * @return The status value.
     */
    inline status_storage_type error() const noexcept { return m_status; }

  private:
    status_storage_type m_status; //!< The status value.
};
} // namespace oe