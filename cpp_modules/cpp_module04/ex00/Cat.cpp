#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat" << std::endl;
}

Cat::Cat(const Cat &cat)
{
    (*this) = cat;
}

Cat::~Cat()
{
    std::cout << "End Animal" << type << std::endl;
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