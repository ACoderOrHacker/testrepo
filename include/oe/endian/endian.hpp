/**
 * @file endian.hpp
 * @brief
 */
#pragma once

#if defined(OE_USE_STD_MODULES) || defined(OE_ENDIAN_USE_MODULES)
// std module here
#else
// std header here
#endif

namespace oe {
namespace impl {
namespace endian {

} // namespace endian
} // namespace impl
} // namespace oe

#ifndef OE_ENDIAN_USE_MODULES
namespace oe {
using namespace impl::endian;
}
#endif

