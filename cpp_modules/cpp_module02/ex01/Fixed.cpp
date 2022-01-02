#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n) : fixed_point_value(n << 8)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float n)
{
    std::cout << "Float constructor called" << std::endl;
    bool is_minus = false;
    fixed_point_value = 0;
    if (n < 0 )
    {
        n *= -1;
        is_minus = true;
    }
    int int_value = (int)n;
    float fractional_value = n - int_value;
    for (int i = 0; i < number_of_fractional_bits; i++)
    {
        fixed_point_value = fixed_point_value << 1;
        fractional_value *= 2;
        if (fractional_value >= 1)
        {
            fractional_value -= 1;
            fixed_point_value++;
        }
    }
    if (fractional_value * 2 >= 1)
        fixed_point_value++;
    fixed_point_value += int_value << 8;
    if (is_minus)
        fixed_point_value *= -1;
}

Fixed::Fixed(const Fixed &f1)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = f1;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f1)
{
    std::cout << "Assignation operator called" << std::endl;
    fixed_point_value = f1.fixed_point_value;
    return (*this);
}

int Fixed::toInt(void) const
{
    return (fixed_point_value >> 8);
}

float Fixed::toFloat(void) const
{
    float result = 0;
    float frac = 0.5;

    for (int i = 0; i < number_of_fractional_bits; i++)
    {
        if (bitmask(fixed_point_value << i) == true)
        {
            result += frac;
        }
        frac /= 2;
    }
    result += toInt();
    return (result);
}

bool Fixed::bitmask(int fixed_value) const
{
    int i = 0x1 << (number_of_fractional_bits - 1);
    return (fixed_value & i);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
    fixed_point_value = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return (os);
}