#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
        Bureaucrat b("saoh", 2);
        const Form *r = new RobotomyRequestForm("R");
        const Form *s = new ShrubberyCreationForm("S");
        const Form *p = new PresidentialPardonForm("P");


        std::cout << b << std::endl;
        std::cout << *r << std::endl;
        std::cout << *s << std::endl;
        std::cout << *p << std::endl;
        b.signForm(*r);
        b.signForm(*s);
        b.signForm(*p);
        b.executeForm(*r);
        b.executeForm(*s);
        b.executeForm(*p);
}