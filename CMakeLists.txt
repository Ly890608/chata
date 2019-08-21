cmake_minimum_required( VERSION 3.10...3.15 )

set( TARGET ly )

project( ${TARGET}
         VERSION 1.0
         LANGUAGES CXX
#		 DESCRIPTION "Main Project" 
)
		 
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

set( PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

option( CHATA_STATIC_LIB "Build static library" ON )

add_subdirectory( external )

add_subdirectory( src )

add_subdirectory( app )