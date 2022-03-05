#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &i);
        ~Ice();
        Ice &operator=(const Ice &i);
        AMateria *clone(void) const;
        void use(ICharacter &target);
};

#endif