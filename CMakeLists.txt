cmake_minimum_required(VERSION 3.13)
project(Exam C)

set(CMAKE_C_STANDARD 99)

add_executable(Exam main.c
        brainfuck/brainfuck.c brainfuck/brainfuck.h
        checkmate/checkmate.h checkmate/check_mate.c
        ft_list_foreach/ft_list_foreach.c ft_list_foreach/ft_list.h
        rostring/rostring.c main.h)