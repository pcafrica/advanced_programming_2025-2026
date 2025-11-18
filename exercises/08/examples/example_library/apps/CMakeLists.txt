# Create executable.
add_executable(math_app main.cpp)

# Link against the math library.
target_link_libraries(math_app PRIVATE math)

# Optional: set C++ standard for this target.
set_target_properties(math_app PROPERTIES CXX_STANDARD 17)
