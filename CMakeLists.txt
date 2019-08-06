cmake_minimum_required( VERSION 3.12...3.13 )

project( chata
         VERSION 1.0
		 DESCRIPTION "c++ utilities" )
		 
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

option( CHATA_STATIC_LIB "Build static library" TRUE )

add_subdirectory( external )

add_subdirectory( src )

add_subdirectory( app )