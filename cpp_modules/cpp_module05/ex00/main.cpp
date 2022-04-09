#include "Bureaucrat.hpp"

int main()
{ 
    try
    {
        Bureaucrat b("saoh", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------" << std::endl;
    try
    {
        Bureaucrat b("saoh", 151);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------" << std::endl;
    try
    {
        Bureaucrat b("saoh", 150);
        std::cout << b << std::endl;
        b.decreaseGrade(1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------" << std::endl;
    try
    {
        Bureaucrat b("saoh", 1);
        std::cout << b << std::endl;
        b.increaseGrade(1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "----------" << std::endl;
    try
    {
        Bureaucrat b("saoh", 1);
        std::cout << b << std::endl;
        Bureaucrat c(b);
        std::cout << c << std::endl;
        Bureaucrat d;
        d = c;
        std::cout << d << std::endl;
        c.increaseGrade(1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}