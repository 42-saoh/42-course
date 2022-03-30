#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreation", 25, 5), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreation", 25, 5), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &p) : Form("ShrubberyCreation", 25, 5), _target(p._target) {}

void ShrubberyCreationForm::action(void) const
{
    std::string img =   "               ,@@@@@@@,\n"
						"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
						"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
						"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
						"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
						"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
						"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
						"       |o|        | |         | |\n"
						"       |.|        | |         | |\n"
						"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
    std::string filename = _target + "_shrubbery";
    std::fstream fs;

    fs.open(filename, std::fstream::out | std::fstream::trunc);
    fs.write(img.c_str(), img.size());
    fs.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw() {}

void ShrubberyCreationForm::get_target(const std::string &target)
{
    _target = target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &p)
{
    _target = p._target;
    return (*this);
}