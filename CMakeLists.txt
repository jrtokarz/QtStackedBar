cmake_minimum_required(VERSION 3.3)
project(QtStackedBar)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt4 REQUIRED QtCore QtGui QtDesigner)

add_executable(QtStackedBar
                main.cpp
                QStackedBar.cpp
                customwidgetplugin.cpp)

target_link_libraries(QtStackedBar
    PRIVATE Qt4::QtCore
    PRIVATE Qt4::QtGui
    PRIVATE Qt4::QtDesigner)
