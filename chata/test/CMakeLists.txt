cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(TARGET chata-tests)

project(${TARGET} 
		VERSION 1.0
		LANGUAGES CXX
		DESCRIPTION "Unit Test" 
)

add_executable(${TARGET})
target_sources(${TARGET} 
                PRIVATE StringTest.cc
                        unittest.cc)
target_link_libraries(${TARGET} PRIVATE chata::chata gtest gtest_main)
