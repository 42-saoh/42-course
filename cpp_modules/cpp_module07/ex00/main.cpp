#include <iostream>
#include <string>
#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    {
        std::cout << "---------------------" << std::endl;
        int i = 0, j = 1;

        std::cout << "i : " << i << ", j : " << j << std::endl;
        swap(i, j);
        std::cout << "i : " << i << ", j : " << j << std::endl;
        std::cout << "min : " << min(i, j) << ", max : " << max(i, j) << std::endl;
    }
    {
        std::cout << "---------------------" << std::endl;
        char i = 'a', j = 'b';

        std::cout << "i : " << i << ", j : " << j << std::endl;
        swap(i, j);
        std::cout << "i : " << i << ", j : " << j << std::endl;
        std::cout << "min : " << min(i, j) << ", max : " << max(i, j) << std::endl;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::string i = "a", j = "b";

        std::cout << "i : " << i << ", j : " << j << std::endl;
        swap(i, j);
        std::cout << "i : " << i << ", j : " << j << std::endl;
        std::cout << "min : " << min(i, j) << ", max : " << max(i, j) << std::endl;
    }
    {
        std::cout << "---------------------" << std::endl;
        std::string i = "a", j = "a";

        std::cout << "i capacity : " << i.capacity() << ", j capacity : " << j.capacity() << std::endl;
        j.reserve(100);
        std::cout << "i capacity : " << i.capacity() << ", j capacity : " << j.capacity() << std::endl;
        std::cout << "min : " << min(i, j).capacity() << ", max : " << max(i, j).capacity() << std::endl;
        swap(i, j);
        std::cout << "i capacity : " << i.capacity() << ", j capacity : " << j.capacity() << std::endl;
    }
}