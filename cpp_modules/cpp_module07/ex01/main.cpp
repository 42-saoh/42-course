#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void Print(T const &x)
{
    std::cout << x << std::endl;
};

int main()
{
    int i[100];

    for (int j = 0; j < 100; j++)
        i[j] = j;
    iter(i, 100, Print);
}