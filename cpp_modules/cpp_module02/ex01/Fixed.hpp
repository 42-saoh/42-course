#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int fixed_point_value;
        static const int number_of_fractional_bits = 8;

    public:
        Fixed();
        Fixed(int n);
        Fixed(float n);
        Fixed(const Fixed &f1);
        ~Fixed();
        Fixed &operator=(const Fixed &f1);
        float toFloat( void ) const;
        int toInt( void ) const;
        bool bitmask(int fixed_value) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif