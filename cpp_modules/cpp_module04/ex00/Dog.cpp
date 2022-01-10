#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog" << std::endl;
}

Dog::Dog(const Dog &dog)
{
    (*this) = dog;
}

Dog::~Dog()
{
    std::cout << "End Animal" << type << std::endl;
}

Dog &Dog::operator=(const Dog &Dog)
{
    type = Dog.getType();
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Wal! Wal!" << std::endl;
}