/**
 * @file allocator.hpp
 * @brief
 */
#pragma once

#if defined(OE_USE_STD_MODULES) || defined(OE_ALLOCATOR_USE_MODULES)
// std module here
#else
// std header here
#endif

namespace oe {
namespace impl {
namespace allocator {} // namespace allocator
} // namespace impl
} // namespace oe

#ifndef OE_ALLOCATOR_USE_MODULES
namespace oe {
using namespace impl::allocator;
}
#endif
