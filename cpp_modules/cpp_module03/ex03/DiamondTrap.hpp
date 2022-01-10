#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string Name;
        using FragTrap::Hit_points;
        using ScavTrap::Energy_point;
        using FragTrap::Attack_damage;

    public:
        DiamondTrap(std::string &name);
        DiamondTrap(const DiamondTrap &ht);
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &ht);
        void attack(std::string const &target);
        void takeDamege(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStatus(void) const;
        void guardGate(void);
        void highFivesGuys(void);
        void whoami(void);
};

#endif