#include <iostream>
#include <string>

int main()
{
    std::string src("HI THIS IS BRAIN");
    std::string &s = src;
    std::string *a;

    a = &src;
    std::cout << static_cast<void *>(a) << std::endl;
    std::cout << *a << std::endl;
    std::cout << static_cast<void *>(&s) << std::endl;
    std::cout << s << std::endl;
    std::cout << static_cast<void *>(&src) << std::endl;
    std::cout << src << std::endl;
}