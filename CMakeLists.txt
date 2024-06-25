cmake_minimum_required(VERSION 3.5)

project("bimbim")

enable_language(CXX)
set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_STANDARD 17)

add_library(visual visual.cpp)
add_executable(main main.cpp)

target_compile_options(main PUBLIC "-O2" "-unroll-loops" "-march=native" "-pipe" "-mavx" "-mavx2" "-mfma")
target_link_libraries(main  sfml-graphics sfml-window sfml-system visual)