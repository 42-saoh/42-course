#include "Fixed.hpp"

int main()
{
   Fixed a;
   Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
   Fixed q(5.5f);
   std::cout << (q / a) << std::endl;

   std::cout << a << std::endl;
   std::cout << ++a << std::endl;
   std::cout << a << std::endl;
   std::cout << a++ << std::endl;
   std::cout << a << std::endl;

   std::cout << b << std::endl;
   std::cout << Fixed::max( a, b ) << std::endl;
   std::cout << "--------a : " << a << " b : " << b << "-------------" << std::endl;
   if (a > b)
      std::cout << " > " << std::endl;
   if (a >= b)
      std::cout << " >= " << std::endl;
   if (a < b)
      std::cout << " < " << std::endl;
   if (a <= b)
      std::cout << " <= " << std::endl;
   if (a == b)
      std::cout << " == " << std::endl;
   if (a != b)
      std::cout << " != " << std::endl;
   Fixed const c( Fixed( 5.05f ) * Fixed( -3.12f ) );
   std::cout << "-------a c : " << c << "--------------" << std::endl;
   if (a > c)
      std::cout << " > " << std::endl;
   if (a >= c)
      std::cout << " >= " << std::endl;
   if (a < c)
      std::cout << " < " << std::endl;
   if (a <= c)
      std::cout << " <= " << std::endl;
   if (a == c)
      std::cout << " == " << std::endl;
   if (a != c)
      std::cout << " != " << std::endl;
   std::cout << "--------b c-------------" << std::endl;
   if (b > c)
      std::cout << " > " << std::endl;
   if (b >= c)
      std::cout << " >= " << std::endl;
   if (b < c)
      std::cout << " < " << std::endl;
   if (b <= c)
      std::cout << " <= " << std::endl;
   if (b == c)
      std::cout << " == " << std::endl;
   if (b != c)
      std::cout << " != " << std::endl;
   Fixed d(c);
   std::cout << "--------d : " << d << " c-------------" << std::endl;
   if (d > c)
      std::cout << " > " << std::endl;
   if (d >= c)
      std::cout << " >= " << std::endl;
   if (d < c)
      std::cout << " < " << std::endl;
   if (d <= c)
      std::cout << " <= " << std::endl;
   if (d == c)
      std::cout << " == " << std::endl;
   if (d != c)
      std::cout << " != " << std::endl;
   std::cout << "--------a + b: " << a + b << "-------------" << std::endl;
   std::cout << "--------a - b: " << a - b << "-------------" << std::endl;
   std::cout << "--------a / b: " << a / b << "-------------" << std::endl;
   std::cout << "--------a * b: " << a * b << "-------------" << std::endl;
   std::cout << "--------b + c: " << b + c << "-------------" << std::endl;
   std::cout << "--------b - c: " << b - c << "-------------" << std::endl;
   std::cout << "--------b / c: " << b / c << "-------------" << std::endl;
   std::cout << "--------b * c: " << b * c << "-------------" << std::endl;
   return 0;
}