#include <iostream>

int foo() _NOEXCEPT { return 0; }

int bar() _NOEXCEPT { throw 1; }

int main()
{
    foo();
    try
    {
        bar();
    }
    catch (int x)
    {
        std::cout << "Error : " << x << std::endl;
    }
}