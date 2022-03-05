#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default")
{
    std::cout << "WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
    std::cout << "WrongAnimal " << type << std::endl;
}

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