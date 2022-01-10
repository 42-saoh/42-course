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
        b.executeForm(*rrf);
        delete rrf;
        rrf = 0;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        b.executeForm(*rrf);
        delete rrf;
        rrf = 0;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        b.executeForm(*rrf);
        delete rrf;
        rrf = 0;
}