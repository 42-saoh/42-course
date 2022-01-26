#include "Data.hpp"

int main()
{
    uintptr_t ptr = Data::serialize(new Data());
    Data *p = Data::deserialize(ptr);

    p->print_data();
}