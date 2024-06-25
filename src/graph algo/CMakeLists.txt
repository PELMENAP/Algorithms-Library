cmake_minimum_required(VERSION 3.8)
enable_language(CXX)
add_library(graph_algo SHARED graphalgo.cpp)
target_compile_options(graph_algo PUBLIC "-O2")
