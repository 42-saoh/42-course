#include "FragTrap.hpp"


FragTrap::FragTrap(std::string &name) : ClapTrap(name)
{
    Hit_points = 100;
    Energy_point = 100;
    Attack_damage = 30;
    std::cout << "FragTrap " << Name << " create" << std::endl;   
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft)
{
    (*this) = ft;
    std::cout << "FragTrap " << Name << " copy create" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << Name << " delete" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ft)
{
    (ClapTrap &)(*this) = (ClapTrap &)ft;
    return (*this);
}

void FragTrap::attack(std::string const &target)
{
    std::cout << "FragTrap " << Name << " attack " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void FragTrap::takeDamege(unsigned int amount)
{
    std::cout << "FragTrap " << Name << " take " << amount << " points of damage!" << std::endl;
    if (amount < 2147483648 && Hit_points > (int)amount)
        Hit_points -= amount;
    else
        Hit_points = 0;
}

void FragTrap::beRepaired(unsigned int amount)
{
    std::cout << "FragTrap " << Name << " be repaired " << amount << " Hit points!" << std::endl;
    if (amount + Hit_points <= 2147483647)
        Hit_points += amount;
    else
        std::cout << "check the amount(range : 0 ~ 2147483647 - Hit_points)" << std::endl;
}

void FragTrap::showStatus(void) const
{
    std::cout << "FragTrap " << Name << "'s status" << std::endl;
    std::cout << "Hit points : " << Hit_points << std::endl;
    std::cout << "Energy point : " << Energy_point << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " high five!!" << std::endl;
}