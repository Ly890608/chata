cmake_minimum_required( VERSION 3.12...3.15 )

project( chata
         VERSION 1.0
		 DESCRIPTION "Base libraries")

if ( CHATA_STATIC_LIB )
    message("Build static library")
    add_compile_definitions( CHATA_STATIC )
    add_library( chata STATIC )
else()
    message("Build shared library")
    add_compile_definitions( CHATA_EXPORT )
    add_library( chata SHARED )
endif()
	
target_sources( chata
	PRIVATE     "base/Math.cpp"
    PUBLIC      "../include/chata/base/CommonMacros.h"
				"../include/chata/base/CompilerMacros.h"
				"../include/chata/base/Export.h"
				"../include/chata/base/IntTypes.h"
				"../include/chata/base/Math.h"
			    "../include/chata/base/MathConstant.h"
			    "../include/chata/base/PlatformMacros.h" )

target_include_directories( chata PUBLIC "../include" )
	
target_compile_features( chata PUBLIC cxx_std_14 )

add_library( library::chata ALIAS chata )

set_target_properties( chata
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )

if ( MSVC )
	set_target_properties( chata
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/release"
		LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/release"
		RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/release"
		ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/debug"
		LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/debug"
		RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/debug" )
endif()