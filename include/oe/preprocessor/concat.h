/**
 * @file concat.h
 * @brief Concats two IDs in macros.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
#ifndef OE_PREPROCESSOR_CONCAT_H
#define OE_PREPROCESSOR_CONCAT_H

#define OE_INTERNAL_ID_CONCAT(x, y) x##y

/**
 * @def OE_PP_CONCAT
 * @brief The OE ID concat macro.
 * This macro is used to concatenate two tokens into a single token.
 * @param a The first token.
 * @param b The second token.
 * @return The concatenated token.
 */
#define OE_PP_CONCAT(a, b) OE_INTERNAL_ID_CONCAT(a, b)

#endif // !OE_PREPROCESSOR_CONCAT_H
