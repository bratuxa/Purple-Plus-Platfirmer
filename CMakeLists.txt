cmake_minimum_required(VERSION 3.0.0)
project(PPP VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(PPP main.cpp 
                   Object.h 
                   Object.cpp 
                   World.h 
                   World.cpp
                   Player.h
                   Player.cpp
                   GameProcess.h
                   GameProcess.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
