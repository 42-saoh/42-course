#include "Character.hpp"
#include <iostream>

Character::Character(const std::string &name) : _name(name)
{
    memset(inventory, 0, sizeof(AMateria *) * 4);
}

Character::Character(const Character &clone)
{
    (*this) = clone;
}

Character &Character::operator=(const Character &clone)
{
    MateriaSource matsrc;
    int i;

    _name = clone.getName();
    for (i = 0; i < 4; i++)
    {
        if (!clone.inventory[i])
        {
            i++;
            continue ;
        }
        matsrc.learnMateria(clone.inventory[i]);
    }
    for (i = 0; i < 4; i++)
        inventory[i] = matsrc.createMateria(clone.inventory[i]->getType());
    return (*this);
}

const std::string &Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria *m)
{
    int i = 0;

    if (m == 0)
        return ;
    while (i < 4 && inventory[i])
        i++;
    if (i == 4)
        return ;
    inventory[i] = m;
}

void Character::unequip(int idx)
{
    if (inventory[idx])
        inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (inventory[idx])
        inventory[idx]->use(target);
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}