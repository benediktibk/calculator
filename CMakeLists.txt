project(calculator)
cmake_minimum_required(VERSION 2.8)

find_library(CPPUNIT_LIBRARY cppunit)
find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

set(SRC_LIST
	src/operatornode.cpp
	src/operatortree.cpp
	src/binaryoperatornode.cpp
	src/valueoperatornode.cpp
    src/unaryoperatornode.cpp
)

set(SRC_QT_LIST
	src/mainwindow.cpp
)

set(SRC_TEST_LIST
	src/operatortreetest.cpp
	src/binaryoperatornodetest.cpp
	src/valueoperatornodetest.cpp
)

set(HEADERS_QT_LIST
	incl/mainwindow.h
)

set(FORMS_LIST
	gui/mainwindow.ui
)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE debug)
endif()

set(CMAKE_CXX_FLAGS_COMMON "-Wall -Wextra -Werror -ansi")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_COMMON} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_COMMON} -g")

include_directories(
	${CMAKE_SOURCE_DIR}/incl
	${CMAKE_CURRENT_BINARY_DIR}
)

qt4_wrap_ui(FORMS_HEADERS ${FORMS_LIST})
qt4_wrap_cpp(HEADERS_MOC_LIST ${HEADERS_QT_LIST})

add_executable(${PROJECT_NAME} ${SRC_LIST} ${SRC_QT_LIST} src/main.cpp ${FORMS_HEADERS} ${HEADERS_MOC_LIST})
add_executable(testrunner ${SRC_LIST} ${SRC_TEST_LIST} src/testrunner.cpp)
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
target_link_libraries(testrunner ${CPPUNIT_LIBRARY})
