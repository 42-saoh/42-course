#include "Span.hpp"

int main()
{
    {
        Span sp = Span(10);

        srand(time(0));
        for(int i = 0; i < 10; i++)
        {
            sp.addNumber(std::rand() % 10000);
        }

        sp.print_all();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << "--------------------" << std::endl;
    Span sp(20);
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(std::rand() % 10000);
    }
    sp.addNumber(vec.begin(), vec.end());
    sp.print_all();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "--------------------" << std::endl;
    Span w(sp);
    w.print_all();
    std::cout << w.shortestSpan() << std::endl;
    std::cout << w.longestSpan() << std::endl;
    try
    {
        w.addNumber(vec.begin(), vec.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Span ss(9);
        ss.addNumber(vec.begin(), vec.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}