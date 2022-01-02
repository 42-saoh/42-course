#ifndef  CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
    protected:
        std::string Name;
        int Hit_points;
        int Energy_point;
        int Attack_damage;

    public:
        ClapTrap();
        ClapTrap(std::string &_name);
        ClapTrap(const ClapTrap &ct);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &ct);
        void attack(std::string const &target);
        void takeDamege(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStatus(void) const;
};

#endif