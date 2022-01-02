#include "Triangle.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    Triangle t(a, b, c);

    if (t.is_not_in(0, point))
        return (false);
    if (t.is_not_in(1, point))
        return (false);
    if (t.is_not_in(2, point))
        return (false);
    return (true);
}