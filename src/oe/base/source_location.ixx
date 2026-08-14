/**
 * @file source_location.ixx
 * @brief Provides a source_location structure for source location getting.
 * Just a std::source_location wrapping.
 *
 * @warning Users should use `oe.utilities` to use `source_location`
 *
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
module;

#include <source_location> // for std::source_location

export module oe.base.source_location;

export namespace oe::base {
using std::source_location;
} // namespace oe::base