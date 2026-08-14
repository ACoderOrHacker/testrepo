# The `oe.base` module

## What is it?

A basic helpers provide for all the OE modules. Includes `attributes`, `casts`, compiler-builtins wrapper, and so on.
Almost all the modules need it.

But users should reduce the uses of the `oe.base`.

## Code Guideline for `oe.base`

- Only basic helpers in it.
- Write interfaces in `oe::base` namespace but **not** the `oe` namespace.
- Only `oe.base` can be imported.