#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &c);
        ~Cure();
        Cure &operator=(const Cure &c);
        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif