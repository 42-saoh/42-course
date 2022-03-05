#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default", "_clap_name"), FragTrap(), ScavTrap(), Name("default")
{
    Hit_points = get_frag_hitpoint();
    Energy_point = get_scav_energe_point();
    Attack_damage = get_frag_attack_damage();
    std::cout << "DiamondTrap " << Name << " create" << std::endl;   
}

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name, "_clap_name"), FragTrap(), ScavTrap(), Name(name)
{
    Hit_points = get_frag_hitpoint();
    Energy_point = get_scav_energe_point();
    Attack_damage = get_frag_attack_damage();
    std::cout << "DiamondTrap " << Name << " create" << std::endl;   
}

DiamondTrap::DiamondTrap(const DiamondTrap &ft) : ClapTrap(ft), FragTrap(ft), ScavTrap(ft)
{
    (*this) = ft;
    std::cout << "DiamondTrap " << Name << " copy create" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << Name << " delete" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ft)
{
    (ClapTrap &)(*this) = (ClapTrap &)ft;
    (FragTrap &)(*this) = (FragTrap &)ft; 
    (ScavTrap &)(*this) = (ScavTrap &)ft;
    Name = ft.Name;
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
    if (amount + Hit_points <= 2147483647)
        Hit_points += amount;
    else
        std::cout << "check the amount(range : 0 ~ 2147483647 - Hit_points)" << std::endl;
}

void DiamondTrap::showStatus(void) const
{
    std::cout << "DiamondTrap " << Name << "'s status" << std::endl;
    std::cout << "Hit points : " << Hit_points << std::endl;
    std::cout << "Energy point : " << Energy_point << std::endl;
    std::cout << "Attact damage : " << Attack_damage << std::endl;
}

 void DiamondTrap::whoami(void)
 {
     std::cout << "DiamondTrap name : " << Name << std::endl;
     std::cout << "ClapTrap name : " << ClapTrap::Name << std::endl;
 }