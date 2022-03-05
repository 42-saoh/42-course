#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include <fstream>


class ShrubberyCreationForm : public Form
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &p);
        ~ShrubberyCreationForm() throw();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &p);
        void action(void) const;
        void execute(const Bureaucrat &executor) const;
};

#endif