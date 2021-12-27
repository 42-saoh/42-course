#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << "<" << name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::get_name(std::string z_name)
{
    name = z_name;
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(void)
{
    std::cout << "<" << name << "> delete" << std::endl;
}