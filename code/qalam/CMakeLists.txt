cmake_minimum_required(VERSION 3.21)

# Declare library
add_library(qalam)

# Set C++ version
target_compile_features(qalam PUBLIC cxx_std_20)

# Set compiler warning level
if(MSVC)
  target_compile_options(qalam PRIVATE /W4 /WX)
else()
  target_compile_options(qalam PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# List header files
set(HEADER_FILES
	header-files/context.hpp
)

# List source files
set(SOURCE_FILES
	source-files/context.cpp
)

# Add header & source files to project
target_sources(qalam
	PRIVATE
		${HEADER_FILES}
		${SOURCE_FILES}
)

# Add include directories
target_include_directories(qalam
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/header-files
)