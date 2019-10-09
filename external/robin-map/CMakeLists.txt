cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(TARGET robinmap)

project(${TARGET}
        VERSION         0.6.1
		LANGUAGES       CXX
		DESCRIPTION     "C++ implementation of a fast hash map and hash set using robin hood hashing"
#       HOMEPAGE_URL    "https://github.com/Tessil/robin-map" 
)
		 
add_library(${TARGET} INTERFACE)
target_include_directories(${TARGET} INTERFACE include)
add_library(robinmap::${TARGET} ALIAS ${TARGET})
