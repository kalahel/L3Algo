cmake_minimum_required(VERSION 3.8)
project(session4)
#Version Windows
set(CMAKE_C_STANDARD 99)
#Version linux
#set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        arbreB_Bug.c)

add_executable(session4 ${SOURCE_FILES})