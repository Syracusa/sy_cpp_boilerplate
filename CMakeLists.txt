cmake_minimum_required(VERSION 3.16)

project(sy_cpp_boilerplate)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

include_directories(include)

add_executable(rsock examples/ex_rawsock.cpp lib/sock.cpp)

add_executable(map examples/ex_stl_map.cpp)