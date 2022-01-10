#include "Form.hpp"

Form::Form(const std::string name, int grade) : _name(name), _grade(grade), is_signed(false)
{
    if (_grade < 1)
        throw (GradeTooLowException());
    else if (_grade > 150)
        throw (GradeTooHighException());
}

Form::Form(const Form &f) : _name(""), _grade(0), is_signed(false)
{
    (*this) = f;
}

Form::~Form() {}

Form &Form::operator=(const Form &f)
{
    const_cast<bool &>(is_signed) = f.is_signed;
    const_cast<int &>(_grade) = f._grade;
    const_cast<std::string &>(_name) = f._name;
    return (*this);
}

void Form::beSigned(const Bureaucrat &b) const
{
    if (b.getGrade() < get_grade())
        const_cast<bool &>(is_signed) = true;
    else
        throw (GradeTooLowException());
}

std::string Form::get_name(void) const
{
    return (_name);
}

bool Form::get_is_signed(void) const
{
    return (is_signed);
}

int Form::get_grade(void) const
{
    return (_grade);
}

int Form::GradeTooHighException(void)
{
    return (TOO_HIGH);
}

int Form::GradeTooLowException(void)
{
    return (TOO_LOW);
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form " << f.get_name() << " is ";
    if (f.get_is_signed())
        os << "signed and ";
    else
        os << "not signed and ";
    os << f.get_name() << "'s grade is " << f.get_grade(); 
    return (os);
}