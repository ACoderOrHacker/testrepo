function(oe_properties TARGET TYPE)
    set_target_properties(${TARGET} PROPERTIES
            LINKER_LANGUAGE CXX
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
            COMPILE_WARNING_AS_ERROR ${OE_ENABLE_WERROR})
endfunction()

# ============================================
# Function to define a sub-module library
# ============================================
function(oe_library NAME)
    set(multiValueArgs SOURCES MODULES INCLUDES DEPS OPTIONS)
    cmake_parse_arguments(ARG "" "" "${multiValueArgs}" ${ARGN})

    # Auto-generated shared library option
    string(TOUPPER ${NAME} NAME_UPPER)
    set(shared_option "OE_${NAME_UPPER}_SHARED")
    option(${shared_option} "Build ${NAME} as shared library" OFF)
    if (${${shared_option}})
        set(lib_type SHARED)
    else ()
        set(lib_type STATIC)
    endif ()

    add_library(${NAME} ${lib_type})

    oe_properties(${NAME} LIBRARY)
    target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

    file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/oe/${NAME}/**.cpp)
    file(GLOB_RECURSE LIB_MODULES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/oe/${NAME}/**.ixx ${CMAKE_CURRENT_SOURCE_DIR}/src/oe/${NAME}.ixx)

    target_sources(${NAME}
            PUBLIC FILE_SET CXX_MODULES TYPE CXX_MODULES FILES ${LIB_MODULES} ${ARG_MODULES}
            PUBLIC FILE_SET HEADERS FILES ${ARG_INCLUDES}
            PRIVATE ${LIB_SOURCES} ${ARG_SOURCES})

    if (ARG_DEPS)
        message(STATUS "Found dependencies for ${NAME} target: ${ARG_DEPS}")
        # Ensure module provider targets are built before this consumer to avoid duplicate PCM generation
        foreach (dep IN LISTS ARG_DEPS)
            add_dependencies(${NAME} ${dep})
        endforeach ()
        target_link_libraries(${NAME} PUBLIC ${ARG_DEPS})
    endif ()

    # Handle custom OPTIONS
    set(opt_list ${ARG_OPTIONS})
    while (opt_list)
        list(POP_FRONT opt_list opt_name)
        list(LENGTH opt_list remaining)
        if (remaining GREATER 0)
            list(POP_FRONT opt_list opt_desc)
        else ()
            set(opt_desc "")
        endif ()
        option(${opt_name} "${opt_desc}" OFF)
        if (${${opt_name}})
            target_compile_definitions(${NAME} PRIVATE ${opt_name})
        endif ()
    endwhile ()

    # Register for later main target aggregation
    set_property(GLOBAL APPEND PROPERTY ALL_MODULE_TARGETS ${NAME})

    add_library(oe::${NAME} ALIAS ${NAME})

    message(STATUS "Add module oe::${NAME} for oe")
endfunction()

# ============================================
# Function to define the main (aggregate) library
# ============================================
function(oe_main_library NAME)
    set(multiValueArgs OPTIONS)
    cmake_parse_arguments(ARG "" "" "${multiValueArgs}" ${ARGN})

    get_property(all_subs GLOBAL PROPERTY ALL_MODULE_TARGETS)
    if (NOT all_subs)
        message(FATAL_ERROR "No sub-modules defined before oe_main_library(${NAME})")
    endif ()

    add_library(${NAME} INTERFACE)

    oe_properties(${NAME} MAIN)

    target_link_libraries(${NAME} INTERFACE ${all_subs})

    # Collect all public include directories from sub-modules
    set(all_includes "")
    foreach (sub IN LISTS all_subs)
        get_target_property(inc ${sub} INTERFACE_INCLUDE_DIRECTORIES)
        if (inc)
            list(APPEND all_includes ${inc})
        endif ()
    endforeach ()
    target_include_directories(${NAME} INTERFACE ${all_includes})

    # Apply main-level OPTIONS to all sub-modules
    set(opt_list ${ARG_OPTIONS})
    while (opt_list)
        list(POP_FRONT opt_list opt_name)
        list(LENGTH opt_list remaining)
        if (remaining GREATER 0)
            list(POP_FRONT opt_list opt_desc)
        else ()
            set(opt_desc "")
        endif ()
        option(${opt_name} "${opt_desc}" OFF)
        if (${${opt_name}})
            foreach (sub IN LISTS all_subs)
                target_compile_definitions(${sub} PRIVATE ${opt_name})
            endforeach ()
        endif ()
    endwhile ()

    add_library(oe::${NAME} ALIAS ${NAME})

    message(STATUS "Add main module oe::${NAME}")
endfunction()