find_package(CATCH2 3 REQUIRED)

add_executable(tests tests.cpp
        ../headers/ShapeReader.h ../sources/ShapeReader.cpp
        ../headers/Circle.h ../sources/Circle.cpp
        ../headers/IShape.h ../headers/ISolidShape.h
        ../headers/LineSegment.h ../sources/LineSegment.cpp
        ../headers/Point.h ../sources/Point.cpp
        ../headers/Rectangle.h ../sources/Rectangle.cpp
        ../headers/Shape.h ../sources/Shape.cpp
        ../headers/ShapeReader.h ../sources/ShapeReader.cpp
        ../headers/Triangle.h ../sources/Triangle.cpp
        )

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)