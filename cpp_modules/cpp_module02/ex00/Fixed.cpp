#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
    std::cout << "Default constructor called" << std::endl;
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
    fixed_point_value = f1.getRawBits();
    return (*this);
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
