cmake_minimum_required(VERSION 3.28)

project(OE)

# Requirements
# We use CPM.cmake to fetch 3rd-libraries

include(cmake/CPM.cmake)
include(cmake/oe_library.cmake)

# Global options

option(OE_ENABLE_TESTING "Enable testing for OE" OFF)
option(OE_ENABLE_BENCHMARKS "Enable benchmarks for OE" OFF)
option(OE_ENABLE_FUZZING "Enable fuzzing for OE" OFF)
option(OE_ENABLE_WERROR "Enable -Werror for OE targets" ON)
option(OE_SHARED "Build OE as shared library" OFF)
# TODO: OE_SHARED is not available now, add OE_SHARED actions

# Targets

oe_library(base)
oe_library(types
        DEPS base
)

oe_main_library(oe
        OPTIONS OE_ENABLE_EXCEPTION_SUPPORTS " Enable exception supports"
)

# Tests

if (OE_ENABLE_TESTING)
    message(STATUS "Enabled tests")

    # Include oe_test to define a test instance
    include(CTest)
    include(cmake/oe_test.cmake)

    enable_testing()

    oe_test(types)
endif ()

# Benchmarks

if (OE_ENABLE_BENCHMARKS)
    message(STATUS "Enabled benchmarks")

    # Include oe_benchmark to define a benchmark instance
    include(cmake/oe_benchmark.cmake)
endif ()

# Fuzzing

if (OE_ENABLE_FUZZING)
    message(STATUS "Enabled fuzzing")

    include(cmake/oe_fuzzing.cmake)
    oe_fuzz(types)
endif ()
