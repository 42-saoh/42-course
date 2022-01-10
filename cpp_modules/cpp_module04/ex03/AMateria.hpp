#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(const std::string &type);
        AMateria(const AMateria &Am);
        virtual ~AMateria();
        AMateria &operator=(const AMateria &Am);
        const std::string &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif