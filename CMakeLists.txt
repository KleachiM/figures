cmake_minimum_required(VERSION 3.24)
project(figures)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

#add_subdirectory(headers)
add_subdirectory(sources)
add_subdirectory(tests)

include_directories(headers)

add_executable(figures main.cpp
        headers/IShape.h
        headers/Point.h sources/Point.cpp
        headers/ISolidShape.h
        sources/LineSegment.cpp headers/LineSegment.h
        headers/Triangle.h sources/Triangle.cpp
        sources/Rectangle.cpp headers/Rectangle.h
        sources/Circle.cpp headers/Circle.h
        sources/ShapeReader.cpp headers/ShapeReader.h
        sources/Shape.cpp headers/Shape.h
        )

target_link_libraries(figures sfml-graphics sfml-audio)