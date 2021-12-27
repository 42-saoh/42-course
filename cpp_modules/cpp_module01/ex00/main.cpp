#include "Zombie.hpp"

int main()
{
    Zombie zom1("zom1");
    Zombie *a;
    
    zom1.announce();
    a = Zombie::newZombie("zom2");
    a->announce();
    Zombie::randomChump("zom3");
    delete a;
}