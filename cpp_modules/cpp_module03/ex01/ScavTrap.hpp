#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string &name);
        ScavTrap(const ScavTrap &st);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &st);
        void attack(std::string const &target);
        void takeDamege(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStatus(void) const;
        void guardGate(void);
};

#endif