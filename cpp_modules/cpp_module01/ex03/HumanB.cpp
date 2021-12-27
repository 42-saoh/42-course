#include "HumanB.hpp"

HumanB::HumanB(std::string p_name)
    : name(p_name), weapon(0) {}

HumanB::HumanB(std::string p_name, const Weapon &p_weapon) : name(p_name)
{
    weapon = &p_weapon;
}

void HumanB::setWeapon(const Weapon &p_weapon)
{
    weapon = &p_weapon;
}

void HumanB::attack()
{
    if (weapon == 0)
        std::cout << name << " attacks with his fist" << std::endl;
    else
        std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}