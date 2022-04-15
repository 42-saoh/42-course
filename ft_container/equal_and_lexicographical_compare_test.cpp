#include <iostream> 
#include "utils.hpp"
#include <vector>
#include <algorithm>

bool mypredicate(int i, int j)
{
    return (i == j);
}

bool mycomp(char c1, char c2)
{
    return (std::tolower(c1) < std::tolower(c2));
}


int main ()
{
    {
      int myints[] = {20,40,60,80,100};
      std::vector<int>myvector (myints, myints+5);

      if ( std::equal (myvector.begin(), myvector.end(), myints) )
        std::cout << "The contents of both sequences are equal.\n";
      else
        std::cout << "The contents of both sequences differ.\n";

        if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
        std::cout << "The contents of both sequences are equal.\n";
      else
        std::cout << "The contents of both sequences differ.\n";

      myvector[3]=81;

        if ( std::equal (myvector.begin(), myvector.end(), myints) )
        std::cout << "The contents of both sequences are equal.\n";
      else
        std::cout << "The contents of both sequences differ.\n";

      if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
        std::cout << "The contents of both sequences are equal.\n";
      else
        std::cout << "The contents of both sequences differ.\n";
    }

    std::cout << "--------------- lex_com ------------ " << std::endl;
    {
        char foo[]="Apple";
        char bar[]="apartment";

        std::cout << std::boolalpha;

        std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

        std::cout << "Using default comparison (operator<): ";
        std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9) << std::endl;

        std::cout << "Using mycomp as comparison object: ";
        std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp) << std::endl;
    }

    std::cout << "--------------- ft ------------ " << std::endl;
    {
      int myints[] = {20,40,60,80,100};
      std::vector<int>myvector (myints, myints+5);

      if ( ft::equal (myvector.begin(), myvector.end(), myints) )
        std::cout << "The contents of both sequences are equal.\n";
      else
        std::cout << "The contents of both sequences differ.\n";

        if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
        std::cout << "The contents of both sequences are equal.\n";
      else
        std::cout << "The contents of both sequences differ.\n";

      myvector[3]=81;

        if ( ft::equal (myvector.begin(), myvector.end(), myints) )
        std::cout << "The contents of both sequences are equal.\n";
      else
        std::cout << "The contents of both sequences differ.\n";

      if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
        std::cout << "The contents of both sequences are equal.\n";
      else
        std::cout << "The contents of both sequences differ.\n";
    }

    std::cout << "--------------- lex_com ------------ " << std::endl;
    {
        char foo[]="Apple";
        char bar[]="apartment";

        std::cout << std::boolalpha;

        std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

        std::cout << "Using default comparison (operator<): ";
        std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9) << std::endl;

        std::cout << "Using mycomp as comparison object: ";
        std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp) << std::endl;
    }

    return 0;
}