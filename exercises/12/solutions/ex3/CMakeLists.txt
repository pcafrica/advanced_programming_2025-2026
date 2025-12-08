cmake_minimum_required(VERSION 3.15)
project(eigen_ops)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)
find_package(Eigen3 REQUIRED)

pybind11_add_module(eigen_ops src/eigen_ops.cpp)
target_include_directories(eigen_ops PRIVATE include)
target_link_libraries(eigen_ops PRIVATE Eigen3::Eigen)
