#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

# define TOO_HIGH 0
# define TOO_LOW 1

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        static int GradeTooHighException(void);
        static int GradeTooLowException(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &b);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &b);
        void increaseGrade(int inc);
        void decreaseGrade(int dec);
        void signForm(const Form &f) const;
        const std::string &getName(void) const;
        void executeForm(const Form &f) const;
        int getGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif