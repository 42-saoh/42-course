#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon", 145), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardon", 145), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form("PresidentialPardon", 145)
{
    (*this) = p;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::get_target(const std::string &target)
{
    _target = target;
}

void PresidentialPardonForm::action(void) const
{
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() <= get_grade())
        action();
    else
        throw (GradeTooLowException());
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
    _target = p._target;
    return (*this);
}