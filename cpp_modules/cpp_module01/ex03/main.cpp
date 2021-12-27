#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
        Weapon spear = Weapon("crude spear");
        jim.setWeapon(spear);
        jim.attack();
    }
}