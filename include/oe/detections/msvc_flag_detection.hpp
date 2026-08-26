/**
 * @file msvc_flag_detection.hpp
 * @brief Detects the _MSC_VER macro
 * @details This file is for the _MSC_VER macro.
 * Some compilers like Clang or MSVC may define it.
 * And Microsoft CRT sometimes has some unstandard behaviors.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */

#pragma once

#ifdef _MSC_VER
/**
 * @define OE_MSVC_FLAG_DETECTED
 * @brief Detects the _MSC_VER macro
 * @details This macro is defined when the _MSC_VER macro is defined.
 */
#define OE_MSVC_FLAG_DETECTED _MSC_VER
#endif
