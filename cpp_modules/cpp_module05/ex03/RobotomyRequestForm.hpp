#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <cstdlib>

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
        void action(void) const;
        void get_target(const std::string &target);
};

#endif