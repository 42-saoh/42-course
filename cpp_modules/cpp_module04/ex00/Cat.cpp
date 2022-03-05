#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) 
{
    std::cout << "Copy Cat" << std::endl;
}

Cat::~Cat()
{
    std::cout << "End Cat" << type << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    type = cat.getType();
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "miew! miew!" << std::endl;
}