/**
 * @file status_define.hpp
 * @brief Defines the status enum generation macros for the result library.
 * Only supports C++20, you should import `oe.types` and `oe.result.status_traits`(imported by
 * `oe.result`) first.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#ifndef OE_RESULT_STATUS_DEFINE_HPP
#define OE_RESULT_STATUS_DEFINE_HPP

#include <oe/preprocessor/concat.h>

/**
 * @def OE_RESULT_STATUS_ENUM_DEFINE(name, ...)
 * @brief Defines an enum for the status of an expected/unexpected value.
 * @note _oe_status_end_[name] should not be used. It's internal use only.
 *
 * @param name The name of the enum.
 * @param ... The status values to define.
 */
#define OE_RESULT_STATUS_ENUM_DEFINE(name, ...)                                                    \
    struct name : ::oe::status_enum_tag {                                                          \
        enum OE_PP_CONCAT(_oe_status_enum_, name) : oe::iptr {                                     \
            ok,                                                                                    \
            __VA_ARGS__,                                                                           \
            OE_PP_CONCAT(_oe_status_end_, name)                                                    \
        };                                                                                         \
    };

/**
 * @def OE_RESULT_STATUS_ENUM_EXTENDS(name, parent, ...)
 * @brief Extends an existing status enum with new status values.
 * @note _oe_status_start_[name] and _oe_status_end_[name] should not be used.
 * They're internal use only.
 *
 * @param name The name of the enum.
 * @param parent The parent enum to extend.
 * @param ... The status values to define.
 */
#define OE_RESULT_STATUS_ENUM_EXTENDS(name, parent, ...)                                           \
    struct name : parent {                                                                         \
        enum OE_PP_CONCAT(_oe_status_enum_, name) : oe::iptr {                                     \
            OE_PP_CONCAT(_oe_status_start_, name) = OE_PP_CONCAT(_oe_status_end_, parent) - 1,     \
            __VA_ARGS__,                                                                           \
            OE_PP_CONCAT(_oe_status_end_, name)                                                    \
        };                                                                                         \
    };

/**
 * @def OE_RESULT_STATUS_ENUM_EXTENDS_FINAL(name, parent, ...)
 * @brief Extends an existing status enum with new status values.
 * And without the end of the child enum. Cannot be extended further.
 *
 * @param name The name of the enum.
 * @param parent The parent enum to extend.
 * @param ... The status values to define.
 */
#define OE_RESULT_STATUS_ENUM_EXTENDS_FINAL(name, parent, ...)                                     \
    struct name : parent {                                                                         \
        enum OE_PP_CONCAT(_oe_status_enum_, name) : oe::iptr {                                     \
            OE_PP_CONCAT(_oe_status_start_, name) = OE_PP_CONCAT(_oe_status_end_, parent) - 1,     \
            __VA_ARGS__,                                                                           \
        };                                                                                         \
    };

#endif
