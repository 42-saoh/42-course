#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "MateriaSource.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *inventory[4];

    public:
        Character(const std::string &name);
        Character(const Character &clone);
        ~Character();
        Character &operator=(const Character &clone);
        const std::string &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif