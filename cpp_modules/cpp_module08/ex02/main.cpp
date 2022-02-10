#include "mutantstack.hpp"

int main()
{
    mutantstack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    mstack.push(50);
    mstack.push(60);
    mstack.push(70);
    mstack.push(80);

    for(mutantstack<int>::iterator start = mstack.begin(); start < mstack.end(); start++)
    {
        std::cout << *start << std::endl;
    }
    std::cout << "----------------" << std::endl;
    for(mutantstack<int>::reverse_iterator start = mstack.rbegin(); start < mstack.rend(); start++)
    {
        std::cout << *start << std::endl;
    }
}