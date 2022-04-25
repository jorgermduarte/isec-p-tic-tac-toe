cmake_minimum_required(VERSION 3.21)
project(tic_tac_toe C)

set(CMAKE_C_STANDARD 99)

add_executable(tic_tac_toe main.c game/game.c game/game.h game/player.c game/player.h game/utils.c game/utils.h game/modes/humanvshuman.c game/modes/humanvshuman.h)
