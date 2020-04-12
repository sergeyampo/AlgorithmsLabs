cmake_minimum_required(VERSION 3.11)
project(interpolation_search)

set(CMAKE_CXX_STANDARD 17)

add_executable(interpolation_search main.cpp interpolation_search.cpp)

add_subdirectory(Google_tests)

add_library(InterpolationSearch interpolation_search.cpp)

set_target_properties(InterpolationSearch PROPERTIES LINKER_LANGUAGE CXX)