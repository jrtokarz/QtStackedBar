cmake_minimum_required(VERSION 3.3)
project(QStackedBar)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt4 REQUIRED QtCore QtGui QtDesigner)

add_library(${PROJECT_NAME} SHARED
			QStackedBar.cpp
			customwidgetplugin.cpp)

target_link_libraries(${PROJECT_NAME}
    PUBLIC Qt4::QtCore
    PUBLIC Qt4::QtGui
    PUBLIC Qt4::QtDesigner)

add_executable(stackedbar_test
                main.cpp)

target_link_libraries(stackedbar_test
	PRIVATE QStackedBar)

