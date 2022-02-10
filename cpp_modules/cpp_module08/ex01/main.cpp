#include "span.hpp"

int main()
{
    {
        Span sp = Span(10);

        for(int i = 0; i < 10; i++)
        {
            sp.addNumber(std::rand() % 10000);
        }

        sp.print_all();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    Span sp(10);
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(std::rand() % 10000);
    }
    sp.addNumber(vec.begin(), vec.end());
    sp.print_all();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}