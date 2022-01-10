#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include <exception>

# define TOO_HIGH 0
# define TOO_LOW 1

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        static int GradeTooHighException(void);
        static int GradeTooLowException(void);
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &b);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &b);
        void  increaseGrade(int inc);
        void  decreaseGrade(int dec);
        const std::string &getName(void) const;
        int getGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif