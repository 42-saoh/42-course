#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *Source[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &m);
        ~MateriaSource();
        MateriaSource &operator=(const MateriaSource &m);
        void learnMateria(AMateria *);
        AMateria* createMateria(const std::string &type);
};

#endif