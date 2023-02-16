cmake_minimum_required(VERSION 3.24)
project(XMLParser)

set(CMAKE_CXX_STANDARD 98)

add_executable(XMLParser main.cpp tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp CD.cpp CD.h)
