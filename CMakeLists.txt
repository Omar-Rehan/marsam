cmake_minimum_required(VERSION 3.21)

# Declare project
project(marsam)

# Add sub-directories
add_subdirectory(code/sahifa)
add_subdirectory(code/examples)

set(CMAKE_SUPPRESS_REGENERATION true)