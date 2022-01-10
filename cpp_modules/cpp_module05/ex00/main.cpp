#include "Bureaucrat.hpp"

int main()
{
    
    try
    {
        Bureaucrat b("saoh", 0);
        std::cout << b << std::endl;
    }
    catch (int ex)
    {
        switch (ex)
        {
            case TOO_HIGH:
                std::cout << "Too High Grade, Grade range 1 ~ 150" << std::endl;
                break ;

            case TOO_LOW:
                std::cout << "Too Low Grade, Grade range 1 ~ 150" << std::endl;
                break ;
            
            default:
                std::cout << "Something wrong" << std::endl;
                return (0);
        }
    }
    std::cout << "----------" << std::endl;
    try
    {
        Bureaucrat b("saoh", 151);
        std::cout << b << std::endl;
    }
    catch (int ex)
    {
        switch (ex)
        {
            case TOO_HIGH:
                std::cout << "Too High Grade, Grade range 1 ~ 150" << std::endl;
                break ;

            case TOO_LOW:
                std::cout << "Too Low Grade, Grade range 1 ~ 150" << std::endl;
                break ;
            
            default:
                std::cout << "Something wrong" << std::endl;
                return (0);
        }
    }
    std::cout << "----------" << std::endl;
    try
    {
        Bureaucrat b("saoh", 150);
        std::cout << b << std::endl;
        b.increaseGrade(1);
    }
    catch (int ex)
    {
        switch (ex)
        {
            case TOO_HIGH:
                std::cout << "Too High Grade, Grade range 1 ~ 150" << std::endl;
                break ;

            case TOO_LOW:
                std::cout << "Too Low Grade, Grade range 1 ~ 150" << std::endl;
                break ;
            
            default:
                std::cout << "Something wrong" << std::endl;
                return (0);
        }
    }
    std::cout << "----------" << std::endl;
    try
    {
        Bureaucrat b("saoh", 1);
        std::cout << b << std::endl;
        b.decreaseGrade(1);
    }
    catch (int ex)
    {
        switch (ex)
        {
            case TOO_HIGH:
                std::cout << "Too High Grade, Grade range 1 ~ 150" << std::endl;
                break ;

            case TOO_LOW:
                std::cout << "Too Low Grade, Grade range 1 ~ 150" << std::endl;
                break ;
            
            default:
                std::cout << "Something wrong" << std::endl;
                return (0);
        }
    }
    std::cout << "----------" << std::endl;
    try
    {
        Bureaucrat b("saoh", 1);
        std::cout << b << std::endl;
        Bureaucrat c(b);
        std::cout << c << std::endl;
        c.decreaseGrade(1);
    }
    catch (int ex)
    {
        switch (ex)
        {
            case TOO_HIGH:
                std::cout << "Too High Grade, Grade range 1 ~ 150" << std::endl;
                break ;

            case TOO_LOW:
                std::cout << "Too Low Grade, Grade range 1 ~ 150" << std::endl;
                break ;
            
            default:
                std::cout << "Something wrong" << std::endl;
                return (0);
        }
    }
}