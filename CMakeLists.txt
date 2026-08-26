cmake_minimum_required(VERSION 3.28)

project(OE)

include(FetchContent)

# Options

option(OE_SHARED "Build shared library" ON)
option(OE_ENABLE_EXCEPTION_SUPPORTS "Enable exception supports" OFF)
option(OE_BUILD_FUZZERS "Build libFuzzer targets" OFF)
option(OE_BUILD_BENCHMARKS "Build Google Benchmark targets" OFF)

file(GLOB_RECURSE OE_LIBRARY_INCLUDES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/**.h" "include/**.hpp")
file(GLOB_RECURSE OE_LIBRARY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp")
file(GLOB_RECURSE OE_LIBRARY_MODULES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/**.ixx")

if (OE_SHARED)
    add_library(oe SHARED)
    target_compile_definitions(oe PUBLIC OE_SHARED)
else ()
    add_library(oe STATIC)
endif ()

set_target_properties(oe PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        COMPILE_WARNING_AS_ERROR TRUE)

target_include_directories(oe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(oe
        PUBLIC FILE_SET CXX_MODULES FILES ${OE_LIBRARY_MODULES}
        PUBLIC FILE_SET HEADERS FILES ${OE_LIBRARY_INCLUDES}
        PRIVATE ${OE_LIBRARY_SOURCES})

# Tests & Benchmarks Frameworks

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
        GIT_SHALLOW ON
)

FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.9.5
        GIT_SHALLOW ON
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_WERROR OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest benchmark)

# Tests

function(add_oe_test NAME)
    set(options "")
    set(oneValueArgs NAME USE_GTEST_MAIN USE_BENCHMARK_MAIN)
    set(multiValueArgs "")
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if (NOT DEFINED ARG_USE_GTEST_MAIN)
        set(ARG_USE_GTEST_MAIN ON)
        set(ARG_USE_BENCHMARK_MAIN ON)
    endif ()

    set(SOURCE_FILES "")

    set(MAIN_TEST_FILE "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_${NAME}.cpp")
    if (EXISTS "${MAIN_TEST_FILE}")
        list(APPEND SOURCE_FILES "${MAIN_TEST_FILE}")
        message(STATUS "Found test file: ${MAIN_TEST_FILE}")
    else ()
        message(STATUS "Note: ${MAIN_TEST_FILE} not found.")
    endif ()

    set(LIB_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests/${NAME}")
    if (EXISTS "${LIB_SOURCE_DIR}")
        file(GLOB LIB_SOURCES CONFIGURE_DEPENDS "${LIB_SOURCE_DIR}/*.cpp")
        list(APPEND SOURCE_FILES ${LIB_SOURCES})
        message(STATUS "Found library sources in: ${LIB_SOURCE_DIR}")
    endif ()

    if (NOT SOURCE_FILES)
        message(WARNING "No source files found for target ${NAME}_test. Target skipped.")
        return()
    endif ()

    add_executable(${NAME}_test ${SOURCE_FILES})

    target_link_libraries(${NAME}_test
            PRIVATE
            oe
            GTest::gtest
            GTest::gmock
            benchmark::benchmark
    )

    if (ARG_USE_GTEST_MAIN)
        target_link_libraries(${NAME}_test PRIVATE GTest::gtest_main)
        message(STATUS "Linking GTest::gtest_main for ${NAME}_test")
    else ()
        message(STATUS "Skipping GTest::gtest_main for ${NAME}_test")
    endif ()

    if (ARG_USE_GTEST_MAIN)
        target_link_libraries(${NAME}_test PRIVATE benchmark::benchmark_main)
        message(STATUS "Linking benchmark::benchmark_main for ${NAME}_test")
    else ()
        message(STATUS "Skipping benchmark::benchmark_main for ${NAME}_test")
    endif ()

    target_include_directories(${NAME}_test
            PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/tests
    )

    set_target_properties(${NAME}_test PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )

    include(GoogleTest)
    gtest_discover_tests(${NAME}_test)
endfunction()

enable_testing()

add_oe_test(types)

if (OE_BUILD_FUZZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_executable(oe_fuzz_types tests/fuzz_types.cpp)
    target_link_libraries(oe_fuzz_types PRIVATE oe)
    target_compile_options(oe_fuzz_types PRIVATE -fsanitize=fuzzer,address,undefined)
    target_link_options(oe_fuzz_types PRIVATE -fsanitize=fuzzer,address,undefined)
    set_target_properties(oe_fuzz_types PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )
endif ()

if (OE_BUILD_BENCHMARKS)
    add_executable(oe_benchmarks benchmarks/benchmarks.cpp)
    target_link_libraries(oe_benchmarks PRIVATE benchmark::benchmark)
    set_target_properties(oe_benchmarks PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )
endif ()
