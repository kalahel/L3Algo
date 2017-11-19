cmake_minimum_required(VERSION 3.8)
project(TD6_TasBinomial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        tas_binomial.c)

add_executable(TD6_TasBinomial ${SOURCE_FILES})