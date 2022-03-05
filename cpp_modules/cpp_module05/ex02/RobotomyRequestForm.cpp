#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequest", 72), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p) : Form("RobotomyRequest", 72)
{
    (*this) = p;
}

RobotomyRequestForm::~RobotomyRequestForm() throw() {}

void RobotomyRequestForm::action(void) const
{
    time_t time_now;

    time(&time_now);
    int i = (rand() + static_cast<int>(time_now)) % 2;
    if (i)
        std::cout << _target << " : drrrrrrrrrrrrrrrrrrr\nsuccess" << std::endl;
    else
        std::cout << _target << " : drrrrrrrrrrrrrrrrrrr\nfail" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() <= get_grade())
        action();
    else
        GradeTooLowException();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &p)
{
    _target = p._target;
    return (*this);
}