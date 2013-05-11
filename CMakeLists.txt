project(calculator)
cmake_minimum_required(VERSION 2.8)

find_library(CPPUNIT_LIBRARY cppunit)

set(SRC_LIST
	src/operatornode.cpp
	src/operatortree.cpp
	src/binaryoperatornode.cpp
	src/valueoperatornode.cpp
)

set(SRC_TEST_LIST
	src/operatortreetest.cpp
	src/binaryoperatornodetest.cpp
	src/valueoperatornodetest.cpp
)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE debug)
endif()

set(CMAKE_CXX_FLAGS_COMMON "-Wall -Wextra -Werror -ansi")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_COMMON} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_COMMON} -g")

include_directories(
	${CMAKE_SOURCE_DIR}/incl
)

add_executable(${PROJECT_NAME} ${SRC_LIST} src/main.cpp)
add_executable(testrunner ${SRC_LIST} ${SRC_TEST_LIST} src/testrunner.cpp)
target_link_libraries(testrunner ${CPPUNIT_LIBRARY})