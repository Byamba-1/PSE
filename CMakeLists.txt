cmake_minimum_required(VERSION 3.24)
project(PSE)

set(CMAKE_CXX_STANDARD 98)

add_executable(${CMAKE_PROJECT_NAME} main.cpp parser/Byamba/CD.cpp parser/Byamba/tinystr.cpp parser/Byamba/tinyxml.cpp parser/Byamba/tinyxmlerror.cpp
        parser/Byamba/tinyxmlparser.cpp)
