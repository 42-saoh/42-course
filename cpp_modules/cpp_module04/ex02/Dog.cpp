#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    brain = new Brain();
    std::cout << "Dog" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    (*this) = dog;
    std::cout << "Copy Dog" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "End Dog " << type << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    type = dog.getType();
    if (dog.brain)
    {
        if (!brain)
            brain = new Brain();
        *brain = *dog.brain;
    }
    return (*this);
}

void Dog::makeSound(void)
{
    std::cout << "Wal! Wal!" << std::endl;
}