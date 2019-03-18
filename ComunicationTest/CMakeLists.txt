cmake_minimum_required(VERSION 3.13)
project(ComunicationTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(ComunicationTest main.cpp socketServer.cpp socketServer.h socketClient.cpp socketClient.h)