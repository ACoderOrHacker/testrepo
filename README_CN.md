<h1 align="center">
  <a href="https://github.com/ACoderOrHacker/OE">
    <img src="logo.png" alt="Logo" width="125" height="125">
  </a>
</h1>

<div align="center">
    OE - Ox-Extends Library
    <br>
    <br>
    <a href="https://github.com/ACoderOrHacker/OE/issues/new?assignees=&labels=bug&template=01_BUG_REPORT.md&title=bug%3A+">报告错误</a>
·
    <a href="https://github.com/ACoderOrHacker/OE/issues/new?assignees=&labels=enhancement&template=02_FEATURE_REQUEST.md&title=feat%3A+">请求功能</a>
·
    <a href="https://github.com/ACoderOrHacker/OE/discussions">提问</a>
</div>

<div align="center">
    <br />

[![项目许可](https://img.shields.io/github/license/ACoderOrHacker/OE.svg?style=flat-square)](LICENSE)

[![欢迎PR](https://img.shields.io/badge/PRs-welcome-ff69b4.svg?style=flat-square)](https://github.com/ACoderOrHacker/OE/issues?q=is%3Aissue+is%3Aopen+label%3A%22help+wanted%22)
[![由ACoderOrHacker用爱制作](https://img.shields.io/badge/%3C%2F%3E%20with%20%E2%99%A5%20by-ACoderOrHacker-ff1414.svg?style=flat-square)](https://github.com/ACoderOrHacker)

</div>

# 目录

- [关于本库](#关于本库)
- [文件结构](#文件结构)
- [项目依赖](#项目依赖)
- [构建本项目](#构建本项目)
- [打包](#打包)
- [为本项目做贡献](#为本项目做贡献)
- [许可证](#许可证)

# 关于本库

Ox 扩展库，基于Ox代码仓库
支持大部分常用库
可以在C++/D 中使用
对于[Dlang](https://dlang.org/), 可以直接使用[Dub](https://dub.pm/) 加入该依赖

# 重要警告!

Ox 库目前处于废弃状态，不应使用

# 文件结构

| 目录/文件                                       | 描述信息                                                   |
| ----------------------------------------------- | ---------------------------------------------------------- |
| `LICENSE`                                       | 许可证文件                                                 |
| `README.md`, `README_CN.md`                     | 项目介绍                                                   |
| `CONTRIBUTING.md`, `CONTRIBUTING_CN.md`         | 贡献指南                                                   |
| `.editorconfig`, `.clang-tidy`, `.clang-format` | 代码风格格式器                                             |
| `dub.sdl`                                       | [DUB](https://dub.pm) 项目文件                             |
| `xmake.lua`                                     | [xmake](https://xmake.io) 构建文件                         |
| `remote`                                        | [xmake](https://xmake.io) 远程仓库文件，用于xmake 依赖管理 |
| `scripts`                                       | 使用脚本，用于创建新模块等用途                             |
| `modules`                                       | [C++](https://cplusplus.com) 20 模块文件                   |
| `src`                                           | [C++](https://cplusplus.com) 源码                          |
| `include`                                       | [C++](https://cplusplus.com) 头文件                        |
| `source`                                        | [D](https://dlang.org) 源文件                              |
| `examples`                                      | 示例程序                                                   |
| `tests`                                         | 测试用例                                                   |
| `benchmarks`                                    | 基准测试程序                                               |
| `metas`                                         | 元信息和构建配置信息                                       |

# 项目依赖

## 构建依赖

本项目的构建工具为[Xmake](https://xmake.io)
Dub[https://dub.pm] 通常用以发布Dub包，但也可用作构建（使用dub作为构建工具构建时）
如果需要使用Dub构建，请使用`scripts/install_dub_dependencies.sh` 安装所需依赖
所有依赖将会被安装至`dub_dependencies` 目录

## 打包依赖

本项目使用[FPack](https://github.com/ACoderOrHacker/fpack) 打包
运行

```sh
fpack install
```

来安装打包所需依赖

# 构建本项目

运行 `xmake` 来构建本项目
或者

```sh
xmake build
```

构建时可以使用以下选项：

- `--shared=true/false` - 以共享库方式构建（默认是 `false`）。
- `--stdmodules=true/false` - 构建时使用 C++20 标准模块（默认是 `false`）。
- `--<module-name>=true/false` - 添加 `<module-name>` 源码（默认是 `true`, 及所有库加入）。

其他构建选项也可从 [配置元数据](metas/configs.json) 中获取

# 打包

运行 `fpack` 来打包本项目
或者

```sh
fpack pack
```

# 为本项目做贡献

参照[贡献指南](CONTRIBUTING_CN.md) 对本项目做出贡献

# 许可证

本项目使用 [Apache License 2.0](LICENSE) 进行许可
Apache-2.0许可证是一种宽松的开源许可证，允许用户自由使用、修改和分发软件，同时向用户明确授予贡献者的专利权利。
