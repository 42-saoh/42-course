#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(const std::string &type)
{
    for (size_t i = 0; i < type.size(); i++)
        _type += tolower(type[i]);
}
AMateria::~AMateria(void) {}
AMateria::AMateria(const AMateria &Am)
{
    (*this) = Am;
}

AMateria &AMateria::operator=(const AMateria &Am)
{
    _type = Am.getType();
    return (*this);
}

const std::string &AMateria::getType() const
{
    return (_type);
}