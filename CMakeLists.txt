cmake_minimum_required(VERSION 3.15)
project(finances)

set(CMAKE_CXX_STANDARD 17)

add_executable(finances
        src/main.cpp
        src/Registry.cpp
        src/Registry.h
        src/CreditCard.cpp
        src/CreditCard.h
        src/FileFormatter.cpp
        src/FileFormatter.h src/Statistics.cpp src/Statistics.h)