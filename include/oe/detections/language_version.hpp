/**
 * @file language_version.hpp
 * @brief The language version detection for C/C++
 * @details This file detects the language and its standard version for C/C++.
 * Usually, it's C++ used, but C is also supported.
 * Usage:
 * @code {.cpp}
 * #ifdef OE_LANGUAGE_TYPE_CPP
 * // C++ Code
 * #if OE_CPP_STANDARD >= OE_CPP23_ID
 * // C++23 or later, use new features
 * #else
 * // Use old features
 * #endif
 * #else // or #elif defined(OE_LANGUAGE_TYPE_C)
 * // C Code
 * #endif
 * @endcode
 *
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/detections/compiler.hpp>

#ifdef __cplusplus
/**
 * @define OE_LANGUAGE_TYPE
 * @brief Defines the language type string for C++
 */
#    define OE_LANGUAGE_TYPE "C++"

/**
 * @define OE_LANGUAGE_TYPE_CPP
 * @brief Defines the language type for C++
 * Defines if the current language is C++ but not C
 */
#    define OE_LANGUAGE_TYPE_CPP

#    ifdef _MSVC_LANG // MSVC Defines it but not __cplusplus
/**
 * @define OE_LANGUAGE_VERSION
 * @brief Defines the language standard for C++
 */
#        define OE_CPP_STANDARD _MSVC_LANG
#    else
/**
 * @define OE_CPP_STANDARD
 * @brief Defines the language standard for C++
 *
 */
#        define OE_CPP_STANDARD __cplusplus
#    endif

/**
 * @define OE_CPP23_ID
 * @brief Defines the C++23 language version ID
 * Compared with OE_CPP_VERSION
 * @see OE_CPP_VERSION
 */
#    define OE_CPP23_ID 202302L

/**
 * @define OE_CPP20_ID
 * @brief Defines the C++20 language version ID
 * Compared with OE_CPP_STANDARD
 * @see OE_CPP_STANDARD
 */
#    define OE_CPP20_ID 202002L

/**
 * @define OE_CPP17_ID
 * @brief Defines the C++17 language version ID
 * Compared with OE_CPP_STANDARD
 * @see OE_CPP_STANDARD
 */
#    define OE_CPP17_ID 201703L

/**
 * @define OE_CPP14_ID
 * @brief Defines the C++14 language version ID
 * Compared with OE_CPP_STANDARD
 * @see OE_CPP_STANDARD
 */
#    define OE_CPP14_ID 201402L

/**
 * @define OE_CPP11_ID
 * @brief Defines the C++11 language version ID
 * Compared with OE_CPP_STANDARD
 * @see OE_CPP_STANDARD
 */
#    define OE_CPP11_ID 201103L

/**
 * @define OE_CPP03_ID
 * @brief Defines the C++03 language version ID
 * Compared with OE_CPP_STANDARD
 * @see OE_CPP_STANDARD
 */
#    define OE_CPP03_ID 200301L

/**
 * @define OE_CPP98_ID
 * @brief Defines the C++98 language version ID
 * Compared with OE_CPP_STANDARD
 * @see OE_CPP_STANDARD
 */
#    define OE_CPP98_ID 199801L

#elif defined(__STDC_VERSION__)
/**
 * @define OE_LANGUAGE_TYPE
 * @brief Defines the language type string for C
 */
#    define OE_LANGUAGE_TYPE "C"

/**
 * @define OE_LANGUAGE_TYPE_C
 * @brief Defines the language type for C
 */
#    define OE_LANGUAGE_TYPE_C

/**
 * @define OE_C_STANDARD
 * @brief Defines the C standard version
 */
#    define OE_C_STANDARD __STDC_VERSION__

/**
 * @define OE_C23_ID
 * @brief Defines the C23 standard version ID
 * Compared with OE_C_STANDARD
 * @see OE_C_STANDARD
 */
#    define OE_C23_ID 202311L

/**
 * @define OE_C17_ID
 * @brief Defines the C17 standard version ID
 * Compared with OE_C_STANDARD
 * @see OE_C_STANDARD
 */
#    define OE_C17_ID 201710L

/**
 * @define OE_C11_ID
 * @brief Defines the C11 standard version ID
 * Compared with OE_C_STANDARD
 * @see OE_C_STANDARD
 */
#    define OE_C11_ID 201112L

/**
 * @define OE_C99_ID
 * @brief Defines the C99 standard version ID
 * Compared with OE_C_STANDARD
 * @see OE_C_STANDARD
 */
#    define OE_C99_ID 199901L

#endif
