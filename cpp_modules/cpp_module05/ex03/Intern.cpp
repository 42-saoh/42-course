#include "Intern.hpp"

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

Form *Intern::makeForm(const std::string &f_name, const std::string &target)
{
    Form *(Intern::*make_form[])() = {&Intern::RoboF, &Intern::PresF, &Intern::ShruF};
    std::string form_name[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    for (int i = 0; i < 3; i++)
    {
        if (form_name[i] == f_name)
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