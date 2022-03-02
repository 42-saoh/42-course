#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string &_name) : Name(_name), Hit_points(10), Energy_point(10), Attack_damage(0)
{
    std::cout << "ClapTrap " << Name << " create" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
    (*this) = ct;
    std::cout << "ClapTrap " << Name << " copy create" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " delete" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct)
{
    Name = ct.Name;
    Hit_points = ct.Hit_points;
    Energy_point = ct.Energy_point;
    Attack_damage = ct.Attack_damage;
    return (*this);
}

void ClapTrap::attack(std::string const &target)
{
    std::cout << "ClapTrap " << Name << " attack " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamege(unsigned int amount)
{
    std::cout << "ClapTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    if (amount < 2147483648 && Hit_points > (int)amount)
        Hit_points -= amount;
    else
        Hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << Name << " be repaired " << amount << " Hit points!" << std::endl;
    if (amount + Hit_points <= 2147483647)
        Hit_points += amount;
    else
        std::cout << "check the amount(range : 0 ~ 2147483647 - Hit_points)" << std::endl;
}

void ClapTrap::showStatus(void) const
{
    std::cout << "ClapTrap " << Name << "'s status" << std::endl;
    std::cout << "Hit points : " << Hit_points << std::endl;
    std::cout << "Energy point : " << Energy_point << std::endl;
}