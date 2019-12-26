cmake_minimum_required(VERSION 3.13.2)
project(GenieStore)

set(CMAKE_CXX_STANDARD 14)

add_executable(GenieStore main.cpp Item.cpp Item.h ItemStock.cpp ItemStock.h node.cpp node.h LinkedList.cpp LinkedList.h ItemManager.cpp ItemManager.h Helper.cpp Helper.h Customer.cpp Customer.h CustomerList.cpp CustomerList.h CustomerManager.cpp CustomerManager.h)