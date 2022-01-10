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
        virtual ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &ct);
        virtual void attack(std::string const &target);
        virtual void takeDamege(unsigned int amount);
        virtual void beRepaired(unsigned int amount);
        virtual void showStatus(void) const;
};

#endif