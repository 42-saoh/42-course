#include <iostream>

int main()
{
    char *a = (char *)malloc(10000000);
    
    if (a == NULL)
        std::cout << "error" << std::endl;
    else
        std::cout << (void *)a << std::endl;
}