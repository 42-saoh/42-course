#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {}

Cure::Cure(const Cure &c) : AMateria(c) {}

Cure &Cure::operator=(const Cure &c)
{
    _type = c.getType();
    return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() const
{
    AMateria *result = new Cure();
    return (result);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}