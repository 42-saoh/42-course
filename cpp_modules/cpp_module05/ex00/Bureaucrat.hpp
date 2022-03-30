#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <exception>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat : public GradeTooHighException, public GradeTooLowException
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &b);
        ~Bureaucrat() throw();
        Bureaucrat &operator=(const Bureaucrat &b);
        void  increaseGrade(int inc);
        void  decreaseGrade(int dec);
        const std::string &getName(void) const;
        int getGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif