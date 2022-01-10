#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &animal);
        Animal(const std::string &type);
        virtual ~Animal();
        Animal &operator=(const Animal &animal);
        virtual void makeSound(void) const;
        std::string getType(void) const;
};

#endif