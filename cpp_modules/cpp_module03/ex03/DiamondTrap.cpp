#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(), FragTrap(), ScavTrap()
{
    ClapTrap::Name = name + "_clap_name";
    Name = name;
    std::cout << "DiamondTrap " << Name << " create" << std::endl;   
}

DiamondTrap::DiamondTrap(const DiamondTrap &ft)
{
    std::cout << "DiamondTrap " << Name << " copy create" << std::endl;
    (*this) = ft;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << Name << " delete" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ft)
{
    Name = ft.Name;
    Hit_points = ft.Hit_points;
    Energy_point = ft.Energy_point;
    Attack_damage = ft.Attack_damage;
    return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamege(unsigned int amount)
{
    std::cout << "DiamondTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    if (amount < 2147483648 && Hit_points > (int)amount)
        Hit_points -= amount;
    else
        Hit_points = 0;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    std::cout << "DiamondTrap " << Name << " be repaired " << amount << " Hit points!" << std::endl;
    Hit_points += amount;
}

void DiamondTrap::showStatus(void) const
{
    std::cout << "DiamondTrap " << Name << "'s status" << std::endl;
    std::cout << "Hit points : " << Hit_points << std::endl;
    std::cout << "Energy point : " << Energy_point << std::endl;
}

 void DiamondTrap::whoami(void)
 {
     std::cout << "DiamondTrap name : " << Name << std::endl;
     std::cout << "ClapTrap name : " << ClapTrap::Name << std::endl;
 }