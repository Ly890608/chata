cmake_minimum_required( VERSION 3.10...3.15 )

project( chata
         VERSION 1.0
         LANGUAGES CXX
#		 DESCRIPTION "Main Project" 
)
		 
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

set( CHATA_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

option( CHATA_BUILD_STATIC_LIB "Build static library" ON )
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

add_subdirectory( external )

add_subdirectory( src )

add_subdirectory( app )