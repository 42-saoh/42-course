#include "Animal.hpp"

Animal::Animal() : type("default")
{
    std::cout << "Animal" << std::endl;
}

Animal::Animal(const std::string &type) : type(type)
{
    std::cout << "Animal " << type << std::endl;
}

Animal::Animal(const Animal &animal)
{
    (*this) = animal;
}

Animal::~Animal()
{
    std::cout << "End Animal" << type << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    type = animal.getType();
    return (*this);
}

std::string Animal::getType(void) const
{
    return (type);
}