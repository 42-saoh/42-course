#include <string>
#include <iostream>

struct mystring : public std::string
{
    mystring(const char *str);
};