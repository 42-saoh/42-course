#include "Bureaucrat.hpp"

int main()
{
        Bureaucrat b("saoh", 2);
        Form f("f1", 3, 2);
        Form s("f2", 1, 1);

        try
        {
            Form a("f4", 0, 3);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "------------------" << std::endl;
        try
        {
            Form a("f4", 151, 150);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "--------------------" << std::endl;
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        std::cout << "--------------------" << std::endl;
        b.signForm(f);
        std::cout << "--------------------" << std::endl;
        b.signForm(s);
}