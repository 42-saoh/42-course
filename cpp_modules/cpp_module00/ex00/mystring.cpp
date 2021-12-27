#include "mystring.hpp"

mystring::mystring(const char *str) : std::string(str)
{
    size_t i = 0;

    while (i < size())
        std::cout << static_cast<char>(std::toupper(str[i++]));
}