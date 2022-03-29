#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        GradeTooLowException();
    else if (_grade > 150)
        GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b.getName()), _grade(b.getGrade()) {}

Bureaucrat::~Bureaucrat() throw() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    const_cast<std::string &>(_name) = b.getName();
    _grade = b.getGrade();
    return (*this);
}

void  Bureaucrat::decreaseGrade(int inc)
{
    if (inc + _grade > 150)
        GradeTooLowException();
    _grade += inc;

}

void  Bureaucrat::increaseGrade(int dec)
{
    if (_grade - dec < 1)
        throw GradeTooHighException();
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
    throw std::out_of_range("Bureaucrat has too high Grade");
}

int Bureaucrat::GradeTooLowException(void)
{
    throw std::out_of_range("Bureaucrat has too Low Grade");
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << getName() << " signs " << f.get_name() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << getName() << " cannot sign " << f.get_name() << " because " << getName() << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}