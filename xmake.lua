--- OE xmake configuration ---
--- Copyright (C) ACoderOrHacker

set_xmakever("2.2.5")
set_project("OE")
set_license("Apache-2.0")

add_includedirs("include")

--- set languages ---
set_languages("c++17")

--- compile_commands generation ---
add_rules("plugin.compile_commands.autoupdate", { outputdir = "build" })

--- modes ---

add_rules("mode.debug", "mode.release")

if is_mode("debug") then
    add_defines("OE_DEBUG")
end

--- configfiles ---
set_configdir("$(projectdir)")
add_configfiles("include/oe/oe/configs.h.in",
    { prefixdir = "include/oe/oe" })

--- build options ---

option("shared")
    set_default(false)
    set_showmenu(true)
    set_description("Build shared library")
    add_defines("OE_SHARED")
option_end()

includes("xmake/libs.lua")
local libs = libs_string:split(";")
for _, name in ipairs(libs) do
    option(name)
        set_default(true)
        set_showmenu(true)
        set_category("modules")
        set_description("Build with " .. name .. "(only for C++)")
        set_configvar("OE_" .. name:upper() .. "ENABLED", 1)
    option_end()
end

option("langcpp")
    set_default(true)
    set_showmenu(true)
    set_description("Build C++ OE target")

    target("oecpp")
        add_options("shared")
        if has_config("shared") then
            set_kind("shared")
            add_rules("utils.symbols.export_all")
        else
            set_kind("static")
        end

        add_headerfiles("include/(**.hpp)")
        add_files("src/**.cpp")

        add_rules("utils.install.cmake_importfiles")
        add_rules("utils.install.pkgconfig_importfiles")
    target_end()
option_end()

option("langd")
    set_default(false)
    set_showmenu(true)
    set_description("Build D OE target")

    target("oed")
        add_options("shared")
        if has_config("shared") then
            set_kind("shared")
            add_rules("utils.symbols.export_all")
        else
            set_kind("static")
        end

        add_headerfiles("source/(**.d)")
    target_end()
option_end()



--- tests and benchmarks ---

option("cpptests")
    set_default(false)
    set_showmenu(true)
    set_description("Build C++ tests")
option_end()

if has_config("cpptests") then
    add_requires("gtest 1.17.0", { alias = "gtest" })
    target("testcpp")
        set_kind("binary")

        add_files("tests/*.cpp")
        add_deps("oecpp")
        add_packages("gtest")
        add_tests("default")
    target_end()
end

option("dtests")
    set_default(false)
    set_showmenu(true)
    set_description("Build D tests")
option_end()

if has_config("dtests") then
    target("testd")
        set_kind("binary")

        add_files("tests/test.d")
        add_deps("oed")
        add_tests("default")
    target_end()
end

option("cppbench")
    set_default(false)
    set_showmenu(true)
    set_description("Build C++ benchmarks")
option_end()

if has_config("cppbench") then
    add_requires("benchmark 1.9.5", { alias = "benchmark" })
    target("benchmarks_cpp")
        set_kind("binary")

        add_files("benchmarks/*.cpp")
        add_deps("oecpp")
        add_packages("benchmark")
        add_tests("default")
    target_end()
end

option("dbench")
    set_default(false)
    set_showmenu(true)
    set_description("Build D benchmarks")
option_end()

if has_config("dbench") then
    target("benchmarks_d")
        set_kind("binary")

        add_files("benchmarks/*.d")
        add_deps("oed")
        add_tests("default")
    target_end()
end
