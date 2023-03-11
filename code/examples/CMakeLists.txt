cmake_minimum_required(VERSION 3.21)

# Declare executable
add_executable(example-window)
target_sources(example-window PRIVATE source-files/example-window.cpp)
target_link_libraries(example-window PRIVATE sahifa)

# Declare executable
add_executable(example-playground)
target_sources(example-playground PRIVATE source-files/example-playground.cpp)
target_link_libraries(example-playground PRIVATE sahifa)