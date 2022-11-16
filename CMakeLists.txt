cmake_minimum_required(VERSION 3.21)
project(term C)

set(CMAKE_C_STANDARD 99)

add_executable(term main.c main.h minseok_function.c minseok_header.h LIM.h "search_hyukjin.c" gyeongwon_function.c gyeongwon_header.h minjun_function.c minjun_header.h)