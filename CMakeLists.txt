project(calculator)
cmake_minimum_required(VERSION 2.8)

find_library(CPPUNIT_LIBRARY cppunit)

set(SRC_LIST
	src/operatornode.cpp
)

set(SRC_TEST_LIST
)

set(CMAKE_CXX_FLAGS_COMMON "-Wall -Wextra -Werror -ansi -g")

include_directories(
	${CMAKE_SOURCE_DIR}/incl
)

add_executable(${PROJECT_NAME} ${SRC_LIST} src/main.cpp)
add_executable(testrunner ${SRC_LIST} ${SRC_TEST_LIST} src/testrunner.cpp)
target_link_libraries(testrunner ${CPPUNIT_LIBRARY})