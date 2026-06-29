/**
 * @file traits.hpp
 * @brief Traits definitions
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#if defined(OE_USE_STD_MODULES) || defined(OE_TRAITS_USE_STD_MODULES)
import std;
#else
#include <type_traits>
#endif

namespace oe {
namespace impl {
namespace traits {

using std::bool_constant;
using std::conditional;
using std::conditional_t;
using std::false_type;
using std::integral_constant;
using std::is_pointer;
using std::is_pointer_v;
using std::is_same;
using std::is_same_v;
using std::remove_cv;
using std::remove_cv_t;
using std::remove_pointer;
using std::remove_pointer_t;
using std::true_type;

} // namespace traits
} // namespace impl
} // namespace oe

#ifndef OE_TRAITS_USE_MODULES
namespace oe {
using namespace impl::traits;
}
#endif
