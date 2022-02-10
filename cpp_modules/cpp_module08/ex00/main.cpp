#include "easyfind.hpp"

template <typename T>
void input(T &array, int i)
{
    array.push_back(i);
}

template <typename T, typename... Arg>
void input(T &array, int i, Arg... args)
{
    array.push_back(i);
    input(array, args...);
}

int main()
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;

    input(v, 1, 2, 3, 4, 5, 6, 7, 11, 15);
    input(l, 1, 2, 3, 4, 5, 6, 7);
    input(d, 1, 2, 3, 4, 5, 6, 7);
    try
    {
        std::cout << "vector ";
        std::vector<int>::iterator q = easyfind(v, 13);
        std::cout << "have value : " << *q << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "list ";
        std::list<int>::iterator j = easyfind(l, 5);
        std::cout << "have value : " << *j << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "deque ";
        std::deque<int>::iterator k = easyfind(d, 2);
        std::cout << "have value : "<< *k << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}