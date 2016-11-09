cmake_minimum_required(VERSION 3.5)
project(03_BinarySearchTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp NotFoundException.cpp PrecondViolatedExcep.cpp)
set(HEADER_FILES BinaryNode.h BinaryNodeTree.h BinarySearchTree.h BinaryTreeInterface.h NotFoundException.h PrecondViolatedExcep.h)
add_executable(03_BinarySearchTree ${SOURCE_FILES} ${HEADER_FILES})