#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string &name);
        FragTrap(const FragTrap &ht);
        virtual ~FragTrap();
        FragTrap &operator=(const FragTrap &ht);
        void attack(std::string const &target);
        void takeDamege(unsigned int amount);
        void beRepaired(unsigned int amount);
        void showStatus(void) const;
        void highFivesGuys(void);
};

#endif