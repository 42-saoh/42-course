#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <ctime>

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &r);
        ~RobotomyRequestForm() throw();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &r);
        void get_target(const std::string &target);
        void action(void) const;
        void execute(const Bureaucrat &executor) const;

};

#endif