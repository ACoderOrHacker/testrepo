# 贡献

在为此代码库贡献之前，请先通过问题、电子邮件或其他方式与该代码库的所有者讨论您希望进行的更改，然后再进行更改。

请注意，我们有 [行为守则](CODE_OF_CONDUCT.md)，在与项目的所有互动中请遵循该守则。

## 开发环境设置

请参阅 [README](README.md) 以获取构建和打包说明。

## 问题和功能请求

您在源代码中发现了错误、文档中的错误，或者您想要一个新功能？

请查看 [GitHub Discussions](https://github.com/ACoderOrHacker/OE/discussions) 看看是否已经在讨论中。

您可以通过 [在GitHub上提交问题](https://github.com/ACoderOrHacker/OE/issues) 来帮助我们。

在您创建问题之前，请确保搜索问题档案——您的问题可能已经被解决了！

请尽量创建符合以下要求的错误报告：

- _可重现的._ 包含重现问题的步骤。
- _具体的._ 尽可能包含详细信息：版本、环境等。
- _唯一的._ 不要重复已有的已打开问题。
- _限于单个错误._ 每个报告只针对一个错误。

**更好的是：提交带有修复或新功能的拉取请求！**

### 如何提交拉取请求

1. 在我们的代码库中搜索相关的开放或关闭的
   [拉取请求](https://github.com/ACoderOrHacker/OE/pulls)，以避免重复工作。
2. Fork 该项目
3. 安装 [git-flow](https://git-flow.sh)
4. 运行 `git-flow init`
5. 创建一个新的功能分支 (`git flow feature start amazing_feature`)
6. 添加您的更改 (`git add .`)
7. 提交您的更改 (`git commit -m 'feat: add amazing_feature'`)
   OE 使用 [Conventional Commits](https://www.conventionalcommits.org)，所以请在提交消息中遵循规范。
8. 完成功能分支 (`git flow feature finish amazing_feature`)
9. 将其推送到远程
10. [打开拉取请求](https://github.com/ACoderOrHacker/OE/compare?expand=1)

## 贡献要求

### 问题报告

- 检查该问题是否已被报告。
- 检查该问题在最新版本中是否已被修复。
- 在问题描述中保持清晰简洁。
- 保持友好和尊重。
- 包含任何相关的代码片段或错误消息。
- 以语法正确、完整的句子打开新问题。

### 拉取请求

- 不允许在同一分支上发生冲突。
- PR 必须良好且书写规范。
- 提交必须是原子性的，并具有清晰、描述性的英文信息。
- 在开发分支上提交是允许的。

### 代码风格

- 使用清晰、描述性的变量名称。
- 编写清晰、简洁的注释。
- 使用 DDOX 风格注释来文档化 D 代码。
- 使用 doxygen 风格注释来文档化 C/C++ 代码。
- 宏以 `OE_` 开头。
- 每个 C/C++ 接口必须以 `oe::<module>::impl` 编写。
- `oe::<module>::details` 仅用于内部使用。
- 每个 C/C++ 函数必须在其声明中添加 `OE_API` 宏。
- 使用 utf-8 编码。
- 变量和函数命名使用蛇形命名法。
- 类的成员变量应以 `m_` 前缀。
- 缩进应为 4 个空格。
- 使用 clang-format（C/C++）和 dfmt（D）来格式化代码。
- 使用 `types` 库时使用诸如 std::uint8_t 的类型。
- 使用 `scripts/add_module.sh` 来添加新模块。
- 当为模块添加新配置时，在 [metas/configs.json](metas/configs.json) 中添加配置。
