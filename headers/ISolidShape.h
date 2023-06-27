#ifndef FIGURES_ISOLIDSHAPE_H
#define FIGURES_ISOLIDSHAPE_H

#include "IShape.h"

class ISolidShape: public IShape
{
public:
    virtual uint32_t GetFillColor() const = 0;
};

#endif //FIGURES_ISOLIDSHAPE_H
