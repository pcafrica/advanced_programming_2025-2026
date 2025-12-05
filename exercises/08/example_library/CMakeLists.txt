cmake_minimum_required(VERSION 3.15)

project(MathExample VERSION 1.0
        DESCRIPTION "A minimal CMake example"
        LANGUAGES CXX)

# Set C++ standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories.
add_subdirectory(math)
add_subdirectory(apps)
