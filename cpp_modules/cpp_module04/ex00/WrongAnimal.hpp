#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &animal);
        WrongAnimal(const std::string &type);
        ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &animal);
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif