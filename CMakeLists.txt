cmake_minimum_required(VERSION 3.12)
project(KANProject)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/pybind11)

include_directories(${PROJECT_SOURCE_DIR})

pybind11_add_module(pykan bindings/pykan.cpp kan.cpp spline.cpp)

# Optional: executable zum Testen
add_executable(example example.cpp kan.cpp spline.cpp)

