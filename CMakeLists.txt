cmake_minimum_required(VERSION 3.16)

project(sy_cpp_boilerplate)

include_directories(include)

add_executable(rsock testapp/t_rsock.cpp src/sock.cpp)
