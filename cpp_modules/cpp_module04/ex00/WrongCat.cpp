#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &Wrongcat) : WrongAnimal(Wrongcat)
{
    std::cout << "Copy WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "End WrongCat" << type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &Wrongcat)
{
    type = Wrongcat.getType();
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "wal! wal!" << std::endl;
}