#include "Triangle.hpp"

int main()
{
   Point p0(3, 1);
   Point p1(3, 3);
   Point p2(1, 3);
   Point p(2, 1);
   if (bsp(p0, p1, p2, p))
      std::cout << "in" << std::endl;
   else
      std::cout << "out" << std::endl;
   return 0;
}