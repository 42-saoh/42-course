#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form : public std::exception
{
    private:
        const std::string _name;
        const int _grade;
        bool is_signed;

    public:
        static int GradeTooHighException(void);
        static int GradeTooLowException(void);
        Form(const std::string name, int _grade);
        Form(const Form &f);
        ~Form() throw();
        Form &operator=(const Form &f);
        void beSigned(const Bureaucrat &b);
        std::string get_name(void) const;
        bool get_is_signed(void) const;
        int get_grade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif