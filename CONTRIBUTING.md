# Contributing

When contributing to this repository, please first discuss the change you wish to make via issue, email, or any other method with the owners of this repository before making a change.

Please note we have a [code of conduct](CODE_OF_CONDUCT.md), please follow it in all your interactions with the project.

## Development environment setup

See [README](README.md) for building and packaging instructions.

## Issues and feature requests

You've found a bug in the source code, a mistake in the documentation or maybe you'd like a new feature?

Take a look at [GitHub Discussions](https://github.com/ACoderOrHacker/OE/discussions) to see if it's already being discussed.

You can help us by [submitting an issue on GitHub](https://github.com/ACoderOrHacker/OE/issues).

Before you create an issue, make sure to search the issue archive -- your issue may have already been addressed!

Please try to create bug reports that are:

- _Reproducible._ Include steps to reproduce the problem.
- _Specific._ Include as much detail as possible: which version, what environment, etc.
- _Unique._ Do not duplicate existing opened issues.
- _Scoped to a Single Bug._ One bug per report.

**Even better: Submit a pull request with a fix or new feature!**

### How to submit a Pull Request

1. Search our repository for open or closed
   [Pull Requests](https://github.com/ACoderOrHacker/OE/pulls)
   that relate to your submission. You don't want to duplicate effort.
2. Fork the project
3. Write codes as `GitFlow` workflow.
4. [Open a Pull Request](https://github.com/ACoderOrHacker/OE/compare?expand=1)

## Contributing requirements

### Issue reporting

- Check that the issue has not already been reported.
- Check that the issue has not already been fixed in the latest version.
- Be clear and concise in your issue description.
- Be friendly and respectful.
- Include any relevant code snippets or error messages.
- Open a new issue with grammatically correct, complete sentences.

### Pull requests

- No conflicting on the same branch.
- PRs must be good and well-written.
- Commits must be atomic and have clear, descriptive English messages.
- Committing on dev branch is allowed.

### Commit Messages Guidelines

- Use clear, descriptive commit messages.
- Use GitFlow workflow, the GitFlow config is: `master` for main branch, `dev` for develop branch, `feature/` for the prefix of a feature branch, `release/` for the prefix of a release branch, `hotfix/` for the prefix of a hotfix branch.
- Use [Angular commit message format](https://github.com/angular/angular/blob/main/contributing-docs/commit-message-guidelines.md). If you are using `Rebased` or other Intellij-based IDE, use `Git Flow Helper` plugin.

<!-- TODO: Add submodule requires -->

### Code style

- Use clear, descriptive variable names.
- Write clear, concise comments.
- Use DDOX style comments for documenting D code.
- Use doxygen style comments for documenting C/C++ code.
- Macros starts with `OE_`.
- Every C/C++ Interfaces must be written in `oe::<module>::impl`.
- `oe::<module>::details` is for internal use only.
- Every C/C++ functions must add `OE_API` macro to their declaration.
- Use utf-8 encoding
- Snake case naming for naming variables and functions.
- Classes's member variables should be prefixed with `m_`.
- Indentation should be 4 spaces.
- Use clang-format(C/C++) and dfmt(D) to format code.
- Use `types` library when using types like std::uint8_t.
- Use `scripts/add_module.sh` to add a new module.
- Add a config in [metas/configs.json](metas/configs.json) when adding a new config for a module.
