#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooLowException();
    else if (_grade > 150)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
    (*this) = b;
}

Bureaucrat::~Bureaucrat() throw() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    const_cast<std::string &>(_name) = b.getName();
    _grade = b.getGrade();
    return (*this);
}

void  Bureaucrat::increaseGrade(int inc)
{
    if (inc + _grade > 150)
        GradeTooHighException();
    _grade += inc;

}

void  Bureaucrat::decreaseGrade(int dec)
{
    if (_grade - dec < 1)
        throw GradeTooLowException();
    _grade -= dec;
}

const std::string &Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

int Bureaucrat::GradeTooHighException(void)
{
    throw std::out_of_range("Too large number");
}

int Bureaucrat::GradeTooLowException(void)
{
    throw std::out_of_range("Too small number");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}