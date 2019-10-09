cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(TARGET json)

project(${TARGET}
        VERSION         3.7.0
		LANGUAGES       CXX
		DESCRIPTION     "JSON for Modern C++"
#       HOMEPAGE_URL    "https://github.com/nlohmann/json" 
)
		 
add_library(${TARGET} INTERFACE)
target_include_directories(${TARGET} INTERFACE include)
add_library(json::${TARGET} ALIAS ${TARGET})
