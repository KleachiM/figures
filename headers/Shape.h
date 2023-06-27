#ifndef FIGURES_SHAPE_H
#define FIGURES_SHAPE_H

#include "ISolidShape.h"

class CShape: public ISolidShape
{
public:
    CShape(std::string type, uint32_t fillColor, uint32_t outlineColor);
    virtual ~CShape() = default;

    std::string ToString() const override;

    uint32_t GetFillColor() const override;
    uint32_t GetOutlineColor() const override;

    std::string GetShapeType() const;
private:
    std::string m_type;
    uint32_t m_fillColor;
    uint32_t m_outlineColor;

    virtual void AppendProperties(std::ostream& strm) const = 0;
};

#endif //FIGURES_SHAPE_H
