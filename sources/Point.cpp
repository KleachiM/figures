#include "../headers/Point.h"
#include <cmath>

using namespace std;
double CPoint::GetDistanceToOtherPoint(const CPoint &other) const
{
    double deltaX = other.x - x;
    double deltaY = other.y - y;
    double sq = sqrt(deltaX * deltaX + deltaY * deltaY);
    return sq;
}
