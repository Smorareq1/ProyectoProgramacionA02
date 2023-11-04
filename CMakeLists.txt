cmake_minimum_required(VERSION 3.26)
project(ProyectoAplicacion02)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProyectoAplicacion02 main.cpp
        myDoubleLinkedList.cpp
        myDoubleLinkedList.h
        Hashear.cpp
        Hashear.h
        LineData.cpp
        LineData.h
        Node.cpp
        Node.h)
