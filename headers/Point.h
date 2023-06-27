#ifndef FIGURES_POINT_H
#define FIGURES_POINT_H

class CPoint
{
public:
    double x;
    double y;
//TODO: сделать отдельную функцию для этого
    double GetDistanceToOtherPoint(const CPoint& other) const;
};

#endif //FIGURES_POINT_H
