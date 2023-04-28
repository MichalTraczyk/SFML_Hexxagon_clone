cmake_minimum_required(VERSION 3.24)
project(Hexxagon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hexxagon main.cpp Board/Board.cpp Board/Board.h Board/Hex.cpp Board/Hex.h Owner.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Hexxagon sfml-system sfml-window sfml-graphics sfml-audio)
