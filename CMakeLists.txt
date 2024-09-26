cmake_minimum_required(VERSION 3.29)
project(Puissance_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Puissance_C main.c
        game.h
        player.c
        player.h
        board.h
        board.c)
