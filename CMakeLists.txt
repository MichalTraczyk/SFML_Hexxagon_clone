cmake_minimum_required(VERSION 3.24)
project(Hexxagon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hexxagon src/main.cpp src/Board/Board.cpp src/Board/Board.h src/Board/Hex.cpp src/Board/Hex.h src/Owner.h src/Background/Background.cpp src/Background/Background.h src/Background/Star.cpp src/Background/Star.h src/HexState.h src/OptionsAndMenu/Button.cpp src/OptionsAndMenu/Button.h src/Move.cpp src/Move.h src/AI.cpp src/AI.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(Hexxagon sfml-system sfml-window sfml-graphics sfml-audio)
