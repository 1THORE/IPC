cmake_minimum_required(VERSION 3.10)
project(MyProgram)

set(CMAKE_CXX_STANDARD 11)

# Add your source files
add_executable(my_program main.cpp)

# Specify the path to libcurl
set(CURL_LIBRARY "lib/libcurl")
set(CURL_INCLUDE_DIR "include")

# Link against libcurl
target_include_directories(my_program PRIVATE "${CURL_INCLUDE_DIR}")
target_link_libraries(my_program PRIVATE "${CURL_LIBRARY}")
