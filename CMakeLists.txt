cmake_minimum_required(VERSION 3.10)
project(DungeonTracker)

set(CMAKE_CXX_STANDARD 17)

add_executable(DungeonTracker main.cpp util/ANSI.cpp headers/ANSI.h entity/Creature.cpp headers/Creature.h entity/attack/Attack.cpp headers/Attack.h util/Dice.cpp headers/Dice.h headers/CreatureElements.h entity/Alignment.cpp headers/Alignment.h util/FileManager.cpp headers/FileManager.h entity/Monster.cpp headers/Monster.h)