#include "Brain.hpp"

Brain::Brain()
{
    memset(&ideas, 0, sizeof(std::string) * 100);
}

Brain::~Brain() {}

Brain::Brain(const Brain &b)
{
    (*this) = b;
}

Brain &Brain::operator=(const Brain &b)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = b.ideas[i];
    return (*this);
}