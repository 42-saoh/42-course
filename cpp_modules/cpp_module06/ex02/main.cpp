#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
# include <ctime>
# include <cstdlib>

Base *generate(void)
{
    time_t time_now;

    time(&time_now);
    int i = (time_now + rand()) % 3;
    switch (i)
    {
        case 0:
        return (new A());
        case 1:
        return (new B());
        case 2:
        return (new C());
    }
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Something wrong" << std::endl;
}

void identify(Base& p)
{
    int i = 0;

    try
    {
        A a = dynamic_cast<A &>(p);
        i = 1;
    }
    catch(const std::exception &e) {}
    try
    {
        B b = dynamic_cast<B &>(p);
        i = 2;
    }
    catch(const std::exception &e) {}
    try
    {
        C c = dynamic_cast<C &>(p);
        i = 3;
    }
    catch(const std::exception &e) {}
    switch (i)
    {
        case 1:
        std::cout << "A" << std::endl;
        break;
    
        case 2:
        std::cout << "B" << std::endl;
        break;

        case 3:
        std::cout << "C" << std::endl;
        break;

        default:
        std::cout << "Something wrong" << std::endl;
        break;
    }
}

int main()
{
    Base *p = generate();
    if (!p)
    {
        std::cout << "Something wrong" << std::endl;
        return (0);
    }
    identify(p);
    identify(*p);
    delete p;
}