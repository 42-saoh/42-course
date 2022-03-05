#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    std::cout << "Copy Dog" << std::endl;
}

Dog::~Dog()
{
    std::cout << "End Dog" << type << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    type = dog.getType();
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Wal! Wal!" << std::endl;
}