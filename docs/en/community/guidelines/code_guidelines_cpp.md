---
title: Code Guidelines in C++
description: OE Code Guidelines in C++
icon: simple/cplusplus

tags:
    - Community
    - Coding Guidelines
---

<!-- Copyright (C) 2026 ACoderOrHacker. All rights reserved. -->

# Code Guidelines in C++

## Exceptions {#Exceptions}

We never use C++ exceptions in OE.

Exceptions can mess up the control flow and blow up the binary size, and what's worse, users and
maintainers often forget to catch them, leading to code that's **not** exception-safe.

Use `oe.result` to give an error and catch an error or just `panic` on unrecoverable errors.

## STL {#STL}

We try not to use STL in OE.

The STL usually comes with historical baggage. And STL cannot boost performance with our developing.
STL with exceptions, cannot be used in `no-exception` environments (see [Exceptions](#Exceptions) for more details).
For STL, we cannot extend it to support our needs.

But that doesn't mean we can't use it in OE.
Sometimes the features cannot be implemented by standard C++ (like **std type_traits header** or **std::source_location**).
Then we just wrap them to fit our needs.

## Macros {#Macros}

We use macros **less**.

Macros are not available in C++ Modules (It cannot be exported in modules).
And It has a lot of side effects.

Like the following code:

```cpp
#define OE_MAX(a, b) ((a) > (b) ? (a) : (b))
```

If you use it at the wrong place, like:

```cpp
int a = 1;
int b = 2;
int c = OE_MAX(a++, b++); // c = 3, a = 3, b = 3

// Wrong answer!
```

And the macros can be spread across multiple lines, making it harder to read and debug.
Use **Code Generator** to do hard works but not **macros**, this make developers more productive and less error-prone.

### When to use macros?

Macros can only be used in C++ preprocessor context and some simple generating works. **NEVER** use macros to inline the codes at preprocessor level but use **constexpr functions** or **constexpr constants** instead.

## 3rd-libraries {#3rd-libraries}

We use 3rd-libraries **less**.

We prefer to rewrite some simple 3rd-libraries but not to use them to reuse the existing implementations.
That can reduce the binary size and improve the performance.

But for heavy libraries (like ffmpeg, openssl), we prefer to wrap them into OE-style but not rewrite them.
Because Their performance is better and their functions have been tested over time and more complex.

## Code styles {#Code-styles}

We give developers a set of code styles to follow.
If you want to contribute, please follow the code styles.

* Use C++20 features whenever possible.
* Use clear, descriptive variable names with `snake_case`.
* Write clear, concise comments.
* Use [Doxygen comments](https://www.doxygen.nl/manual/docblocks.html) and **JavaDoc-style** comments.
* Use `OE_<MacroName>` for macro names.
* Write extensible interfaces in namespace `oe::<module>::impls`.
* Use `oe::<module>::details` for private implementation details (although they are not exported at all).
* Add `OE_API` macro to exported symbols.
* Always give Unicode first support (especially for UTF-8).
* Prefix `m_` for member variables.
* Use clang-format to format the code.
* Use `oe.types` instead of standard types or types in `<cstdint>` (e.g. `int`, `uint32_t`).
