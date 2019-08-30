cmake_minimum_required( VERSION 3.1...3.15 )

if( ${CMAKE_VERSION} VERSION_LESS 3.12 )
    cmake_policy( VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} )
endif()

project( chata )

set( CMAKE_POSITION_INDEPENDENT_CODE ON )

include( CheckIPOSupported )
    check_ipo_supported( RESULT result )
if( result )
    set( CHATA_IPO_SUPPORTED ON )
else()
    set( CHATA_IPO_SUPPORTED OFF )
endif()

set( CHATA_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

option( CHATA_BUILD_STATIC_LIB "Build static library" OFF )
option( CHATA_LINK_USE_STATIC_CRT "Link against the static runtime libraries." ON )

if( WIN32 )
    if ( ${CHATA_LINK_USE_STATIC_CRT} )
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

message( STATUS "CHATA_IPO_SUPPORTED=${CHATA_IPO_SUPPORTED}" )
message( STATUS "CHATA_BUILD_STATIC_LIB=${CHATA_BUILD_STATIC_LIB}" )
message( STATUS "CHATA_LINK_USE_STATIC_CRT=${CHATA_LINK_USE_STATIC_CRT}" )

add_subdirectory( external )

add_subdirectory( src )

add_subdirectory( app )