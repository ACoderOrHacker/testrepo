# Benchmarks Framework
# Using Google Benchmark

include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

set(BENCHMARK_ENABLE_WERROR OFF CACHE BOOL "" FORCE)
set(BENCHMARK_FORCE_WERROR OFF CACHE BOOL "" FORCE)
CPMAddPackage(
        NAME benchmark
        GITHUB_REPOSITORY google/benchmark
        VERSION 1.9.5
        OPTIONS
        "BENCHMARK_ENABLE_TESTING OFF"
        "BENCHMARK_ENABLE_WERROR OFF"
        "BENCHMARK_FORCE_WERROR OFF"
)

if (TARGET benchmark)
    target_compile_options(benchmark PRIVATE
            $<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-Wno-error>
            $<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-Wno-sign-conversion>
    )
endif ()

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/benchmarks/benchmarks.cpp")
    add_executable(oe_benchmarks
            "${CMAKE_CURRENT_SOURCE_DIR}/benchmarks/benchmarks.cpp"
    )
    target_link_libraries(oe_benchmarks
            PRIVATE
            benchmark::benchmark
    )
    target_include_directories(oe_benchmarks
            PRIVATE
            "${CMAKE_CURRENT_SOURCE_DIR}/include"
            "${CMAKE_CURRENT_SOURCE_DIR}/benchmarks"
    )
    set_target_properties(oe_benchmarks PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )
endif ()

# ============================================
# Function to define the benchmark
# ============================================
function(oe_benchmark NAME)
    set(options "")
    set(oneValueArgs NAME USE_BENCHMARK_MAIN)
    set(multiValueArgs "")
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if (NOT DEFINED ARG_USE_BENCHMARK_MAIN)
        set(ARG_USE_BENCHMARK_MAIN ON)
    endif ()

    set(SOURCE_FILES "")

    set(MAIN_BENCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/benchmarks/benchmark_${NAME}.cpp")
    if (EXISTS "${MAIN_BENCH_FILE}")
        list(APPEND SOURCE_FILES "${MAIN_BENCH_FILE}")
        message(STATUS "Found benchmark file: ${MAIN_BENCH_FILE}")
    else ()
        message(STATUS "Note: ${MAIN_BENCH_FILE} not found.")
    endif ()

    set(LIB_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/benchmarks/${NAME}")
    if (EXISTS "${LIB_SOURCE_DIR}")
        file(GLOB LIB_SOURCES CONFIGURE_DEPENDS "${LIB_SOURCE_DIR}/*.cpp")
        list(APPEND SOURCE_FILES ${LIB_SOURCES})
        message(STATUS "Found library sources in: ${LIB_SOURCE_DIR}")
    endif ()

    if (NOT SOURCE_FILES)
        message(WARNING "No source files found for target ${NAME}_benchmark. Target skipped.")
        return()
    endif ()

    add_executable(${NAME}_benchmark ${SOURCE_FILES})

    target_link_libraries(${NAME}_benchmark
            PRIVATE
            oe::${NAME}
            benchmark::benchmark
    )

    if (ARG_USE_BENCHMARK_MAIN)
        target_link_libraries(${NAME}_benchmark PRIVATE benchmark::benchmark_main)
        message(STATUS "Linking benchmark::benchmark_main for ${NAME}_benchmark")
    else ()
        message(STATUS "Skipping benchmark::benchmark_main for ${NAME}_benchmark")
    endif ()

    target_include_directories(${NAME}_benchmark
            PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/benchmarks
    )

    set_target_properties(${NAME}_benchmark PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )

    add_test(NAME "Benchmark ${NAME}" COMMAND ${NAME}_benchmark)

    message(STATUS "Add ${NAME} benchmark for oe::${NAME}")
endfunction()
