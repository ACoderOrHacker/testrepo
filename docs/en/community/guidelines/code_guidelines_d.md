---
title: Code Guidelines in D
description: OE Code Guidelines in D
icon: simple/d

tags:
    - Community
    - Coding Guidelines
---

<!-- Copyright (C) 2026 ACoderOrHacker. All rights reserved. -->

# Code Guidelines in D

D has its own style and this standard has really taken root in people's minds.

D has a **REALLY** modern design and we follow it.

We will provide wrapped APIs in D (in `oe.core`) and provide modern APIs that reduce boilerplate codes.

## Exceptions {#Exceptions}

Use D exceptions less in OE.

Exceptions can mess up the control flow and blow up the binary size, and what's worse, users and
maintainers often forget to catch them, leading to code that's **not** exception-safe.

Use `oe.result` to give an error and catch an error or just `panic` on unrecoverable errors.

But you **can** use exceptions in APIs if it truly makes sense. (Not like [in C++](code_guidelines_cpp.md#Exceptions) because it's not idiomatic in D and D's STL is very great!).

## Mixin {#Mixin}

Reduce `mixin` use.

`mixin` is great, but use it less can highly improve compile times.

## Code styles {#Code-styles}

* Use clear, descriptive variable names with `camelCase`.
* Write clear, concise comments.
* Use `_` suffix for private variables or members.
* Use DDOX style comments for documenting D code.
* Always give Unicode first support (especially for UTF-8).
* Use dfmt(D) to format code.
* Use `oe.types` instead of standard types or types in `core.stdc.stdint` (e.g. `int`, `uint32_t`).
* Reduce `mixin` use.
