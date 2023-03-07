cmake_minimum_required(VERSION 3.21)

# Declare executable
add_executable(examples)

# Set C++ version
target_compile_features(examples PUBLIC cxx_std_20)

# List header files
set(HEADER_FILES
)

# List source files
set(SOURCE_FILES
	source-files/example-window.cpp
)

# Add header & source files to project
target_sources(examples
	PRIVATE
		${HEADER_FILES}
		${SOURCE_FILES}
)

# Link libraries to project
target_link_libraries(examples
	PUBLIC
		sahifa
)