cmake_minimum_required(VERSION 3.8)

project("graph_algo")

enable_language(CXX)

add_library(graph_algo SHARED graphalgo.cpp)

add_executable(main main.cpp)

target_compile_options(main PUBLIC "-O2" "-unroll-loops" "-march=native" "-pipe" "-mavx" "-mavx2" "-mfma")
target_link_libraries(main graph_algo)