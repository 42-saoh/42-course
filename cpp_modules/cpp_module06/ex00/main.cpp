#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Arguments error" << std::endl;
        return (0);
    }
    Convert c(argv[1]);
    if (c.is_error())
        return (0);
    c.tos();
    c.toi();
    c.tof();
    c.tod();
}