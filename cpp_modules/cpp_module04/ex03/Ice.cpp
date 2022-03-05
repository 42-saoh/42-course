#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {}

Ice::Ice(const Ice &i) : AMateria(i) {}

Ice &Ice::operator=(const Ice &i)
{
    _type = i.getType();
    return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const
{
    AMateria *result = new Ice();
    return (result);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}