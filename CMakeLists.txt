cmake_minimum_required(VERSION 3.10)

project(an-geometry VERSION 0.1 DESCRIPTION "an-geometry Open source library for computational geometry")

add_library(angeometry
    includes/angeometry.hpp
)
set_target_properties(angeometry PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(angeometry PUBLIC includes)
# target_include_directories(angeometry PRIVATE src)



