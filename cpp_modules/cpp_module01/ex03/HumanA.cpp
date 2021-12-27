#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon &p_weapon) : name(name), weapon(p_weapon) {}

void HumanA::attack()
{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}