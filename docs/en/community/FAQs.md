---
title: FAQs
description: OE FAQs
icon: material/help-circle

comments: true

tags:
    - Community
    - FAQs
---

<!-- Copyright (C) 2026 ACoderOrHacker. All rights reserved. -->

# FAQs

## Contents

* [**Why we create `OE`?**](#why-we-create-oe)

* [**What are our goals?**](#what-are-our-goals)

* [**What `OE` libraries we provide?**](#oe-libraries)

* [**Can it be high speed with these modern designs?**](#can-it-be-high-speed)

* [**Can OE/C++ be used in less C++20?**](#can-oe-cpp-be-used-in-less-cpp20)

* [**Will OE/C++ support C++ Exceptions?**](#will-oe-cpp-support-cpp-exceptions)

* [**Will OE/C++ always update its C++ Standard?**](#will-oe-cpp-always-update-its-cpp-standard)

* [**What versioning that we use?**](#what-versioning-that-we-use)

## Why we create `OE`? {#why-we-create-oe}

The lack of a standard library and the inconsistency of third-party libraries pushed us to create this library
collection. More importantly, some libraries that meet the requirements often don't comply with **Our Coding Guidelines**
(for example, using exceptions in C++).

## What are our goals? {#what-are-our-goals}

Our goals are to be a **powerful** toolkits that include anything you need in coding.

And you can build your apps fast and safer with our good designs.

## What `OE` libraries we provide? {#oe-libraries}

I/O, Network, String, Containers, JSON/XML/..., Serialization... with modern concepts, fast implementations and zero-overhead.

We provide all you need.

## Can it be high speed with these modern designs? {#can-it-be-high-speed}

No, we will keep it fast and easy to use. For APIs that can't be improved, we also give less-modern APIs or low-level APIs to help you improve speed.

## Can OE/C++ be used in less C++20? {#can-oe-cpp-be-used-in-less-cpp20}

Mostly no, it's built with modules. You should upgrade your C++ Standard.
But for some of the features can be used, see the following list:

- include/preprocessor/*: most of the macros can be used in all the C++ standards or even C.
- include/detections/*: can be used in all the C++ standards and C standards, have extra supports for C.
- include/meta/*: can be used in all the C++ standards, but never use them because they are **deprecated**.
- include/api.h, include/configs.h: can be used in C/C++.
- And so on...

## Will OE/C++ support C++ Exceptions? {#will-oe-cpp-support-cpp-exceptions}

Yes, but not in library implementations and APIs. They are only giving some helpers for you to write better exception-based codes or help you wrap from exceptions.
But OE/C++ will never encourage you to use exceptions.

See [Our C++ Coding Guidelines](guidelines/code_guidelines_cpp.md#Exceptions) for more details.

## Will OE/C++ always update its C++ Standard? {#will-oe-cpp-always-update-its-cpp-standard}

No, we will just update at big features coming out from C++ Newer Standards.

And old APIs will be marked **deprecated** and be removed at the next major version updating.

## What versioning that we use? {#what-versioning-that-we-use}

We use [Semantic Versioning Specification](https://semver.org/) to manage the version.

We follow the specification strictly.
