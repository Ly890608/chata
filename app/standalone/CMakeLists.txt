cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(TARGET standalone)

project(${TARGET} 
		VERSION 1.0
		LANGUAGES CXX
		DESCRIPTION "Standalone For Windows" 
)

add_executable(${TARGET})
target_sources(${TARGET} PRIVATE main.cpp)
target_link_libraries(${TARGET} PRIVATE chata::chata)

set_target_properties(${TARGET}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
