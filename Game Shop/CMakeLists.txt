cmake_minimum_required(VERSION 3.21)
project(testowanie)

set(CMAKE_CXX_STANDARD 14)

add_executable(testowanie main.cpp src/cSingle.cpp Include/cSingle.h src/cGame.cpp Include/cGame.h src/cMulti.cpp Include/cMulti.h src/cBase.cpp Include/cBase.h src/cView.cpp Include/cView.h src/cController.cpp Include/cController.h src/cButton.cpp Include/cButton.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(testowanie sfml-system sfml-window sfml-graphics sfml-audio)