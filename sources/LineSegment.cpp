#include "../headers/LineSegment.h"

using namespace std;
CLineSegment::CLineSegment(const CPoint& startPoint, const CPoint& endPoint)
        : m_startPoint(startPoint) , m_endPoint(endPoint)
{
}

double CLineSegment::GetArea() const
{
    return 0;
}

double CLineSegment::GetPerimeter() const
{
    return m_startPoint.GetDistanceToOtherPoint(m_endPoint);
}

uint32_t CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}

std::string CLineSegment::ToString() const
{
    string outStr;
    outStr = "Start point: {" + to_string(m_startPoint.x)
            + ", " + to_string(m_startPoint.y) + "}\n"
            + "End point: {" + to_string(m_endPoint.x)
            + ", " + to_string(m_endPoint.y) + "}";
    return outStr;
}