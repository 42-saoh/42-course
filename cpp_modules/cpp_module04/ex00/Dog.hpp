#ifndef Dog_HPP
# define Dog_HPP
# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &dog);
        ~Dog();
        Dog &operator=(const Dog &dog);
        void makeSound(void) const;
};

#endif