#include "Point.hpp"

Point::Point() {}
Point::Point(const float x, const float y) : _x(x), _y(y), _z(0) {}
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y), _z(0) {}
Point::Point(const Fixed x, const Fixed y, const Fixed z) : _x(x), _y(y), _z(z) {}
Point::~Point() {}

Point::Point(const Point &p)
{
    (*this) = p;
}

Point &Point::operator=(const Point &p)
{
    const_cast<Fixed &>(_x) = p._x;
    const_cast<Fixed &>(_y) = p._y;
    const_cast<Fixed &>(_z) = p._z;
    return (*this);
}

Point Point::operator-(const Point &p) const
{
    Point tmp(_x - p._x, _y - p._y, _z - p._z);
    return (tmp);
}

Fixed Point::dot(const Point &p1, const Point &p2) const
{
    Fixed _dot((p1._x * p2._x) + (p1._y * p2._y) + (p1._z * p2._z));
    return (_dot);
}

Point Point::cross(const Point &p1, const Point &p2) const
{
    Point _cross((p1._y * p2._z) - (p1._z * p2._y) \
                , (p1._z * p2._x) - (p1._x * p2._z) \
                , (p1._x * p2._y) - (p1._y * p2._x));
    return (_cross);
}

Fixed Point::length(void) const
{
    Fixed _tmp((_x * _x) + (_y * _y) + (_z * _z));
    return (_tmp.sqrt());
}

Point Point::unit(const Point &p) const
{
    Fixed _length(p.length());
    Point _tmp(p._x / _length, p._y / _length, p._z / _length);
    return (_tmp);
}