cmake_minimum_required(VERSION 3.14)
project(__)

set(CMAKE_CXX_STANDARD 17)

add_executable(__ main.cpp token.cpp token.h condition_parser.h condition_parser.cpp condition_parser_test.cpp database.cpp database.h date.h date.cpp node.h node.cpp test_runner.h database_test.cpp database_test.h)