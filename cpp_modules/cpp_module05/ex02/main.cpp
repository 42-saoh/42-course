#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
        Bureaucrat b("saoh", 2);
        Bureaucrat c("ohsa", 150);
        Form *r = new RobotomyRequestForm("R");
        Form *s = new ShrubberyCreationForm("S");
        Form *p = new PresidentialPardonForm("P");


        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << *r << std::endl;
        std::cout << *s << std::endl;
        std::cout << *p << std::endl;
        std::cout << "--------b-------" << std::endl;
        b.signForm(*r);
        b.signForm(*s);
        b.signForm(*p);
        std::cout << "--------c-------" << std::endl;
        c.signForm(*r);
        c.signForm(*s);
        c.signForm(*p);
        std::cout << "--------b-------" << std::endl;
        for (int i = 0; i < 10; i++)
        {
                b.executeForm(*r);
                std::cout << "---------------" << std::endl;
        }
        b.executeForm(*s);
        std::cout << "---------------" << std::endl;
        b.executeForm(*p);
        std::cout << "--------c-------" << std::endl;
        for (int i = 0; i < 10; i++)
        {
                c.executeForm(*r);
                std::cout << "---------------" << std::endl;
        }
        c.executeForm(*s);
        std::cout << "---------------" << std::endl;
        c.executeForm(*p);
}