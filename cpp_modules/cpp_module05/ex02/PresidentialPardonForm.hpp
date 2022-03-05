#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &p);
        ~PresidentialPardonForm() throw();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &p);
        void execute(const Bureaucrat &executor) const;
        void action(void) const;
};

#endif