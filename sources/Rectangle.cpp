#include "../headers/Rectangle.h"
#include <string>
#include <iostream>

using namespace std;
CRectangle::CRectangle(
        const CPoint &leftTop, double width, double height,
        uint32_t fillColor, uint32_t outlineColor
        )
        : CShape("rectangle", fillColor, outlineColor),
          m_leftTop(leftTop)
{
    if (width <= 0)
    {
        m_width = 1;
    }
    if (height <= 0)
    {
        m_height = 1;
    }
    m_width = width;
    m_height = height;
}

double CRectangle::GetPerimeter() const
{
    return 2 * (m_width + m_height);
}

double CRectangle::GetArea() const
{
    return m_width * m_height;
}

CPoint CRectangle::GetLeftTop() const
{
    return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
    CPoint rightBottom;
    rightBottom.x = m_leftTop.x + m_width;
    rightBottom.y = m_leftTop.y + m_height;
    return rightBottom;
}

double CRectangle::GetWidth() const
{
    return m_width;
}

double CRectangle::GetHeight() const
{
    return m_height;
}

void CRectangle::AppendProperties(ostream &strm) const
{
    strm << "Left top: {" + to_string(m_leftTop.x) + ", " + to_string(m_leftTop.y) + "}" << endl;
    strm << "Right bottom: {" + to_string(GetRightBottom().x) + ", " + to_string(GetRightBottom().y) + "}" << endl;
    strm << "Width: " << m_width << " Height: " << m_height << endl;
}
