#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {}

AMateria *Cure::clone() const
{
    AMateria *result = new Cure();
    return (result);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}