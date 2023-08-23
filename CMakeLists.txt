cmake_minimum_required(VERSION 3.2...3.5 FATAL_ERROR)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(PROJECT_NAME HW-dpcpp-2.2)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} include/main.hpp src/main.cpp)

add_library(VeryHeavyDatabaseLib SHARED include/VeryHeavyDatabase.hpp src/VeryHeavyDatabase.cpp)

target_link_libraries(${PROJECT_NAME} VeryHeavyDatabaseLib)
