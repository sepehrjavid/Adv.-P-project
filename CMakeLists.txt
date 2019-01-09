cmake_minimum_required(VERSION 3.12)
project(Cpp_java_game_engin)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(Cpp_java_game_engin
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Cpp_java_game_engin.cbp
        cmake-build-debug/Makefile
        classes.h
        Dice.cpp
        Game.cpp
        main.cpp
        Player.cpp
        Exceptions.h
        helperfunctions.h
        Mohre.cpp
        Socket.h
        project.txt Time.cpp PreviousMove.cpp)
