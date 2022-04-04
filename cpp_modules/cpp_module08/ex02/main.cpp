#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    mstack.push(50);
    mstack.push(60);
    mstack.push(70);
    mstack.push(80);

    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    std::cout << "----------------" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "----------------" << std::endl;
    for(MutantStack<int>::reverse_iterator start = mstack.rbegin(); start < mstack.rend(); start++)
    {
        std::cout << *start << std::endl;
    }
    std::cout << "----------------" << std::endl;
    std::stack<int> s(mstack);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.size() << std::endl;
    std::cout << "----------------" << std::endl;
    {
        std::list<int> a;

        a.push_back(10);
        a.push_back(20);
        a.push_back(30);
        a.push_back(40);
        a.push_back(50);
        a.push_back(60);
        a.push_back(70);
        a.push_back(80);

        std::cout << *(--a.end()) << std::endl;
        a.pop_back();
        std::cout << a.size() << std::endl;
        std::cout << "----------------" << std::endl;
        std::list<int>::iterator it = a.begin();
        std::list<int>::iterator ite = a.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
}