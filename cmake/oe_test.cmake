# Tests Frameworks
# Using GoogleTest

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
        GIT_SHALLOW ON
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# ============================================
# Function to define the test
# ============================================
function(oe_test NAME)
    set(options "")
    set(oneValueArgs NAME USE_GTEST_MAIN)
    set(multiValueArgs "")
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if (NOT DEFINED ARG_USE_GTEST_MAIN)
        set(ARG_USE_GTEST_MAIN ON)
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
            oe::${NAME} # Link the tested module
            GTest::gtest
            GTest::gmock
    )

    if (ARG_USE_GTEST_MAIN)
        target_link_libraries(${NAME}_test PRIVATE GTest::gtest_main)
        message(STATUS "Linking GTest::gtest_main for ${NAME}_test")
    else ()
        message(STATUS "Skipping GTest::gtest_main for ${NAME}_test")
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
    add_test(NAME "Test ${NAME}" COMMAND ${NAME}_test)

    message(STATUS "Add ${NAME} test for oe::${NAME}")
endfunction()