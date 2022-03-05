#include "Bureaucrat.hpp"

int main()
{
        Bureaucrat b("saoh", 2);
        Form f("f1", 3);
        Form s("f2", 1);

        try
        {
            Form a("f4", 0);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "------------------" << std::endl;
        try
        {
            Form a("f4", 151);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "--------------------" << std::endl;
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        std::cout << "--------------------" << std::endl;
        b.signForm(f);
        std::cout << "--------------------" << std::endl;
        b.signForm(s);
}