#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    memset(Source, 0, sizeof(AMateria *) * 4);
}

MateriaSource::MateriaSource(const MateriaSource &m)
{
    memset(Source, 0, sizeof(AMateria *) * 4);
    (*this) = m;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &m)
{
    for (int i = 0; i < 4 && m.Source[i]; i++)
    {
        Source[i] = m.Source[i]->clone();
    }
    return (*this);
}


MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete Source[i];
}

void MateriaSource::learnMateria(AMateria *src)
{
    for (int i = 0; i < 4; i++)
    {
        if (!Source[i])
        {
            Source[i] = src;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < 4 && Source[i]; i++)
    {
        if (Source[i]->getType() == type)
            return (Source[i]->clone());
    }
    return (0);
}

