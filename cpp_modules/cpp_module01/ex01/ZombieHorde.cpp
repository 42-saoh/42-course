#include "Zombie.hpp"

std::string put_name(const std::string name, int i)
{
    std::string result = name;
    int div = 100000;

    while (div)
    {
        result += (((i / div) % 10) + 48);
        div /= 10;
    }
    return (result);
}

Zombie* Zombie::zombieHorde(int n, std::string name)
{
    if (n >= 1000000)
    {
        std::cout << "Too Big number Sorry" << std::endl;
        return (NULL);
    }
    Zombie *zomhorde = new Zombie[n];
    int i = 0;

    if (!zomhorde)
    {
        std::cout << "Memory alloc error" << std::endl;
        return (NULL);
    }
    while (i < n)
    {
        zomhorde[i].get_name(put_name(name, i));
        i++;
    }
    return (zomhorde);
}