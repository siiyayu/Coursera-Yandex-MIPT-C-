cmake_minimum_required(VERSION 3.14)
project(_web_)

set(CMAKE_CXX_STANDARD 17)

add_executable(_web_ main.cpp stats.h http_request.h stats.cpp)