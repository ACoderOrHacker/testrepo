/**
 * @file has_member_define.hpp
 * @brief The macros for definition `has member`. Only for C++.
 * Requires C++20 and you should import `oe.meta` first before using these
 * macros.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
#ifndef OE_META_HAS_MEMBER_DEFINE_HPP
#define OE_META_HAS_MEMBER_DEFINE_HPP

#include <oe/preprocessor.h>

/**
 * @def OE_DEFINE_HAS_MEMBER
 * @brief Macro to define a trait for checking if a type has a member function
 * or field.
 * @details You can extend this macro by using argument `CheckType`. It's the
 * passing type of the member to check for.
 * @param trait_name The name of the trait to define.
 * @param member_name The name of the member to check for.
 */
#define OE_DEFINE_HAS_MEMBER(trait_name, member_name)                          \
    template <class CheckType, class = void>                                   \
    struct trait_name : oe::false_type {};                                     \
    template <class CheckType>                                                 \
    struct trait_name<                                                         \
        CheckType, oe::void_t<decltype(oe::declval<CheckType>().member_name)>> \
        : oe::true_type {};                                                    \
    template <class CheckType>                                                 \
    constexpr static bool OE_PP_CONCAT(trait_name, _v) =                       \
        trait_name<CheckType>::value;

/**
 * @def OE_DEFINE_HAS_or_TYPE
 * @brief Macro to define a trait for checking if a type has a type definition
 * @details You can extend this macro by using argument `CheckType`. It's the
 * passing type of the type to check for.
 * @param trait_name The name of the trait to define.
 * @param type_name The name of the type to check for.
 */
#define OE_DEFINE_HAS_TYPE(trait_name, type_name)                              \
    template <class CheckType, class = void>                                   \
    struct trait_name : oe::false_type {};                                     \
    template <class CheckType>                                                 \
    struct trait_name<CheckType, oe::void_t<typename CheckType::type_name>>    \
        : oe::true_type {};                                                    \
    template <class CheckType>                                                 \
    constexpr static bool OE_PP_CONCAT(trait_name, _v) =                       \
        trait_name<CheckType>::value;

/**
 * @def OE_DEFINE_HAS_MEMBER_WITH_TYPE
 * @brief Macro to define a trait for checking if a type has a member with
 * a correct type or field with a specific type.
 * @details You can extend this macro by using argument `CheckType`. It's the
 * passing type of the member to check for.
 * @param trait_name The name of the trait to define.
 * @param member_name The name of the member to check for.
 * @param type The type of the member to check for.
 */
#define OE_DEFINE_HAS_MEMBER_WITH_TYPE(trait_name, member_name, type)          \
    template <class CheckType, class = void>                                   \
    struct trait_name : oe::false_type {};                                     \
    template <class CheckType>                                                 \
    struct trait_name<                                                         \
        CheckType, oe::enable_if_t<std::is_same_v<                             \
                       decltype(oe::declval<CheckType>().member_name), type>>> \
        : oe::true_type {};                                                    \
    template <class CheckType>                                                 \
    constexpr static bool OE_PP_CONCAT(trait_name, _v) =                       \
        trait_name<CheckType>::value;

/**
 * @def OE_DEFINE_HAS_FUNCTION_MEMBER
 * @brief Macro to define a trait for checking if a type has a function member
 * with a given return type and arguments.
 * @details You can extend this macro by using argument `CheckType`. It's the
 * passing type of the function member to check for.
 * @param trait_name The name of the trait to define.
 * @param member_name The name of the function member to check for.
 * @param ret The return type of the function member to check for.
 * @param ... The argument types of the function member to check for.
 */
#define OE_DEFINE_HAS_FUNCTION_MEMBER(trait_name, member_name, ret, ...)       \
    template <class CheckType, class... Args>                                  \
    struct OE_PP_CONCAT(trait_name, _Details) {                                \
      private:                                                                 \
        template <class U>                                                     \
        static auto check(int)                                                 \
            -> decltype(oe::is_same_v<                                         \
                            decltype(oe::declval<CheckType>().member_name(     \
                                oe::declval<Args>()...)),                      \
                            ret>,                                              \
                        oe::true_type());                                      \
        template <class U> static oe::false_type check(...);                   \
                                                                               \
      public:                                                                  \
        enum {                                                                 \
            value = oe::is_same<decltype(check<CheckType>(0)),                 \
                                oe::true_type>::value                          \
        };                                                                     \
    };                                                                         \
    template <class CheckType>                                                 \
    using trait_name =                                                         \
        OE_PP_CONCAT(trait_name, _Details)<CheckType, __VA_ARGS__>;            \
    template <class CheckType>                                                 \
    constexpr static bool OE_PP_CONCAT(trait_name, _v) =                       \
        trait_name<CheckType>::value;

#endif // !OE_META_HAS_MEMBER_DEFINE_HPP
