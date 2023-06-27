#include "../headers/Shape.h"
#include <sstream>

using namespace std;

CShape::CShape(string type, uint32_t fillColor, uint32_t outlineColor)
            : m_type(type), m_fillColor(fillColor), m_outlineColor(outlineColor)
{}

std::string CShape::ToString() const
{
    ostringstream strm;
    strm << "type: " << GetShapeType() << endl
        << "perimeter: " << GetPerimeter() << endl
        << "area: " << GetArea() << endl
        << "outline color: " << GetOutlineColor() << endl
        << "fill color: " << GetFillColor() << endl;
    AppendProperties(strm);
    return strm.str();
}

uint32_t CShape::GetFillColor() const
{
    return m_fillColor;
}

uint32_t CShape::GetOutlineColor() const
{
    return m_outlineColor;
}

std::string CShape::GetShapeType() const
{
    return m_type;
}

