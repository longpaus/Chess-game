cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(text_editor VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SDL2 and SDL2_ttf packages
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Add the executable
add_executable(text_editor
        src/main.cpp
)

# Include directories
target_include_directories(text_editor PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/include/SDL2
)

# Library directories (if needed)
link_directories(${CMAKE_SOURCE_DIR}/lib/libSDL2)

# Link libraries
target_link_libraries(text_editor PRIVATE
        SDL2::SDL2
        SDL2_ttf::SDL2_ttf
)

# Enable testing
enable_testing()

# Add the Catch2 main library for testing
add_library(catch2_main STATIC lib/catch2_main.cpp)
target_include_directories(catch2_main PUBLIC lib)

# Compile options
add_compile_options(
        -Wall
        -Wextra
        -Werror
        -pedantic-errors
        -Wconversion
        -Wsign-conversion
        -Wdouble-promotion
        -Wcast-align
        -Wformat=2
        -Wuninitialized
        -Wnull-dereference
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wdeprecated-copy-dtor
        -Wold-style-cast
        -Wzero-as-null-pointer-constant
        -Wsuggest-override
        -fstack-protector-strong
)

# Add the test executable (assuming you have test files)
add_executable(test_text_editor
        src/tests/main.test.cpp)
target_link_libraries(test_text_editor PRIVATE
        catch2_main
        SDL2::SDL2
        SDL2_ttf::SDL2_ttf
)

# Add the tests
add_test(NAME test_text_editor COMMAND test_text_editor)
