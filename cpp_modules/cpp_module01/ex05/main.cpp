#include "Karen.hpp"

int main (int argc,  char **argv)
{
    Karen karen;
    int i = 1;

    while (i < argc)
    {
        karen.complain(argv[i]);
        i++;
    }
}