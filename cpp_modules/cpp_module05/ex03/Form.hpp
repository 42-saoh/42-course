#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"
# include "NotSign.hpp"

class Bureaucrat;

class Form : public GradeTooHighException, public GradeTooLowException, public NotSign
{
    private:
        const std::string _name;
        const int _signed_grade;
        const int _execute_grade;
        bool is_signed;
        Form &operator=(const Form &f);

    public:
        Form();
        Form(const std::string name, int s_grade, int e_grade);
        Form(const Form &f);
        virtual ~Form() throw();
        void beSigned(const Bureaucrat &b);
        std::string get_name(void) const;
        bool get_is_signed(void) const;
        int get_signed_grade(void) const;
        int get_execute_grade(void) const;
        void execute(const Bureaucrat &executor) const;
        virtual void action(void) const = 0;
        virtual void get_target(const std::string &target) = 0;
};

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif