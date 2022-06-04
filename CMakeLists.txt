cmake_minimum_required(VERSION 3.21)
project(tic_tac_toe C)

set(CMAKE_C_STANDARD 99)

add_executable(tic_tac_toe main.c game/gameBoard.c game/gameBoard.h game/player.c game/player.h game/utils.c game/utils.h game/modes/HumanVsHuman.c game/modes/HumanVsHuman.h game/modes/HumanVsBot.c game/modes/HumanVsBot.h)
