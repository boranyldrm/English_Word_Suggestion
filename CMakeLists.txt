cmake_minimum_required(VERSION 3.6)
project(Assignment_4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SuggestWords.cpp SuggestWords.h AVLTree.cpp AVLTree.h)
add_executable(Assignment_4 ${SOURCE_FILES})