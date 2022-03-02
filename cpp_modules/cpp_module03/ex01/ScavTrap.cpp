#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
    Hit_points = 100;
    Energy_point = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap " << Name << " create" << std::endl;   
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st)
{
    std::cout << "ScavTrap " << Name << " copy create" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " delete" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st)
{
    (ClapTrap &)(*this) = (ClapTrap &)st;
    return (*this);
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << Name << " have enterred in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
    std::cout << "ScavTrap " << Name << " attack " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamege(unsigned int amount)
{
    std::cout << "ScavTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    if (amount < 2147483648 && Hit_points > (int)amount)
        Hit_points -= amount;
    else
        Hit_points = 0;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    std::cout << "ScavTrap " << Name << " be repaired " << amount << " Hit points!" << std::endl;
    Hit_points += amount;
}

void ScavTrap::showStatus(void) const
{
    std::cout << "ScavTrap " << Name << "'s status" << std::endl;
    std::cout << "Hit points : " << Hit_points << std::endl;
    std::cout << "Energy point : " << Energy_point << std::endl;
}