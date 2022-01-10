#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat" << std::endl;
}

Cat::Cat(const Cat &cat)
{
    (*this) = cat;
}

Cat::~Cat()
{
    std::cout << "End Animal " << type << std::endl;
    delete brain;
}

Cat &Cat::operator=(const Cat &cat)
{
    type = cat.getType();
    if (!brain)
        brain = new Brain();
    if (cat.brain)
        *brain = *cat.brain;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "miew! miew!" << std::endl;
}