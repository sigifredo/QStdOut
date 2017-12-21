project(QStdOut)
cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt5 COMPONENTS Core Widgets Network Quick MultimediaWidgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(include)

set (MOC_HDRS
include/Window.hpp
)

set (SRCS
src/CustomStream.cpp
src/Window.cpp
src/main.cpp
)

qt5_wrap_cpp(MOC_SRCS ${MOC_HDRS})

add_executable(stream ${MOC_SRCS} ${SRCS})

qt5_use_modules(stream Widgets Core)
