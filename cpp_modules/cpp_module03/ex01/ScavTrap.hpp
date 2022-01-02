#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string &name);
        ScavTrap(const ScavTrap &st);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &st);
        void guardGate(void);
};

#endif