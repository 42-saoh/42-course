#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal" << std::endl;
    type = "default";
}

Animal::Animal(const std::string &type) : type(type) {}

Animal::Animal(const Animal &animal)
{
    (*this) = animal;
}

Animal::~Animal()
{
    std::cout << "End Animal " << type << std::endl;
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