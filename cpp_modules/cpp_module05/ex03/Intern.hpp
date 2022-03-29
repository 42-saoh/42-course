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
        std::string form_name[3];

    public:
        Intern();
        Intern(const Intern &i);
        ~Intern();
        Intern &operator=(const Intern &i);
        void nothing(void) const;
        Form *makeForm(const std::string &f_name, const std::string &target);
        
};

#endif