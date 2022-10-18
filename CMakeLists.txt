cmake_minimum_required(VERSION 3.16)

project(sy_cpp_boilerplate)

include_directories(include)

add_executable(rsock examples/ex_rawsock.cpp lib/sock.cpp)

# add_executable(rsock examples/ex_rawsock.cpp lib/sock.cpp)