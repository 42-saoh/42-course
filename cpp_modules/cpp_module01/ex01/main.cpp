#include "Zombie.hpp"

int main()
{
    Zombie *a;

    a = Zombie::zombieHorde(999999, "zombie");
    int i = 0;
    while (i < 999999)
    {
        if (i % 10000 == 9876)
            a[i].announce();
        i++;
    }
    delete[] a;
}