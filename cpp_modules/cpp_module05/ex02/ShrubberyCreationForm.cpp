#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreation", 25), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &p) : Form("ShrubberyCreation", 25)
{
    (*this) = p;
}

void ShrubberyCreationForm::action(void) const
{
    std::string img("               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_");
    std::string filename = _target + "_shrubbery";
    std::fstream fs;

    fs.open(filename, std::fstream::out | std::fstream::trunc);
    fs.write(img.c_str(), img.size());
    fs.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() <= get_grade())
        action();
    else
        GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &p)
{
    _target = p._target;
    return (*this);
}