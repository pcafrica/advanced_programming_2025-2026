cmake_minimum_required(VERSION 3.15)
project(newton_solver)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(newton_solver newton.cpp newton_py.cpp)
