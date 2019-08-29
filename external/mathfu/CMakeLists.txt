cmake_minimum_required( VERSION 3.10...3.15 )

set( TARGET mathfu )

project( ${TARGET}
         VERSION 1.1.0
		 LANGUAGES CXX
#		 DESCRIPTION "C++ math library developed primarily for games focused on simplicity and efficiency."
#        HOMEPAGE_URL "https://github.com/google/mathfu" 
)

set(mathfu_build_benchmarks OFF CACHE BOOL "")
set(mathfu_build_tests OFF CACHE BOOL "")

add_library( ${TARGET} INTERFACE )
target_include_directories( ${TARGET} INTERFACE include )
add_library( External::${TARGET} ALIAS ${TARGET} )