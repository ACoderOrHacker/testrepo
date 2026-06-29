<h1 align="center">
  <a href="https://github.com/ACoderOrHacker/OE">
    <img src="logo.png" alt="Logo" width="125" height="125">
  </a>
</h1>

<div align="center">
    OE - Ox-Extends Library
    <br/>
    <br/>
    <a href="https://github.com/ACoderOrHacker/OE/issues/new?assignees=&labels=bug&template=01_BUG_REPORT.md&title=bug%3A+">Report a Bug</a>
    ·
    <a href="https://github.com/ACoderOrHacker/OE/issues/new?assignees=&labels=enhancement&template=02_FEATURE_REQUEST.md&title=feat%3A+">Request a Feature</a>
    ·
    <a href="https://github.com/ACoderOrHacker/OE/discussions">Ask a Question</a>
</div>

<div align="center">
    <br/>

[![Project license](https://img.shields.io/github/license/ACoderOrHacker/OE.svg?style=flat-square)](LICENSE)

[![Pull Requests welcome](https://img.shields.io/badge/PRs-welcome-ff69b4.svg?style=flat-square)](https://github.com/ACoderOrHacker/OE/issues?q=is%3Aissue+is%3Aopen+label%3A%22help+wanted%22)
[![code with love by ACoderOrHacker](https://img.shields.io/badge/%3C%2F%3E%20with%20%E2%99%A5%20by-ACoderOrHacker-ff1414.svg?style=flat-square)](https://github.com/ACoderOrHacker)

</div>

# Table of Contents

- [About](#about)
- [File Structure](#file-structure)
- [Dependencies](#dependencies)
- [Building](#building)
- [Packaging](#packaging)
- [Contributing](#contributing)
- [License](#license)

# About

The Ox-Extends Library, based on Ox codebase.
Supports terminal, gui, string, etc.
It can be used in both [C++](https://cplusplus.com) and [D](https://dlang.org)

# Warning

Old [ox](https://github.com/ACoderOrHacker/ox) is actually deprecated.
DO NOT USE IT.

# File Structure

| Directory/File                                  | Description                                                     |
| ----------------------------------------------- | --------------------------------------------------------------- |
| `LICENSE`                                       | License file                                                    |
| `README.md`                                     | Short introduction                                              |
| `CONTRIBUTING.md`                               | Contributing guidelines                                         |
| `.editorconfig`, `.clang-tidy`, `.clang-format` | Code style configuration files                                  |
| `dub.sdl`                                       | [DUB](https://dub.pm) project file                              |
| `xmake.lua`                                     | [xmake](https://xmake.io) build file, use this to build C++ & D |
| `remote`                                        | [xmake](https://xmake.io) remote package files                  |
| `scripts`                                       | Useful scripts for publishing, packing, etc.                    |
| `modules`                                       | [C++](https://cplusplus.com) 20 modules                         |
| `src`                                           | [C++](https://cplusplus.com) source code                        |
| `include`                                       | [C++](https://cplusplus.com) header files                       |
| `source`                                        | [D](https://dlang.org) source code                              |
| `examples`                                      | Example programs                                                |
| `tests`                                         | Test programs                                                   |
| `benchmarks`                                    | Benchmark programs                                              |
| `metas`                                         | Gives metainfos and configs for the project                     |

# Dependencies

## Building Dependencies

[Xmake](https://xmake.io) is for building.

[DUB](https://dub.pm) is used for publishing in dub (building is also ok).
You can also use [scripts/install_dub_deps.sh](scripts/install_dub_deps.sh) to install dependencies for DUB and then build.
Every dependency will be installed into `dub_dependencies` before committing.

## Packing Dependencies

[FPack](https://github.com/ACoderOrHacker/fpack) is for packing.
Run

```sh
fpack install
```

to install the required tools for packing.

# Building

Run `xmake` to build the project.
Or

```sh
xmake build
```

You can also use these following options in building:

- `--shared=true/false` - Build shared libraries (default is `false`).
- `--modules=true/false` - Build With C++20 modules (default is `false`).
- `--stdmodules=true/false` - Build With C++20 standard modules (default is `false`).
- `--<module-name>=true/false` - Build With `<module-name>` (default is `true`, all libraries are included by default).

Other build options/macros see [configs](metas/configs.json)

# Packaging

Run `fpack` to package the project.
Or

```sh
fpack pack
```

# Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for more information.

# License

This library is under the Apache License 2.0.

The Apache-2.0 license is a permissive open-source license that allows users to freely use, modify, and distribute software while providing an express grant of patent rights from contributors to users.
