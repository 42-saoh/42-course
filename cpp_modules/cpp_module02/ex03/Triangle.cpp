#include "Triangle.hpp"

Triangle::Triangle() {}
Triangle::~Triangle() {}
Triangle::Triangle(const Triangle &t)
{
    (*this) = t;
}

Triangle::Triangle(const Point p0, const Point p1, const Point p2)
    : _p0(p0), _p1(p1), _p2(p2)
{
    Point tmp1(_p1 - _p0);
    Point tmp2(_p2 - _p0);
    _normal = unit(cross(tmp1, tmp2));
}

Triangle &Triangle::operator=(const Triangle &t)
{
    const_cast<Point &>(_p0) = t._p0;
    const_cast<Point &>(_p1) = t._p1;
    const_cast<Point &>(_p2) = t._p2;
    _normal = t._normal;
    return (*this);
}

bool Triangle::is_not_in(int n, const Point point)
{
    Point c;
    if (n == 0)
    {
        Point edge(_p1 - _p0);
        Point vp(point - _p0);
        c = cross(edge, vp);
    }
    else if (n == 1)
    {
        Point edge(_p2 - _p1);
        Point vp(point - _p1);
        c = cross(edge, vp);
    }
    else
    {
        Point edge(_p0 - _p2);
        Point vp(point - _p2);
        c = cross(edge, vp);
    }
    if (dot(_normal, c) < 0)
        return (true);
    return (false);
}