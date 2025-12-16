cmake_minimum_required(VERSION 3.23)
project(customHeaders)

set(CMAKE_CXX_STANDARD 14)

add_executable(customHeaders main.cpp rbxio.cpp rbxerr.cpp LList.cpp HashTable.cpp)
