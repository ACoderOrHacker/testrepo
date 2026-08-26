/**
 * @file language_version.h
 * @brief The language version detection for C/C++.
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
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
#ifndef OE_DETECTIONS_LANGUAGE_VERSION_H
#define OE_DETECTIONS_LANGUAGE_VERSION_H

#include <oe/detections/compiler_detections.h>

#ifdef __cplusplus
/**
 * @def OE_LANGUAGE_TYPE
 * @brief Defines the language type string for C++.
 */
#define OE_LANGUAGE_TYPE "C++"

/**
 * @def OE_LANGUAGE_TYPE_CPP
 * @brief Defines the language type for C++.
 * Defines if the current language is C++ but not C.
 */
#define OE_LANGUAGE_TYPE_CPP

#ifdef _MSVC_LANG // MSVC Defines it but not __cplusplus
/**
 * @def OE_LANGUAGE_VERSION
 * @brief Defines the language standard for C++.
 */
#define OE_CPP_STANDARD _MSVC_LANG
#else
/**
 * @define OE_CPP_STANDARD
 * @brief Defines the language standard for C++
 *
 */
#define OE_CPP_STANDARD __cplusplus
#endif

/**
 * @def OE_CPP26_ID
 * @brief Defines the C++26 language version ID.
 * Compared with OE_CPP_STANDARD.
 * @note This value is from the cplusplus papers:
 * https://github.com/cplusplus/draft/blob/8ab1a9b574d97fea3809a2885c7f41f5d60b93f6/papers/n5051.md
 * Maybe changed.
 * @see OE_CPP_STANDARD
 */
#define OE_CPP26_ID 202603L

/**
 * @def OE_CPP23_ID
 * @brief Defines the C++23 language version ID.
 * Compared with OE_CPP_STANDARD.
 * @see OE_CPP_STANDARD
 */
#define OE_CPP23_ID 202302L

/**
 * @def OE_CPP20_ID
 * @brief Defines the C++20 language version ID.
 * Compared with OE_CPP_STANDARD.
 * @see OE_CPP_STANDARD
 */
#define OE_CPP20_ID 202002L

/**
 * @def OE_CPP17_ID
 * @brief Defines the C++17 language version ID.
 * Compared with OE_CPP_STANDARD.
 * @see OE_CPP_STANDARD
 */
#define OE_CPP17_ID 201703L

/**
 * @def OE_CPP14_ID
 * @brief Defines the C++14 language version ID.
 * Compared with OE_CPP_STANDARD.
 * @see OE_CPP_STANDARD
 */
#define OE_CPP14_ID 201402L

/**
 * @def OE_CPP11_ID
 * @brief Defines the C++11 language version ID.
 * Compared with OE_CPP_STANDARD.
 * @see OE_CPP_STANDARD
 */
#define OE_CPP11_ID 201103L

/**
 * @def OE_CPP03_ID
 * @brief Defines the C++03 language version ID.
 * Compared with OE_CPP_STANDARD.
 * @see OE_CPP_STANDARD
 */
#define OE_CPP03_ID 200301L

/**
 * @def OE_CPP98_ID
 * @brief Defines the C++98 language version ID.
 * Compared with OE_CPP_STANDARD.
 * @see OE_CPP_STANDARD
 */
#define OE_CPP98_ID 199801L

#elif defined(__STDC_VERSION__)
/**
 * @def OE_LANGUAGE_TYPE
 * @brief Defines the language type string for C.
 */
#define OE_LANGUAGE_TYPE "C"

/**
 * @def OE_LANGUAGE_TYPE_C
 * @brief Defines the language type for C.
 */
#define OE_LANGUAGE_TYPE_C

/**
 * @def OE_C_STANDARD
 * @brief Defines the C standard version.
 */
#define OE_C_STANDARD __STDC_VERSION__

/**
 * @def OE_C23_ID
 * @brief Defines the C23 standard version ID.
 * Compared with OE_C_STANDARD.
 * @see OE_C_STANDARD
 */
#define OE_C23_ID 202311L

/**
 * @def OE_C17_ID
 * @brief Defines the C17 standard version ID.
 * Compared with OE_C_STANDARD.
 * @see OE_C_STANDARD
 */
#define OE_C17_ID 201710L

/**
 * @def OE_C11_ID
 * @brief Defines the C11 standard version ID.
 * Compared with OE_C_STANDARD.
 * @see OE_C_STANDARD
 */
#define OE_C11_ID 201112L

/**
 * @def OE_C99_ID
 * @brief Defines the C99 standard version ID.
 * Compared with OE_C_STANDARD.
 * @see OE_C_STANDARD
 */
#define OE_C99_ID 199901L

#endif

#endif