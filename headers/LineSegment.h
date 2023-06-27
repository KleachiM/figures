#ifndef FIGURES_LINESEGMENT_H
#define FIGURES_LINESEGMENT_H

#include "IShape.h"
#include "Point.h"

class CLineSegment: public IShape
{
public:
    CLineSegment(const CPoint& startPoint, const CPoint& endPoint);
    double GetArea() const override;
    double GetPerimeter() const override;

    std::string ToString() const override;

    uint32_t GetOutlineColor() const override;

    CPoint GetStartPoint() const;
    CPoint GetEndPoint() const;
private:
    CPoint m_startPoint;
    CPoint m_endPoint;
    uint32_t m_outlineColor;
};

#endif //FIGURES_LINESEGMENT_H
