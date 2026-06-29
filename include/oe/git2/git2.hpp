/**
 * @file git2.hpp
 * @brief
 */
#pragma once

#if defined(OE_USE_STD_MODULES) || defined(OE_GIT2_USE_MODULES)
// std module here
#else
// std header here
#endif

namespace oe {
namespace impl {
namespace git2 {

} // namespace git2
} // namespace impl
} // namespace oe

#ifndef OE_GIT2_USE_MODULES
namespace oe {
using namespace impl::git2;
}
#endif

