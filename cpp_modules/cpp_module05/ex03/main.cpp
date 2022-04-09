#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat b("saoh", 2);
    Intern someRandomIntern;
    Form* rrf;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }
    std::cout << "-----------------------" << std::endl;
    rrf = 0;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    if (rrf)
    {
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }
    std::cout << "-----------------------" << std::endl;
    rrf = 0;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    if (rrf)
    {
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }
    rrf = 0;
    std::cout << "-----------------------" << std::endl;
    rrf = 0;
    rrf = someRandomIntern.makeForm("ssdfjio", "Bender");
    if (rrf)
    {
        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }
    rrf = 0;
}