cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Project
project(chata
        VERSION     1.0
	    LANGUAGES   CXX
	    DESCRIPTION "project chata" 
)

# Options
option(CHATA_BUILD_SHARED_LIBS "build chata as a shared library" OFF)

# Settings
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(DEFAULT_BUILD_TYPE "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING 
            "Choose the type of build." 
            FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS 
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}" CACHE STRING
            "The install location"
            FORCE)
    message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# IDEs Friendly
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Compiler Flags
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD "-std=c++17")
if (WIN32)
    set(CXX_STANDARD "/std:c++17")
endif()

# OS specific
if(WIN32)
    option(CHATA_LINK_USE_STATIC_CRT "Link against the static runtime libraries." ON)
    if (${CHATA_LINK_USE_STATIC_CRT})
        add_compile_options(
            $<$<CONFIG:>:/MT>
            $<$<CONFIG:Debug>:/MTd>
            $<$<CONFIG:Release>:/MT>
        )
    else()
        add_compile_options(
            $<$<CONFIG:>:/MD>
            $<$<CONFIG:Debug>:/MDd>
            $<$<CONFIG:Release>:/MD>
        )
    endif()
endif()

# Optimize
include(CheckIPOSupported)
check_ipo_supported(RESULT IPO_SUPPORT)
if(IPO_SUPPORT)
    message(STATUS "LTO support is enabled")
    set_property(GLOBAL PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

find_program(CCACHE_FOUND "ccache")
if(CCACHE_FOUND)
    message(STATUS "Using ccache for building.")
    set_property(GLOBAL PROPERTY LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

# Module
add_subdirectory(external)
add_subdirectory(chata)
add_subdirectory(app)

# Test (ctest --verbose)
enable_testing()
add_test(NAME chata-tests COMMAND chata-tests)
add_test(NAME chata-benchmarks COMMAND chata-benchmarks)
