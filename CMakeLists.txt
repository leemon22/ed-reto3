cmake_minimum_required(VERSION 3.23)
project(reto3)

set(CMAKE_CXX_STANDARD 20)

include_directories(ejercicio2/includes)

add_executable(ej1 ejercicio1/src/main.cpp)

add_executable(ej2 ejercicio2/src/main.cpp ejercicio2/src/VectorPilas.cpp)
