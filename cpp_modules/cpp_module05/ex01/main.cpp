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
        try
        {
            Form a("f4", 151);
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
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        b.signForm(s);
}