#ifndef FIGURES_TRIANGLE_H
#define FIGURES_TRIANGLE_H

#include "Shape.h"
#include "Point.h"

class CTriangle: public CShape
{
public:
    CTriangle(
            const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3,
            uint32_t fillColor, uint32_t outlineColor
            );
    double GetArea() const override;
    double GetPerimeter() const override;

    void AppendProperties(std::ostream& strm) const override;

    CPoint GetVertex1() const;
    CPoint GetVertex2() const;
    CPoint GetVertex3() const;
private:
    CPoint m_vertex1;
    CPoint m_vertex2;
    CPoint m_vertex3;
};

#endif //FIGURES_TRIANGLE_H
