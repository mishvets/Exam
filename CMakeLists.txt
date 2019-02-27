cmake_minimum_required(VERSION 3.13)
project(Exam C)

set(CMAKE_C_STANDARD 99)

add_executable(Exam main.c brainfuck.c brainfuck.h checkmate.h check_mate.c)