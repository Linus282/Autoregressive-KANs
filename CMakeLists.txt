cmake_minimum_required(VERSION 3.14)
project(KANPython)

set(CMAKE_CXX_STANDARD 14)

find_package(pybind11 REQUIRED)

pybind11_add_module(kanpy
    bindings.cpp
    kan.cpp
    spline.cpp
)

target_include_directories(kanpy PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
