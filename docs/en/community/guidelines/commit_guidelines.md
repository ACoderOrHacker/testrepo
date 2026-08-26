---
title: Commit Guidelines
description: OE Commit Guidelines
icon: simple/git

tags:
    - Community
    - Coding Guidelines
---

<!-- Copyright (C) 2026 ACoderOrHacker. All rights reserved. -->

# Commit Guidelines

`OE` uses [Git](https://git-scm.com/) to manage source code.

And standard commit guidelines are very important.
It's readable and easy to understand. More importantly, `OE` uses tools to generate [Changelog](https://github.com/ACoderOrHacker/OE/blob/master/CHANGELOG.md).

If you are not following these guidelines, your commits will not be accepted.

## Commit Standard

!!! note
    Modified based on [Angular Commit Message Guidelines](https://github.com/angular/angular/blob/main/contributing-docs/commit-message-guidelines.md)

We use [Conventional Commits](https://www.conventionalcommits.org/) and its variant [Angular Commit Format](https://github.com/angular/angular/blob/main/contributing-docs/commit-message-guidelines.md):

### Format

```
<header>
<BLANK LINE>
<body>
<BLANK LINE>
<footer>
```

The `<header>` is mandatory and must conform to the [Commit Message Header format](#commit-header-format).

The `<body>` is mandatory for all commits except for those of type "docs". When the body is present it must be at least 20 characters long and must conform to the [Commit Message Body format](#commit-body-format).

The `<footer>` is optional. The [Commit Message Footer format](#commit-footer-format) describes what the footer is used for and the structure it must have.

#### Commit Header Format {#commit-header-format}

```
<type>(<scope>): <summary>
  |       |          |
  |       |          |----> Summary in present tense. Not capitalized. No period at the end.
  |       |
  |       |----> Commit scope.
  |
  |----> Commit type.
```

`<type>` and `<scope>` are mandatory, `<summary>` is optional.

`<type>` and `<scope>` are required to be one of the following:

| type       | description                                                                                            |
|------------|--------------------------------------------------------------------------------------------------------|
| `feat`     | A new feature                                                                                          |
| `fix`      | A bug fix                                                                                              |
| `docs`     | Documentation only changes                                                                             |
| `style`    | Changes that do not affect the meaning of the code (white-space, formatting, missing semi-colons, etc) |
| `refactor` | A code change that neither fixes a bug nor adds a feature                                              |
| `perf`     | A code change that improves performance                                                                |
| `build`    | Changes to the build process or auxiliary tools and libraries such as documentation generation         |
| `ci`       | Changes to the continuous integration configuration                                                    |
| `test`     | Adding or correcting tests                                                                             |
| `chore`    | Changes to the build process or auxiliary tools and libraries such as documentation generation         |
| `revert`   | Reverts a previous commit                                                                              |
| `hotfix`   | A hot fix for a specific issue                                                                         |

| scope                        | description                                              |
|------------------------------|----------------------------------------------------------|
| `<module>-<cpp or d>`        | C++/D (cpp for C++ and d for D) `oe.<module>` changes.   |
| `docs-api`                   | Documentation (Documentation Comments) changes.          |
| `docs-pages`                 | Pages changes in Zensical Documentations.                |
| `cmake`                      | CMake BuildScripts change.                               |
| `meson`                      | Meson BuildScripts change.                               |
| `bazel`                      | Bazel BuildScripts change.                               |
| `xmake`                      | XMake BuildScripts change.                               |
| `github-ci`                  | GitHub CI changes.                                       |
| Others (scope is not strict) | Other changes that do not fit into the above categories. |

#### Commit Body Format {#commit-body-format}

Just as in the summary, use the imperative, present tense: "fix" not "fixed" nor "fixes".

Explain the motivation for the change in the commit message body. This commit message should explain why you are making the change. You can include a comparison of the previous behavior with the new behavior in order to illustrate the impact of the change.

#### Commit Footer Format {#commit-footer-format}

The footer can contain information about breaking changes and deprecations and is also the place to reference GitHub issues and other PRs that this commit closes or is related to.
For example:

```
BREAKING CHANGE: <breaking change summary>
<BLANK LINE>
<breaking change description + migration instructions>
<BLANK LINE>
<BLANK LINE>
Fixes #<issue number>
```

or

```
DEPRECATED: <what is deprecated>
<BLANK LINE>
<deprecation description + recommended update path>
<BLANK LINE>
<BLANK LINE>
Closes #<pr number>
```

Breaking Change section should start with the phrase `BREAKING CHANGE: ` followed by a _brief_ summary of the breaking change, a blank line, and a detailed description of the breaking change that also includes migration instructions.

Similarly, a Deprecation section should start with `DEPRECATED: ` followed by a short description of what is deprecated, a blank line, and a detailed description of the deprecation that also mentions the recommended update path.

### Revert commits

If the commit reverts a previous commit, it should begin with `revert: `, followed by the header of the reverted commit.

The content of the commit message body should contain:

- information about the SHA of the commit being reverted in the following format: `This reverts commit <SHA>`,
- a clear description of the reason for reverting the commit message.
