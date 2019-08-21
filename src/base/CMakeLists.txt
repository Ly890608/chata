cmake_minimum_required( VERSION 3.10...3.15 )

set( TARGET chata )

project( ${TARGET}
		 VERSION 1.0
		 LANGUAGES CXX
#		 DESCRIPTION "Libraries Chata"
)

set( SRCS
        Chata.cpp
)

set( PUBLIC_HEADER
    ${PROJECT_ROOT}/include/chata/base/Chata.h
    ${PROJECT_ROOT}/include/chata/base/CommonMacros.h
    ${PROJECT_ROOT}/include/chata/base/CompilerMacros.h
    ${PROJECT_ROOT}/include/chata/base/IntTypes.h
    ${PROJECT_ROOT}/include/chata/base/MathConstant.h
    ${PROJECT_ROOT}/include/chata/base/PlatformMacros.h
)

if ( CHATA_STATIC_LIB )
    message("Build static library")
    add_library( ${TARGET} STATIC ${SRCS} ${PUBLIC_HEADERS} )
    target_compile_definitions( ${TARGET} PUBLIC CHATA_STATIC )
else()
    message("Build shared library")
    add_library( ${TARGET} SHARED ${SRCS} ${PUBLIC_HEADERS} )
    target_compile_definitions( ${TARGET} PRIVATE CHATA_EXPORT )
endif()

target_include_directories( ${TARGET} PUBLIC "${PROJECT_ROOT}/include" )
	
target_compile_features( ${TARGET} PUBLIC cxx_std_17 )

add_library( library::${TARGET} ALIAS ${TARGET} )

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