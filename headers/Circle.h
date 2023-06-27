#ifndef FIGURES_CIRCLE_H
#define FIGURES_CIRCLE_H

#include "Shape.h"
#include "Point.h"

class CCircle: public CShape
{
public:
    CCircle(const CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor);
    double GetArea() const override;
    double GetPerimeter() const override;

    void AppendProperties(std::ostream& strm) const override;

    CPoint GetCenter() const;
    double GetRadius() const;
private:
    CPoint m_center;
    double m_radius;
};

#endif //FIGURES_CIRCLE_H
