#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"
# include <cmath>

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;
        const Fixed _z;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Fixed x, const Fixed y);
        Point(const Fixed x, const Fixed y, const Fixed z);
        Point(const Point &p);
        ~Point();
        Point &operator=(const Point &p);
        Point operator-(const Point &p) const;
        Fixed dot(const Point &p1, const Point &p2) const;
        Point cross(const Point &p1, const Point &p2) const;
        Fixed length(void) const;
        Point unit(const Point &p) const;
};

#endif