cmake_minimum_required(VERSION 3.0)

project(find)

add_executable(find main.cpp)

install(TARGETS find RUNTIME DESTINATION bin)
