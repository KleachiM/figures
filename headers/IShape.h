#ifndef FIGURES_ISHAPE_H
#define FIGURES_ISHAPE_H

#include <string>
//TODO: добавить виртуальный деструктор
class IShape
{
public:
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual std::string ToString() const = 0;
    virtual uint32_t GetOutlineColor() const = 0;
};

#endif //FIGURES_ISHAPE_H
