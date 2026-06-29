/**
 * @file status_or.hpp
 * @brief status_or structure definition
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/statusor/status.hpp>

namespace oe {
namespace details {
template <typename ValueType, typename StatusType>
struct status_or_data : public oe::impl::statusor::status<StatusType> {
    constexpr status_or_data() noexcept
        : oe::impl::statusor::status<StatusType>() {}

    constexpr explicit status_or_data(StatusType status) noexcept
        : oe::impl::statusor::status<StatusType>(status) {}

    constexpr explicit status_or_data(ValueType value) noexcept
        : oe::impl::statusor::status<StatusType>(), data(value) {}

    union {
        char dummy_;
        ValueType value;
    } data;
};
} // namespace details

namespace impl {
namespace statusor {
template <typename ValueType, typename StatusType = default_status>
struct status_or : protected details::status_or_data<ValueType, StatusType> {
    using value_type = ValueType;
    using status_type = StatusType;
    using status_value_type =
        typename details::status_or_data<value_type,
                                         status_type>::status_value_type;

    static_assert(!oe::is_same_v<value_type, status_type>,
                  "oe::status_or: ValueType and StatusType must be different");

    constexpr status_or() noexcept
        : details::status_or_data<value_type, status_type>() {}

    constexpr status_or(status_type status) noexcept
        : details::status_or_data<value_type, status_type>(status) {}

    constexpr status_or(value_type value) noexcept
        : details::status_or_data<value_type, status_type>(value) {}

    constexpr status_or& operator=(value_type value) noexcept {
        this->data.value = value;
        return *this;
    }

    constexpr status_or& operator=(status_type status) noexcept {
        this->m_status = status;
        return *this;
    }

    constexpr const value_type& operator*() const noexcept { return value(); }

    constexpr const value_type& value() const noexcept {
        return this->data.value;
    }

    constexpr const value_type&
    value_or(oe::remove_cv_t<value_type>&& value) const noexcept {
        return this->ok() ? this->value() : value;
    }

    constexpr status_type
    error_or(oe::remove_cv_t<status_type>&& status) const noexcept {
        return this->ok() ? status_value_type::Ok : this->m_status;
    }
};
} // namespace statusor
} // namespace impl
} // namespace oe

#ifndef OE_STATUSOR_USE_MODULES
namespace oe {
using namespace impl::statusor;
}
#endif
