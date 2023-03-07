cmake_minimum_required(VERSION 3.21)

# Declare library
add_library(sahifa)

# Set C++ version
target_compile_features(sahifa PUBLIC cxx_std_20)

# Set compiler warning level
if(MSVC)
  target_compile_options(sahifa PRIVATE /W4 /WX)
else()
  target_compile_options(sahifa PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# List header files
set(HEADER_FILES
	header-files/window.hpp
	header-files/core/win32/win32-window.hpp
)

# List source files
set(SOURCE_FILES
	source-files/window.cpp
	source-files/core/win32/win32-window.cpp
)

# Add header & source files to project
target_sources(sahifa
	PRIVATE
		${HEADER_FILES}
		${SOURCE_FILES}
)

# Add include directories
target_include_directories(sahifa
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/header-files
)