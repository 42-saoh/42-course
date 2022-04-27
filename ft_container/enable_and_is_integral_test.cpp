#include <iostream>
#include "utils.hpp"
#include <type_traits>

template <class T, class U = typename ft::enable_if<ft::is_integral<T>::value>::type>
struct ft_test
{
    void operator()(T a)
    {
        std::cout << "T : " << a << std::endl;
    }
};

template <class T, class U = typename std::enable_if<std::is_integral<T>::value>::type>
struct std_test
{
    void operator()(T a)
    {
        std::cout << "T : " << a << std::endl;
    }
};

int main()
{
    std::cout << "---------------- std -------------" << std::endl;
    {
        std_test<int> b;
        std_test<char> c;
        b(1);
        c(49);
        std::cout << std::boolalpha;
        std::cout << "bool : " << std::is_integral<bool>::value << std::endl;
        std::cout << "char : " << std::is_integral<char>::value << std::endl;
        std::cout << "wchar_t : " << std::is_integral<wchar_t>::value << std::endl;
        std::cout << "signed char : " << std::is_integral<signed char>::value << std::endl;
        std::cout << "short int : " << std::is_integral<short int>::value << std::endl;
        std::cout << "int : " << std::is_integral<int>::value << std::endl;
        std::cout << "long int : " << std::is_integral<long int>::value << std::endl;
        std::cout << "long long int : " << std::is_integral<long long int>::value << std::endl;
        std::cout << "unsigned char : " << std::is_integral<unsigned char>::value << std::endl;
        std::cout << "unsigned short int : " << std::is_integral<unsigned short int>::value << std::endl;
        std::cout << "unsigned int : " << std::is_integral<unsigned int>::value << std::endl;
        std::cout << "unsigned long int : " << std::is_integral<unsigned long int>::value << std::endl;
        std::cout << "unsigned long long int : " << std::is_integral<unsigned long long int>::value << std::endl;
        std::cout << "double : " << std::is_integral<double>::value << std::endl;
        std::cout << "float : " << std::is_integral<float>::value << std::endl;
    }
    std::cout << "---------------- ft -------------" << std::endl;
    {
        ft_test<int> b;
        ft_test<char> c;
        b(1);
        c(49);
        std::cout << std::boolalpha;
        std::cout << "bool : " << ft::is_integral<bool>::value << std::endl;
        std::cout << "char : " << ft::is_integral<char>::value << std::endl;
        std::cout << "wchar_t : " << ft::is_integral<wchar_t>::value << std::endl;
        std::cout << "signed char : " << ft::is_integral<signed char>::value << std::endl;
        std::cout << "short int : " << ft::is_integral<short int>::value << std::endl;
        std::cout << "int : " << ft::is_integral<int>::value << std::endl;
        std::cout << "long int : " << ft::is_integral<long int>::value << std::endl;
        std::cout << "long long int : " << ft::is_integral<long long int>::value << std::endl;
        std::cout << "unsigned char : " << ft::is_integral<unsigned char>::value << std::endl;
        std::cout << "unsigned short int : " << ft::is_integral<unsigned short int>::value << std::endl;
        std::cout << "unsigned int : " << ft::is_integral<unsigned int>::value << std::endl;
        std::cout << "unsigned long int : " << ft::is_integral<unsigned long int>::value << std::endl;
        std::cout << "unsigned long long int : " << ft::is_integral<unsigned long long int>::value << std::endl;
        std::cout << "double : " << ft::is_integral<double>::value << std::endl;
        std::cout << "float : " << ft::is_integral<float>::value << std::endl;
    }
}