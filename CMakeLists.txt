cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Chess_game VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Add the executable
add_executable(Chess_game
        src/main.cpp
        # Add more source files as needed
)

# Include directories
target_include_directories(Chess_game PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/include/SDL2
)

# Library directories
link_directories(${CMAKE_SOURCE_DIR}/lib/libSDL2)

# Link libraries
target_link_libraries(Chess_game PRIVATE SDL2::SDL2)

# Optional: Set compile options
target_compile_options(Chess_game PRIVATE
        -Wall
        -Wextra
        -pedantic
)
