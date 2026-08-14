/**
 * @file console.ixx
 * @brief Console I/O for OE io library
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
module;

#include <oe/api.h>

export module oe.io.console;

export namespace oe {
/**
 * @brief Prints an error message to stderr.
 *
 * @pre fmt != nullptr
 * @param fmt The format string.
 * @param args The error messages to print.
 */
template <typename... Args>
OE_API void prerrln(const char* fmt, Args... args) noexcept {
    // TODO: implement
}
} // namespace oe