#include "../headers/Triangle.h"
#include <cmath>
#include <iostream>

using namespace std;
CTriangle::CTriangle(
        const CPoint &vertex1, const CPoint &vertex2, const CPoint &vertex3,
        uint32_t fillColor, uint32_t outlineColor
        )
        : CShape("triangle", fillColor, outlineColor),
        m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3)
{
}

double CTriangle::GetArea() const {
    double semiP = GetPerimeter() / 2;
    double side1 = m_vertex1.GetDistanceToOtherPoint(m_vertex2);
    double side2 = m_vertex2.GetDistanceToOtherPoint(m_vertex3);
    double side3 = m_vertex3.GetDistanceToOtherPoint(m_vertex1);
    double sq = sqrt(semiP * (semiP - side1) * (semiP - side2) * (semiP - side3));
    return sq;
}

double CTriangle::GetPerimeter() const
{
    double side1 = m_vertex1.GetDistanceToOtherPoint(m_vertex2);
    double side2 = m_vertex2.GetDistanceToOtherPoint(m_vertex3);
    double side3 = m_vertex3.GetDistanceToOtherPoint(m_vertex1);
    return side1 + side2 + side3;
}

CPoint CTriangle::GetVertex1() const
{
    return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
    return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
    return m_vertex3;
}

void CTriangle::AppendProperties(ostream &strm) const
{
    strm << "Vertex 1: {" + to_string(m_vertex1.x) + ", " + to_string(m_vertex1.y) + "}" << endl;
    strm << "Vertex 2: {" + to_string(m_vertex2.x) + ", " + to_string(m_vertex2.y) + "}" << endl;
    strm << "Vertex 3: {" + to_string(m_vertex3.x) + ", " + to_string(m_vertex3.y) + "}" << endl;
}

