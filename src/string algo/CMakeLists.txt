cmake_minimum_required(VERSION 3.8)
enable_language(C)
add_library(stralg SHARED stralgo.c)
target_compile_options(stralg PUBLIC "-O2")
