cmake_minimum_required(VERSION 3.15)
project(AlgorithmsSecond)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgorithmsSecond main.cpp KMPSearch.cpp KMPSearch.h)

add_subdirectory(Google_tests)

add_library(KMPSearch KMPSearch.cpp)

target_compile_features(KMPSearch INTERFACE cxx_std_17)

set_target_properties(KMPSearch PROPERTIES LINKER_LANGUAGE CXX)