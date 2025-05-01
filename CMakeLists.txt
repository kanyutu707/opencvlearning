cmake_minimum_required(VERSION 3.10)
project(opencvcourse)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(opencvcourse transform.cpp)

target_link_libraries(opencvcourse ${OpenCV_LIBS})
