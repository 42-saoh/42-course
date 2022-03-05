#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "-----------------" << std::endl;

    const Animal *k[10];
    for (int i = 0; i < 10; i++)
    {
        if (!(i % 2))
            k[i] = new Dog();
        else
            k[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        delete k[i];
    }
}
