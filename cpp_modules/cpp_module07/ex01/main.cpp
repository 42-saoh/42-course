#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
struct Print
{
    void operator()(T &a) { std::cout << a << std::endl; }
};

template <typename T>
struct Add_one
{
    void operator()(T &a) { ++a; }
};

int main()
{
    int i[100];
    Print<int> print;
    Add_one<int> ad;

    for (int j = 0; j < 100; j++)
        i[j] = j;
    iter(i, 100, print);
    iter(i, 100, ad);
    iter(i, 100, print);
}