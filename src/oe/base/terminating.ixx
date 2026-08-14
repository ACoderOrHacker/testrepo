/**
 * @file terminating.ixx
 * @brief Terminating functions for OE (like exit).
 * @todo This library depends on std::printf and std::exit, they are c-functions
 * and may cause problems.
 *
 * @warning Users should use `oe.utilities` to use terminating functions.
 *
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
module;

#include <cstdlib> // for std::exit
#include <cstdio>  // for printf

export module oe.base.terminating;

import oe.base.source_location;
import oe.base.cast;

export namespace oe::base {
/**
 * @enum exit_status
 * @brief The exit status for oe::exit.
 *
 * @see oe::exit
 */
enum class exit_status { success = EXIT_SUCCESS, failure = EXIT_FAILURE };

/**
 * @brief Exits the program with the given status code. The given status code
 * depends on the platform.
 *
 * @param status The exit status code.
 */
[[noreturn]]
inline void exit(const int status) noexcept {
    std::exit(status);
}

/**
 * @brief Exits with the given status.
 *
 * @see oe::exit_status
 * @param status The exit status.
 */
[[noreturn]]
inline void exit(exit_status status) noexcept {
    exit(cast<int>(status));
}

/**
 * @brief Panics with the given message and source location information.
 * @details Outputs an error message and exits with exit code `1` after calling
 * this. Never returns because the exit.
 * @par
 * The output message is `PANIC(<func>: <line>, <column>): <msg> (from file:
 * <file>)`.
 *
 * @param msg The extra message for `panic` to output, nullptr if no need to
 * output message.
 * @param loc The source location of the caller.
 */
[[noreturn]]
inline void panic(const char* msg,
                  const source_location& loc = source_location::current()) noexcept {
    if (msg != nullptr)
        std::printf("PANIC(%s: %u, %u): %s \n\t(from file: %s)\n", loc.function_name(), loc.line(),
                    loc.column(), msg, loc.file_name());
    exit(exit_status::failure);
}
} // namespace oe::base
