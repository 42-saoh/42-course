#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        const Weapon *weapon;
    
    public:
        HumanB(std::string p_name);
        HumanB(std::string p_name, const Weapon &p_weapon);
        void setWeapon(const Weapon &p_weapon);
        void attack();
};

#endif