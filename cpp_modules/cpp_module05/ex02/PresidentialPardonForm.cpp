#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon", 145, 137), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardon", 145, 137), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form("PresidentialPardon", 145, 137), _target(p._target) {}

PresidentialPardonForm::~PresidentialPardonForm() throw() {}

void PresidentialPardonForm::action(void) const
{
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p)
{
    _target = p._target;
    return (*this);
}