# Create a shared library.
add_library(math SHARED math.cpp math.hpp)

# Specify include directories for the library.
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Optional: add compiler warnings.
target_compile_options(math PRIVATE -Wall -Wextra -Wpedantic)
