#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP
# include "Point.hpp"

class Triangle : public Point
{
    private:
        const Point _p0;
        const Point _p1;
        const Point _p2;
        Point _normal;

    public:
        Triangle();
        Triangle(const Triangle &t);
        Triangle(const Point p0, const Point p1, const Point p2);
        ~Triangle();
        bool is_not_in(int n, const Point point);
        Triangle &operator=(const Triangle &t);
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif