# Create executable.
add_executable(math_app main.cpp)

# Link against the math library.
target_link_libraries(math_app PRIVATE math)
