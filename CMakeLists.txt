cmake_minimum_required(VERSION 3.21)
project(mds2hw1)

set(CMAKE_CXX_STANDARD 17)

add_executable(mds2hw1 main.cpp npc.cpp npc.h item.cpp item.h hero.cpp hero.h character.cpp character.h sorcerer.cpp sorcerer.h fighter.cpp fighter.h exception.h)
