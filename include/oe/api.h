/**
 * @file api.h
 * @brief The OE API header.
 * This header defines the OE API macro used to mark functions as exported from
 * the OE library.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#ifndef OE_API_H
#define OE_API_H

#include <oe/detections.h>
#ifdef OE_SHARED
#ifdef OE_COMPILER_MSVC
/**
 * @def OE_API
 * @brief The OE API macro.
 * This macro is used to mark functions as exported from the OE library. Does
 * nothing if oe is not a shared library.
 */
#define OE_API __declspec(dllexport)
#elif defined(OE_COMPILER_GCC) || defined(OE_COMPILER_CLANG)
/**
 * @def OE_API
 * @brief The OE API macro.
 * This macro is used to mark functions as exported from the OE library. Does
 * nothing if oe is not a shared library.
 */
#define OE_API __attribute__((visibility("default")))
#else
#error "Unsupported compiler"
#endif
#else
/**
 * @def OE_API
 * @brief The OE API macro.
 * This macro is used to mark functions as exported from the OE library. Does
 * nothing if oe is not a shared library.
 */
#define OE_API
#endif

#endif