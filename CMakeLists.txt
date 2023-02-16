cmake_minimum_required(VERSION 3.24)
project(XMLParser)

set(CMAKE_CXX_STANDARD 98)

add_executable(PSE main.cpp parser/Byamba/CD.cpp parser/Byamba/tinystr.cpp parser/Byamba/tinyxml.cpp parser/Byamba/tinyxmlerror.cpp
        parser/Byamba/tinyxmlparser.cpp)
