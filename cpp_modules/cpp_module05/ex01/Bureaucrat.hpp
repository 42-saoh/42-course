#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat : public std::exception
{
    private:
        const std::string _name;
        int _grade;

    public:
        static int GradeTooHighException(void);
        static int GradeTooLowException(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &b);
        ~Bureaucrat() throw();
        Bureaucrat &operator=(const Bureaucrat &b);
        void increaseGrade(int inc);
        void decreaseGrade(int dec);
        void signForm(Form &f);
        const std::string &getName(void) const;
        int getGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif