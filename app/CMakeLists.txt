cmake_minimum_required( VERSION 3.12...3.13 )

project( app 
         VERSION 1.0
		 DESCRIPTION "Example project for chata" )
		 
if ( CHATA_STATIC_LIB )
    add_compile_definitions( CHATA_STATIC )
endif()
		 
add_executable( app )
target_sources( app PRIVATE "src/main.cpp" )
target_link_libraries( app PRIVATE library::chata )
target_compile_features( app PUBLIC cxx_std_14 )
		
set_target_properties( app
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
		
if ( MSVC )
	set_target_properties( app
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/release"
		LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/release"
		RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/release"
		ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/debug"
		LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/debug"
		RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/debug" )
endif()