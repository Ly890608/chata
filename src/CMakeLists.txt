cmake_minimum_required( VERSION 3.10...3.15 )

set( TARGET chata )

project( ${TARGET}
		 VERSION 1.0
		 LANGUAGES CXX
#		 DESCRIPTION "Library Chata"
)

if ( CHATA_BUILD_STATIC_LIB )
    add_library( ${TARGET} STATIC ${SRCS} )
    target_compile_definitions( ${TARGET} PUBLIC CHATA_STATIC )
else()
    add_library( ${TARGET} SHARED ${SRCS} )
    target_compile_definitions( ${TARGET} PRIVATE CHATA_EXPORT )
endif()

target_sources( ${TARGET}
	PUBLIC		${CHATA_ROOT}/include/chata/base/CommonMacros.h
				${CHATA_ROOT}/include/chata/base/CompilerMacros.h
				${CHATA_ROOT}/include/chata/base/Export.h
				${CHATA_ROOT}/include/chata/base/IntTypes.h
				${CHATA_ROOT}/include/chata/base/MathUtils.h
				${CHATA_ROOT}/include/chata/base/PlatformMacros.h
				${CHATA_ROOT}/include/chata/system/Process.h
)

if (WIN32)
	target_sources( ${TARGET}
		PRIVATE		chata/system/ProcessWindows.cpp
		PRIVATE		chata/windows/MinWindows.h
	)
endif()

target_include_directories( ${TARGET} 
	PUBLIC 		"${CHATA_ROOT}/include"
	PRIVATE		"${CHATA_ROOT}/src"
)
	
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