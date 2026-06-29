/**
 * @file status.hpp
 * @brief Defines the status type for the statusor library.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/oe/idcontact.h>
#include <oe/traits.hpp>
#include <oe/types.hpp>

/**
 * @brief Defines an enum for the status of an expected/unexpected value.
 * _OeExpectedEnd<name> should not be used. It's internal use only.
 * @note Using struct { enum {}; }; instead of enum class to make it can be
 * inherited.
 * @example
 * OE_STATUSOR_STATUS_ENUM_DEFINE(MyStatus, StatusA, StatusB)
 *
 */
#define OE_STATUSOR_STATUS_ENUM_DEFINE(name, ...)                              \
    struct name {                                                              \
        enum { Ok, __VA_ARGS__, OE_ID_CONTACT(_OeExpectedEnd_, name) };        \
    };

/**
 * @brief Extends an existing status enum with new status values.
 * @note Using struct { enum {}; }; instead of enum class to make it can be
 * inherited.
 * @example
 * OE_STATUSOR_STATUS_ENUM_DEFINE(Status, StatusA, StatusB)
 * OE_STATUSOR_STATUS_ENUM_EXTENDS(MyStatus, Status, StatusC, StatusD)
 * // then MyStatus has values: Ok, StatusA, StatusB, StatusC, StatusD
 */
#define OE_STATUSOR_STATUS_ENUM_EXTENDS(name, parent, ...)                     \
    struct name : parent {                                                     \
        enum : oe::iptr {                                                      \
            OE_ID_CONTACT(_OeExpectedStart, name) =                            \
                OE_ID_CONTACT(_OeExpectedEnd_, parent) - 1,                    \
            __VA_ARGS__,                                                       \
            OE_ID_CONTACT(_OeExpectedEnd_, name)                               \
        };                                                                     \
    };

/**
 * @brief Extends an existing status enum with new status values.
 * And without the end of the child enum.
 * @note Using struct { enum {}; }; instead of enum class to make it can be
 * inherited.
 * @example
 * OE_STATUSOR_STATUS_ENUM_DEFINE(Status, StatusA, StatusB)
 * OE_STATUSOR_STATUS_ENUM_EXTENDS(MyStatus, Status, StatusC, StatusD)
 * // then MyStatus has values: Ok, StatusA, StatusB, StatusC, StatusD
 */
#define OE_STATUSOR_STATUS_ENUM_EXTENDS_FINAL(name, parent, ...)               \
    struct name : parent {                                                     \
        enum : oe::iptr {                                                      \
            OE_ID_CONTACT(_OeExpectedStart, name) =                            \
                OE_ID_CONTACT(_OeExpectedEnd_, parent) - 1,                    \
            __VA_ARGS__,                                                       \
        };                                                                     \
    };

namespace oe {
namespace impl {
namespace statusor {
/**
 * @brief Represents the basic status of an expected/unexpected value.
 */
OE_STATUSOR_STATUS_ENUM_DEFINE(basic_status, InternalError, Unknown,
                               InvalidArgument)

using default_status =
    basic_status; //!< The default status type.Includes the most used statuses

/**
 * @brief Represents the status of an expected/unexpected value.
 * It passes the StatusType by value.
 * The StatusType should be create from OE_STATUSOR_<...> or extends from them
 * or a pointer to exactly the object created in heap.
 * You CAN NOT modify the status value after it is created.
 *
 * If you want to pass a
 * @tparam StatusType The status type.
 */
template <typename StatusType = default_status> struct status {
    using status_value_type =
        oe::conditional_t<oe::is_pointer_v<StatusType>,
                          oe::remove_pointer_t<StatusType>, StatusType>;

    constexpr status() noexcept : m_status() {
        static_assert(
            !oe::is_pointer_v<StatusType>,
            "oe::status: a pointer type cannot be default constructed");
    }
    explicit constexpr status(StatusType status) noexcept : m_status(status) {}

    constexpr bool operator==(StatusType status) const noexcept {
        return m_status == status;
    }
    constexpr bool operator!=(StatusType status) const noexcept {
        return m_status != status;
    }

    /**
     * @brief Returns the status value.
     */
    constexpr const status_value_type& get() const noexcept {
        if constexpr (oe::is_pointer_v<StatusType>)
            return *m_status;
        else
            return m_status;
    }

    /**
     * @brief Returns whether the status is OK (i.e., the value is
     * expected).
     */
    [[nodiscard]]
    constexpr bool ok() const noexcept {
        return this->get() == status_value_type::Ok;
    }

  private:
    StatusType m_status; //!< The status value.
};
} // namespace statusor
} // namespace impl
} // namespace oe
