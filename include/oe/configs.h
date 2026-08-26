/**
 * @file configs.h
 * @brief The basic configurations for OE.
 * @par A list of OE configurations:
 * - OE_SHARED: Defines the build type of OE. Defined if OE is built as a shared
 * library.
 * - OE_ENABLE_EXCEPTION_SUPPORTS: Enable exception supports for OE. *But* not
 * means OE will use exceptions to throw an error at all. It means OE will
 * enable some exception helpers in OE top modules, although you don't enable
 * the switch, you can import it by its inner module.
 *
 * For example, you need to import `oe.contracts`. You can enable this switch
 * (by adding -DOE_ENABLE_EXCEPTION_SUPPORTS=ON in cmake) and load it:
 * @code {.cpp}
 * // Enabled OE_ENABLE_EXCEPTION_SUPPORTS
 * import oe.contracts;
 * import maybe_thrown; // The example code. Contains a function that maybe
 * throw.
 *
 * int main() {
 *      oe::assert_thrown(maybe_thrown_function()); // You can use it directly.
 *      return 0;
 * }
 * @endcode
 *
 * But you can also load it without the switch:
 *
 * @code {.cpp}
 * // Disabled OE_ENABLE_EXCEPTION_SUPPORTS
 * import oe.contracts.exception_assertions; // Load it directly.
 * import maybe_thrown; // The example code. Contains a function that maybe
 * throw.
 *
 * int main() {
 *      oe::assert_thrown(maybe_thrown_function()); // You can use it, too.
 *      return 0;
 * }
 * @endcode
 *
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#ifndef OE_CONFIGS_H
#define OE_CONFIGS_H

/**
 * @def OE_DEBUG_MODE
 * @brief A tag for the debug mode.
 * @see OE_BUILD_MODE
 */
#define OE_DEBUG_MODE 0

/**
 * @def OE_DEBUG_MODE
 * @brief A tag for the debug mode.
 * @see OE_BUILD_MODE
 */
#define OE_RELEASE_MODE 1

#ifdef NDEBUG
/**
 * @def OE_IS_DEBUG
 * @brief Checks if the program is built as debug mode,
 * 0 if the build mode is release,
 * 1 if the build mode is debug.
 */
#define OE_IS_DEBUG 0

/**
 * @def OE_BUILD_MODE
 * @brief The build mode of the program
 * `OE_RELEASE_MODE` if the program is built as release,
 * `OE_DEBUG_MODE` if the program is built as debug.
 *
 * @see OE_RELEASE_MODE
 * @see OE_DEBUG_MODE
 */
#define OE_BUILD_MODE OE_RELEASE_MODE
#else
/**
 * @def OE_IS_DEBUG
 * @brief Checks if the program is build as debug mode,
 * 0 if the build mode is release,
 * 1 if the build mode is debug.
 */
#define OE_IS_DEBUG 1

/**
 * @def OE_BUILD_MODE
 * @brief The build mode of the program.
 * `OE_RELEASE_MODE` if the program is built as release,
 * `OE_DEBUG_MODE` if the program is built as debug.
 *
 * @see OE_RELEASE_MODE
 * @see OE_DEBUG_MODE
 */
#define OE_BUILD_MODE OE_DEBUG_MODE
#endif

#endif