# Fuzzing Framework
# Using libFuzzer

function(oe_fuzz NAME)
    set(options "")
    set(oneValueArgs NAME)
    set(multiValueArgs "")
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(FUZZ_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/fuzzing/fuzz_${NAME}.cpp")
    if (NOT EXISTS "${FUZZ_SOURCE}")
        message(WARNING "No fuzz source found for target ${NAME}_fuzz: ${FUZZ_SOURCE}")
        return()
    endif ()

    if (NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(WARNING "Skipping ${NAME}_fuzz: libFuzzer requires Clang")
        return()
    endif ()

    add_executable(${NAME}_fuzz "${FUZZ_SOURCE}")
    target_link_libraries(${NAME}_fuzz PRIVATE oe::${NAME})
    target_compile_options(${NAME}_fuzz PRIVATE -fsanitize=fuzzer,address,undefined)
    target_link_options(${NAME}_fuzz PRIVATE -fsanitize=fuzzer,address,undefined)

    set_target_properties(${NAME}_fuzz PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )

    message(STATUS "Add ${NAME} fuzz target for oe::${NAME}")
endfunction()
