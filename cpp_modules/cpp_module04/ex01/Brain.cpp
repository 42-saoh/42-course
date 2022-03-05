#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain create" << std::endl;
    memset(&ideas, 0, sizeof(std::string) * 100);
}

Brain::~Brain()
{
    std::cout << "Brain delete" << std::endl;
}

Brain::Brain(const Brain &b)
{
    (*this) = b;
    std::cout << "Brain copy" << std::endl;
}

Brain &Brain::operator=(const Brain &b)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = b.ideas[i];
    return (*this);
}