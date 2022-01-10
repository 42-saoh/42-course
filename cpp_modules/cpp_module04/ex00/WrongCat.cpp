#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &Wrongcat)
{
    (*this) = Wrongcat;
}

WrongCat::~WrongCat()
{
    std::cout << "End WrongAnimal" << type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &Wrongcat)
{
    type = Wrongcat.getType();
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "miew! miew!" << std::endl;
}