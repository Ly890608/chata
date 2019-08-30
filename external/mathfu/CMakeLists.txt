cmake_minimum_required( VERSION 3.1...3.15 )

if( ${CMAKE_VERSION} VERSION_LESS 3.12 )
    cmake_policy( VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} )
endif()

set( TARGET mathfu )

project( ${TARGET}
         VERSION 1.1.0
		 LANGUAGES CXX
		 DESCRIPTION "C++ math library developed primarily for games focused on simplicity and efficiency."
         HOMEPAGE_URL "https://github.com/google/mathfu" 
)

set( mathfu_build_benchmarks OFF CACHE BOOL "" )
set( mathfu_build_tests OFF CACHE BOOL "" )

add_library( ${TARGET} INTERFACE )
target_include_directories( ${TARGET} INTERFACE include )

target_include_directories( ${TARGET} 
    INTERFACE	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
				$<INSTALL_INTERFACE:include>
)

add_library( External::${TARGET} ALIAS ${TARGET} )