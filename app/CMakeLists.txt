cmake_minimum_required( VERSION 3.10...3.15 )

set( TARGET app )

project( ${TARGET} 
		 VERSION 1.0
		 LANGUAGES CXX
#		 DESCRIPTION "Example Application for chata"
)
		 
add_executable( ${TARGET} )
target_sources( ${TARGET} PRIVATE "src/main.cpp" )
target_link_libraries( ${TARGET} PRIVATE library::chata )
target_compile_features( ${TARGET} PUBLIC cxx_std_17 )
		
set_target_properties( ${TARGET}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" 
)
		
if ( MSVC )
	set_target_properties( ${TARGET}
		PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/release"
		LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/lib/release"
		RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/release"
		ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/debug"
		LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/lib/debug"
		RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/debug" 
	)
endif()