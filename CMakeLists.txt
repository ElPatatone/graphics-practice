cmake_minimum_required(VERSION 3.10)

project(graphics)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp src/glad.c)

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

# find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

target_link_libraries(main glfw)
