cmake_minimum_required(VERSION 3.25)
project(Structuri_date3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Structuri_date3
        App.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
