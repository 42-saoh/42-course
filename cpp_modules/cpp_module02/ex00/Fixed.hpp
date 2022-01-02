#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int fixed_point_value;
        static const int number_of_fractional_bits;

    public:
        Fixed();
        Fixed(const Fixed &f1);
        ~Fixed();
        Fixed &operator=(const Fixed &f1);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif