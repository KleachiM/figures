#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "../headers/ShapeReader.h"
#include "../headers/Circle.h"
#include "../headers/Rectangle.h"
#include "../headers/Triangle.h"
#include "../headers/Point.h"

#include <sstream>

using namespace std;
SCENARIO("Reading shapes")
{
    GIVEN("Reader")
    {
        stringstream inpStr;
        stringstream outStr;
        vector<shared_ptr<CShape>> shapes;
        CShapeReader reader(shapes, inpStr, outStr);
        REQUIRE(reader.GetShapes().empty());

        WHEN("Read circle")
        {
            inpStr << "circle 5 5 10 20 20\n"s;
            reader.HandleInput();
            REQUIRE(outStr.str() == ""s);
            REQUIRE(reader.GetShapes().size() == 1);

            THEN("Calculate circle area and perimeter")
            {
                REQUIRE(reader.GetShapes()[0]->GetShapeType() == "circle");
                REQUIRE(reader.GetShapes()[0]->GetArea() == Catch::Approx(314.159));
                REQUIRE(reader.GetShapes()[0]->GetPerimeter() == Catch::Approx(62.831).margin(0.001));
            }
        }

        WHEN("Read rectangle")
        {
            inpStr << "rectangle 0 0 10 5 100 1000\n"s;
            REQUIRE(reader.GetShapes().empty());
            reader.HandleInput();
            REQUIRE(reader.GetShapes().size() == 1);

            THEN("Calculate rect area and perimeter")
            {
                REQUIRE(reader.GetShapes()[0]->GetShapeType() == "rectangle");
                REQUIRE(reader.GetShapes()[0]->GetArea() == Catch::Approx(50));
                REQUIRE(reader.GetShapes()[0]->GetPerimeter() == Catch::Approx(30));
            }
        }

        WHEN("Read triangle")
        {
            inpStr << "triangle 1 1 2 4 5 10 100 100\n"s;
            REQUIRE(reader.GetShapes().empty());
            reader.HandleInput();
            REQUIRE(reader.GetShapes().size() == 1);

            THEN("Calculate triangle area and perimeter")
            {
                REQUIRE(reader.GetShapes()[0]->GetShapeType() == "triangle");
                REQUIRE(reader.GetShapes()[0]->GetArea() == Catch::Approx(1.5));
                REQUIRE(reader.GetShapes()[0]->GetPerimeter() == Catch::Approx(19.72).margin(0.01));
            }
        }
    }
}

TEST_CASE("Unknown command")
{
    stringstream inpStr;
    stringstream outStr;
    vector<shared_ptr<CShape>> shapes;
    CShapeReader reader(shapes, inpStr, outStr);
    REQUIRE(reader.GetShapes().empty());
    inpStr << "hello\n"s;
    reader.HandleInput();
    REQUIRE(reader.GetShapes().empty());
}

TEST_CASE("Bad input for circle")
{
    stringstream inpStr;
    stringstream outStr;
    vector<shared_ptr<CShape>> shapes;
    CShapeReader reader(shapes, inpStr, outStr);

    SECTION("Command without args")
    {
        inpStr << "circle\n"s;
        reader.HandleInput();
        REQUIRE(reader.GetShapes().empty());
        REQUIRE(outStr.str() == "Too few args\n"s);
    }
}

TEST_CASE("Bad input for triangle")
{
    stringstream inpStr;
    stringstream outStr;
    vector<shared_ptr<CShape>> shapes;
    CShapeReader reader(shapes, inpStr, outStr);

    SECTION("Command without args")
    {
        inpStr << "triangle\n"s;
        reader.HandleInput();
        REQUIRE(reader.GetShapes().empty());
        REQUIRE(outStr.str() == "Too few args\n"s);
    }
}

TEST_CASE("Bad input for rectangle")
{
    stringstream inpStr;
    stringstream outStr;
    vector<shared_ptr<CShape>> shapes;
    CShapeReader reader(shapes, inpStr, outStr);

    SECTION("Command without args")
    {
        inpStr << "rectangle\n"s;
        reader.HandleInput();
        REQUIRE(reader.GetShapes().empty());
        REQUIRE(outStr.str() == "Too few args\n"s);
    }
}

TEST_CASE("Get area")
{
    stringstream inpStr;
    stringstream outStr;
    vector<shared_ptr<CShape>> shapes;
    CShapeReader reader(shapes, inpStr, outStr);

    inpStr << "rectangle 1 1 1 1 100 100\n"s;
    REQUIRE(outStr.str() == ""s);
    reader.HandleInput();
    inpStr << "triangle 1 1 2 4 5 10 200 200\n"s;
    reader.HandleInput();
    inpStr << "circle 3 3 2 300 300\n"s;
    reader.HandleInput();

    REQUIRE(reader.GetShapes()[0]->GetShapeType() == "rectangle");
    REQUIRE(reader.GetShapes()[1]->GetShapeType() == "triangle");
    REQUIRE(reader.GetShapes()[2]->GetShapeType() == "circle");

    REQUIRE(reader.GetShapes()[0]->GetArea() == Catch::Approx(1));
    REQUIRE(reader.GetShapes()[1]->GetArea() == Catch::Approx(1.5));
    REQUIRE(reader.GetShapes()[2]->GetArea() == Catch::Approx(12.56).margin(0.01));
}

TEST_CASE("Get perimeter")
{
    stringstream inpStr;
    stringstream outStr;
    vector<shared_ptr<CShape>> shapes;
    CShapeReader reader(shapes, inpStr, outStr);

    inpStr << "rectangle 1 1 1 1 100 100\n"s;
    REQUIRE(outStr.str() == ""s);
    reader.HandleInput();
    inpStr << "triangle 1 1 2 4 5 10 200 200\n"s;
    reader.HandleInput();
    inpStr << "circle 3 3 2 300 300\n"s;
    reader.HandleInput();

    REQUIRE(reader.GetShapes()[0]->GetPerimeter() == 4);
    REQUIRE(reader.GetShapes()[1]->GetPerimeter() == Catch::Approx(19.72).margin(0.01));
    REQUIRE(reader.GetShapes()[2]->GetPerimeter() == Catch::Approx(12.56).margin(0.01));
}