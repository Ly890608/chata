cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(TARGET chata)

project(${TARGET}
        VERSION     1.0
	    LANGUAGES   CXX
	    DESCRIPTION "library" 
)

if(CHATA_BUILD_SHARED_LIBS)
    add_library(${TARGET} SHARED)
	target_compile_definitions(${TARGET} PRIVATE CHATA_EXPORT)
else()
    add_library(${TARGET} STATIC)
	target_compile_definitions(${TARGET} PUBLIC CHATA_STATIC)
endif()

target_sources(${TARGET}
	PUBLIC		${CMAKE_CURRENT_SOURCE_DIR}/include/chata/BaseDefines.h
				${CMAKE_CURRENT_SOURCE_DIR}/include/chata/CompilerDefines.h
				${CMAKE_CURRENT_SOURCE_DIR}/include/chata/String.h
                ${CMAKE_CURRENT_SOURCE_DIR}/include/chata/TypeDefines.h
	PRIVATE		${CMAKE_CURRENT_SOURCE_DIR}/src/chata/String.cpp
)

target_link_libraries(${TARGET} 
	PUBLIC	fmt::fmt
			json::json
			mathfu::mathfu
			robinmap::robinmap
)

target_include_directories(${TARGET}
	PUBLIC	"${CMAKE_CURRENT_SOURCE_DIR}/include"
	PRIVATE	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

add_library(chata::${TARGET} ALIAS ${TARGET})

set_target_properties(${TARGET}
	PROPERTIES	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
				LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
				RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" 
)

add_subdirectory(benchmark)
add_subdirectory(test)
