cmake_minimum_required(VERSION 3.15)
project(example)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)
find_package(Eigen3 REQUIRED)

pybind11_add_module(example example.cpp)
target_link_libraries(example PRIVATE Eigen3::Eigen)

# Example that shows how to pass a value from Python to C++.
target_compile_definitions(example PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
