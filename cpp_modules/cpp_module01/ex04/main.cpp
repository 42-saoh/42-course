#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Arguments ERROR" << std::endl;
        return (0);
    }
    Replace arg(argv[1], argv[2], argv[3]);
    if (arg.is_s1_or_s2_error())
    {
        std::cout << "Argument string ERROR" << std::endl;
        return (0);
    }
    if (arg.fs_open())
        return (0);
    if (arg.read_and_write())
        std::cout << "read or write error" << std::endl;
    return (0);
}