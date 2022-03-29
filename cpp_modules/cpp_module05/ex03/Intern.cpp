#include "Intern.hpp"

Intern::Intern()
{
    form_name[0] = "robotomy";
    form_name[1] = "presidential";
    form_name[2] = "shrubbery";
}

Intern::Intern(const Intern &i)
{
    form_name[0] = "robotomy";
    form_name[1] = "presidential";
    form_name[2] = "shrubbery";
}

Intern &Intern::operator=(const Intern &i)
{
    form_name[0] = "robotomy";
    form_name[1] = "presidential";
    form_name[2] = "shrubbery";
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
    std::cerr << "Intern doesn't create " << f_name << " becuase the requested form is not known" << std::endl;
    return (0);
}