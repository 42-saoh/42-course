#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string &name);
        ScavTrap(const ScavTrap &st);
        virtual ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &st);
        void attack(std::string const &target);
        void takeDamege(unsigned int amount);
        void beRepaired(unsigned int amount);
        int get_scav_energe_point(void) const;
        void showStatus(void) const;
        void guardGate(void);
};

#endif