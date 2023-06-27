#include "../headers/Circle.h"
#include <limits>
#include <iostream>

using namespace std;
CCircle::CCircle(const CPoint& center, double radius, uint32_t fillColor = 0, uint32_t outlineColor = 0)
        : CShape("circle", fillColor, outlineColor), m_center(center)
{
    m_radius = abs(radius);
    if (m_radius < numeric_limits<double>::epsilon())
    {
        m_radius = 1;
    }
}

double CCircle::GetArea() const
{
    return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const {
    return 2 * M_PI * m_radius;
}

CPoint CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

void CCircle::AppendProperties(ostream &strm) const
{
    strm << "Center: {" + to_string(m_center.x) + ", " + to_string(m_center.y) + "}" << endl;
    strm << "Radius: " + to_string(m_radius) << endl;
}
