#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    std::cout << "Cat" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) 
{
    (*this) = cat;
    std::cout << "Copy Cat" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "End Cat " << type << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    type = cat.getType();
    if (cat.brain)
    {
        if (!brain)
            brain = new Brain();
        *brain = *cat.brain;
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "miew! miew!" << std::endl;
}