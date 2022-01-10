#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal" << std::endl;
    type = "default";
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type) {}

WrongAnimal::WrongAnimal(const WrongAnimal &Wronganimal)
{
    (*this) = Wronganimal;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "End WrongAnimal" << type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &Wronganimal)
{
    type = Wronganimal.getType();
    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "default! default!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (type);
}