/**
 * @file function.ixx
 * @brief Gives a flexible function wrapper that lets you store and call any
 * callable with a given signature.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.functional.function;

export import oe.functional.invoke;

export namespace oe {
template <typename FunctionSignature> class function {};
} // namespace oe
