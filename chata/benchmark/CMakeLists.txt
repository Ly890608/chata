cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(TARGET chata-benchmarks)

project(${TARGET} 
		VERSION 1.0
		LANGUAGES CXX
		DESCRIPTION "Benchmark" 
)

add_executable(${TARGET})
target_sources(${TARGET} PRIVATE benchmark_chata.cpp)
target_link_libraries(${TARGET} PRIVATE chata::chata benchmark_main)
