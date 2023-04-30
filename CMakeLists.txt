cmake_minimum_required(VERSION 3.24)
project(Hexxagon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hexxagon src/main.cpp src/Board/Board.cpp src/Board/Board.h src/Board/Hex.cpp src/Board/Hex.h src/Owner.h src/Background.cpp src/Background.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Hexxagon sfml-system sfml-window sfml-graphics sfml-audio)
