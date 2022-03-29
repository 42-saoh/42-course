#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequest", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequest", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p) : Form("RobotomyRequest", 72, 45), _target(p._target) {}

RobotomyRequestForm::~RobotomyRequestForm() throw() {}

void RobotomyRequestForm::action(void) const
{
    int i = rand() % 2;
    
    if (i)
        std::cout << _target << " : drrrrrrrrrrrrrrrrrrr\nsuccess" << std::endl;
    else
        std::cout << _target << " : drrrrrrrrrrrrrrrrrrr\nfail" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &p)
{
    _target = p._target;
    return (*this);
}