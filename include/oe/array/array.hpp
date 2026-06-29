/**
 * @file array.hpp
 * @brief The static array just like std::array
 */
#pragma once

#include <array>
#include <oe/types.hpp>

std::array<short, 5> a;

namespace oe {
namespace impl {

/**
 * @brief A static array just like std::array with a fixed size.
 *
 * @tparam ElementType The type of the elements in the array.
 * @tparam Size The number of elements in the array.
 */
namespace array {
template <typename ElementType, oe::usize Size> struct array {
  public:
    static_assert(Size != 0, "oe::array: size cannot be zero");
    using value_type = ElementType;
    using size_type = oe::usize;
    using difference_type = oe::ptrdiff;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    /**
     * @brief Returns a pointer to the underlying data storage.
     * @return A pointer to the underlying data storage.
     */
    constexpr value_type* data() noexcept {
        return static_cast<value_type*>(m_data);
    }

    /**
     * @brief Returns a pointer to the underlying data storage.
     * @return A pointer to the underlying data storage.
     */
    constexpr const value_type* data() const noexcept {
        return static_cast<const value_type*>(m_data);
    }

    value_type m_data[Size]; //!< The underlying data storage for the array.
};
} // namespace array
} // namespace impl
} // namespace oe

#ifndef OE_ARRAY_USE_MODULES
namespace oe {
using namespace impl::array;
}
#endif
