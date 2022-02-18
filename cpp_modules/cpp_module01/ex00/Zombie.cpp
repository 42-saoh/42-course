#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << "<" << name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(void)
{
    std::cout << "<" << name << "> delete" << std::endl;
}