#include "Karen.hpp"

int main (int argc,  char **argv)
{
    Karen karen;

    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (0);
    }
    if (karen.filter(argv[1]))
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}