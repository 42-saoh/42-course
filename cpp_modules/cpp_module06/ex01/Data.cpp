#include "Data.hpp"

Data::Data() : a(1), b("2"), c(3), d(4), e(5) {}

void Data::print_data(void)
{
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;
    std::cout << "d : " << d << std::endl;
    std::cout << "e : " << e << std::endl;
}

uintptr_t Data::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Data::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}