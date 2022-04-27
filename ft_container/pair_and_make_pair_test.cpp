#include <utility> 
#include <iostream>
#include <string>
#include "utils.hpp"

int main ()
{
    std::cout << "---------- std --------" << std::endl;
    {
        std::pair <std::string,double> product1;
        std::pair <std::string,double> product2 ("tomatoes",2.30);
        std::pair <std::string,double> product3 (product2);

        product1 = std::make_pair(std::string("lightbulbs"),0.99);

        product2.first = "shoes";
        product2.second = 39.90;

        std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
        std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
        std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;
    }
    std::cout << "---------- make_pair --------" << std::endl;
    {
        std::pair <int,int> foo;
        std::pair <int,int> bar;

        foo = std::make_pair (10,20);
        bar = std::make_pair (10.5,'A');

        std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
        std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    }
    std::cout << "---------- ft --------" << std::endl;
    {
        ft::pair <std::string,double> product1;
        ft::pair <std::string,double> product2 ("tomatoes",2.30);
        ft::pair <std::string,double> product3 (product2);

        product1 = ft::make_pair(std::string("lightbulbs"),0.99);

        product2.first = "shoes";
        product2.second = 39.90;

        std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
        std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
        std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;
    }
    std::cout << "---------- make_pair --------" << std::endl;
    {
        ft::pair <int,int> foo;
        ft::pair <int,int> bar;

        foo = ft::make_pair (10,20);
        bar = ft::make_pair (10.5,'A');

        std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
        std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    }
}