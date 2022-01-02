#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string &name) : ClapTrap()
{
    Name = name;
    Hit_points = 100;
    Energy_point = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap " << Name << " create" << std::endl;   
}

ScavTrap::ScavTrap(const ScavTrap &st)
{
    std::cout << "ScavTrap " << Name << " copy create" << std::endl;
    (*this) = st;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " delete" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &st)
{
    Name = st.Name;
    Hit_points = st.Hit_points;
    Energy_point = st.Energy_point;
    Attack_damage = st.Attack_damage;
    return (*this);
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << Name << " have enterred in Gate keeper mode." << std::endl;
}