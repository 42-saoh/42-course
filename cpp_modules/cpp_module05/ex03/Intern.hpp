#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        Form *RoboF(void);
        Form *PresF(void);
        Form *ShruF(void);

    public:
        Form *makeForm(const std::string &f_name, const std::string &target);
        
};

#endif