#include "Vector.hpp"
#include <iostream>

int main()
{
    ft::vector<int> a(5);
    ft::vector<int> b(1);

    std::cout << a.size() << std::endl;
    std::cout << a.capacity() << std::endl;
    a.push_back(5);
    for (ft::vector<int>::iterator k = a.begin(); k < a.end(); k++)
    {
        std::cout << *k << std::endl;
    }
    std::cout << a.size() << std::endl;
    std::cout << a.capacity() << std::endl;
    b.swap(a);
    std::cout << a.size() << std::endl;
    std::cout << a.capacity() << std::endl;
    std::cout << b.size() << std::endl;
    std::cout << b.capacity() << std::endl;
}