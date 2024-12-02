cmake_minimum_required(VERSION 3.27)
project(Video_Game_Recommender)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Video_Game_Recommender
        main.cpp
        Game.h
        ParseData.cpp
        ParseData.h
        Similar.cpp
        Similar.h
        SortingAlgorithms.cpp
)
