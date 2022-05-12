cmake_minimum_required(VERSION 3.18.1)
project("strace example" CXX)

add_library(app SHARED native-lib.cpp)
