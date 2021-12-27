#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
    Zombie *zom1 = new Zombie(name);
    return (zom1);
}