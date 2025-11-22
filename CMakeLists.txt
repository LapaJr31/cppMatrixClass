cmake_minimum_required(VERSION 3.27)
project(matrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_executable(${PROJECT_NAME} matrix.cpp)