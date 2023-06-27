#ifndef FIGURES_RECTANGLE_H
#define FIGURES_RECTANGLE_H

#include "Shape.h"
#include "Point.h"

class CRectangle: public CShape
{
public:
    CRectangle(
            const CPoint& leftTop, double width, double height,
            uint32_t fillColor, uint32_t outlineColor
            );
    double GetArea() const override;
    double GetPerimeter() const override;

    void AppendProperties(std::ostream& strm) const override;

    CPoint GetLeftTop() const;
    CPoint GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;
private:
    CPoint m_leftTop;
    double m_width;
    double m_height;
};

#endif //FIGURES_RECTANGLE_H
