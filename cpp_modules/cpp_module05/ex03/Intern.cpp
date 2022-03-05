#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &i)
{
    (*this) = i;
}
Intern &Intern::operator=(const Intern &i)
{
    i.nothing();
    return (*this);
}

Intern::~Intern() {}

Form *Intern::RoboF(void)
{
    Form *result = new RobotomyRequestForm();
    return (result);
}

Form *Intern::PresF(void)
{
    Form *result = new PresidentialPardonForm();
    return (result);
}

Form *Intern::ShruF(void)
{
    Form *result = new ShrubberyCreationForm();
    return (result);
}

void Intern::nothing(void) const {}

Form *Intern::makeForm(const std::string &f_name, const std::string &target)
{
    Form *(Intern::*make_form[])() = {&Intern::RoboF, &Intern::PresF, &Intern::ShruF};
    std::string form_name[3] = {"robotomy", "presidential", "shrubbery"};

    for (int i = 0; i < 3; i++)
    {
        if (f_name.find(form_name[i], 0) < form_name[i].size())
        {
            Form *result = ((this)->*make_form[i])();
            result->get_target(target);
            std::cout << "Intern creates " << result->get_name() << std::endl;
            return (result);
        }
    }
    std::cout << "Intern doesn't create " << f_name << " becuase the requested form is not known" << std::endl;
    return (0);
}