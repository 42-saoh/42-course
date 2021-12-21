#include <string>
#include <iostream>

struct mystring : public std::string
{
    mystring(const char *str) : std::string(str)
    {
        size_t i = 0;

        while (i < size())
        {
            char x = at(i);
            if (x >= 'a' && x <= 'z')
                x -= 32;
            std::cout << x;
            i++;
        }
    }
};