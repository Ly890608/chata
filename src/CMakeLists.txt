cmake_minimum_required( VERSION 3.1...3.15 )

if( ${CMAKE_VERSION} VERSION_LESS 3.12 )
    cmake_policy( VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} )
endif()

set( TARGET chata )

project( ${TARGET}
		 VERSION 1.0
		 LANGUAGES CXX
		 DESCRIPTION "Library Chata"
		 HOMEPAGE_URL "https://github.com/lyLoveSharon/chata"
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
	PUBLIC 		$<BUILD_INTERFACE:${CHATA_ROOT}/include>
				$<INSTALL_INTERFACE:include>
	PRIVATE		${CHATA_ROOT}/src
)

if( CHATA_IPO_SUPPORTED )
	set_target_properties( ${TARGET} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

target_compile_features( ${TARGET} PUBLIC cxx_std_17 )

add_library( library::${TARGET} ALIAS ${TARGET} )

set_target_properties( ${TARGET}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" 
)