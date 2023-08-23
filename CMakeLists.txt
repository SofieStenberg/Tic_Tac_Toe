cmake_minimum_required(VERSION 3.16)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic -pedantic -errors -O0 -Werror)

add_executable(Tic_Tac_Toe source/main.cpp source/Tic_Tac_Toe.cpp include/Tic_Tac_Toe.h)
include_directories(include)