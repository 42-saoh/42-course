#include "mystring.hpp"

int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 1;
        while (i < argc - 1)
        {
            mystring str(argv[i]);
            std::cout << " ";
            i++;
        }
        mystring str(argv[i]);
    }
    std::cout << std::endl;
}