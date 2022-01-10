#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {}

AMateria *Ice::clone() const
{
    AMateria *result = new Ice();
    return (result);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}