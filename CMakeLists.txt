# Date: 2017-09-28
# Author: Ruggero Vasile

project ( pathplanningalgorithms )
cmake_minimum_required ( VERSION 3.5 )

add_definitions(-std=c++11 -g)

option ( BUILD_TESTS "Enable to build the tests" ON )
option ( BUILD_APPLICATIONS "Enable to build the tests" OFF )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall " )

include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}/include )

if ( ${BUILD_TESTS} )
	add_subdirectory( third_party/googletest-release-1.8.0 )
    add_subdirectory ( tests )
endif ()
