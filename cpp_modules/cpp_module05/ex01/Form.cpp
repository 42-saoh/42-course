#include "Form.hpp"

Form::Form()
    : _name("default"), _signed_grade(150), _execute_grade(150), is_signed(false) {}

Form::Form(const std::string name, int s_grade, int e_grade)
    : _name(name), _signed_grade(s_grade), _execute_grade(e_grade), is_signed(false)
{
    if (s_grade < 1)
        GradeTooHighException("signed grade");
    else if (s_grade > 150)
        GradeTooLowException("signed grade");
    if (e_grade < 1)
        GradeTooHighException("execute grade");
    else if (e_grade > 150)
        GradeTooLowException("execute grade");
}

Form::Form(const Form &f) : _name(f.get_name()), _signed_grade(f.get_signed_grade()) \
    , _execute_grade(f.get_execute_grade()), is_signed(get_is_signed()) {}

Form::~Form() throw() {}

Form &Form::operator=(const Form &f)
{
    is_signed = f.get_is_signed();
    const_cast<int &>(_signed_grade) = f.get_signed_grade();
    const_cast<int &>(_execute_grade) = f.get_execute_grade();
    const_cast<std::string &>(_name) = f.get_name();
    return (*this);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() < get_signed_grade())
        is_signed = true;
    else
        GradeTooLowException();
}

std::string Form::get_name(void) const
{
    return (_name);
}

bool Form::get_is_signed(void) const
{
    return (is_signed);
}

int Form::get_signed_grade(void) const
{
    return (_signed_grade);
}

int Form::get_execute_grade(void) const
{
    return (_execute_grade);
}

int Form::GradeTooHighException(std::string s)
{
    throw std::out_of_range("Form has too high " + s);
}

int Form::GradeTooLowException(std::string s)
{
    throw std::out_of_range("Form has too low " + s);
}

int Form::GradeTooLowException(void)
{
    throw std::out_of_range("'s grade too row");
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form " << f.get_name() << " is ";
    if (f.get_is_signed())
        os << "signed and ";
    else
        os << "not signed and ";
    os << f.get_name() << "'s signed grade is " << f.get_signed_grade() \
        << " and execute grade is " << f.get_execute_grade();
    return (os);
}