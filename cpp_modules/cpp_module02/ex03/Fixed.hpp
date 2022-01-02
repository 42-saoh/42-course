#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
        int fixed_point_value;
        static const int number_of_fractional_bits = 8;

    public:
        static Fixed &min(Fixed &f1, Fixed &f2);
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static const Fixed &max(const Fixed &f1, const Fixed &f2);
        void showbits(void);
        Fixed();
        Fixed(int n);
        Fixed(float n);
        Fixed(const Fixed &f1);
        ~Fixed();
        Fixed &operator=(const Fixed &f1);
        Fixed operator+(const Fixed &f1) const;
        Fixed operator-(const Fixed &f1) const;
        Fixed operator*(const Fixed &f1) const;
        Fixed operator/(const Fixed &f1) const;
        Fixed &operator++();
        Fixed operator++(int);
        bool operator<(const Fixed &f1) const;
        bool operator<=(const Fixed &f1) const;
        bool operator>(const Fixed &f1) const;
        bool operator>=(const Fixed &f1) const;
        bool operator==(const Fixed &f1) const;
        bool operator!=(const Fixed &f1) const;
        float toFloat( void ) const;
        int toInt( void ) const;
        bool bitmask(int fixed_value) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed sqrt(void);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif