cmake_minimum_required(VERSION 3.21)
project(term C)

set(CMAKE_C_STANDARD 99)

add_executable(term main.c main.h minseok_function.c minseok_header.h gyeongwon_function.c gyeongwon_header.h minjun_function.c minjun_header.h hyukjin_function.c hyukjin_header.h LIM_header.h LIM_function.c)
