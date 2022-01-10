#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequest", 72), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p) : Form("RobotomyRequest", 72)
{
    (*this) = p;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action(void) const
{
    time_t time_now;

    time(&time_now);
    int i = time_now % 2;
    if (i)
        std::cout << _target << " : drrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\n success" << std::endl;
    else
        std::cout << _target << " : drrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\ndrrrrrrrrrrrrrrrrrrr\n fail" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() <= get_grade())
        action();
    else
        throw (GradeTooLowException());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &p)
{
    _target = p._target;
    return (*this);
}