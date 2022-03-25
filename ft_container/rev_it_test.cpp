#include "utils.hpp"
#include <iostream>
#include <iterator>
#include <vector> 
#include <map>

int main()
{
    
    std::vector<int> v;
    
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    using RevIt = std::reverse_iterator<std::vector<int>::iterator>;

    const std::vector<int>::iterator it = v.begin() + 3;
    {
        RevIt r_it(it);
    
        std::cout << "*it == " << *it << '\n'
                << "*r_it == " << *r_it << '\n'
                << "*r_it.base() == " << *r_it.base() << '\n'
                << "*(r_it.base()-1) == " << *(r_it.base() - 1) << '\n';

        std::cout << "*r_it == " << *(++r_it) << std::endl;
        std::cout << "*r_it == " << *(r_it++) << std::endl;
        std::cout << "*r_it == " << *(r_it--) << std::endl;
        std::cout << "*r_it == " << *(--r_it) << std::endl;

        std::cout << "*r_it == " << *(r_it - 2) << std::endl;
        std::cout << "*r_it == " << *(r_it + 2) << std::endl;

        r_it += 2;
        std::cout << "r_it == " << *(r_it) << std::endl;
        r_it -= 2;
        std::cout << "r_it == " << *(r_it) << std::endl;
        std::cout << "r_it == " << r_it[-1] << std::endl;
        std::cout << "r_it == " << r_it[0] << std::endl;
        std::cout << "r_it == " << r_it[1] << std::endl;

        RevIt r_it2 = 1 + r_it;

        std::cout << "rit2 " << *r_it2 << std::endl;
        std::cout << "value = " << r_it2 - r_it << std::endl;

        if (r_it < r_it2)
            std::cout << " < " << std::endl;
        if (r_it <= r_it2)
            std::cout << " <= " << std::endl;
        if (r_it > r_it2)
        {}
        else
            std::cout << " > " << std::endl;
        if (r_it >= r_it2)
        {}
        else
            std::cout << " >= " << std::endl;
        if (r_it < r_it)
            std::cout << " < " << std::endl;
        if (r_it <= r_it)
            std::cout << " <= " << std::endl;
        if (r_it > r_it)
            std::cout << " > " << std::endl;
        if (r_it >= r_it)
            std::cout << " >= " << std::endl;
        if (r_it == r_it)
            std::cout << " == " << std::endl;
        if (r_it != r_it) {}
        else
            std::cout << " != " << std::endl;
    }
    {
        std::map<int,std::string> numbers;
        numbers.insert (std::make_pair(1,"one"));
        numbers.insert (std::make_pair(2,"two"));
        numbers.insert (std::make_pair(3,"three"));

        typedef std::map<int,std::string>::iterator map_iter;

        std::reverse_iterator<map_iter> rev_end (numbers.begin());

        std::reverse_iterator<map_iter> rev_iterator (numbers.end());

        for ( ; rev_iterator != rev_end ; ++rev_iterator )
            std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
    }


    std::cout << " ----------ft------------- " << std::endl;
    {
        using Revft = ft::reverse_iterator<std::vector<int>::iterator>;
        Revft r_ft(it);

        std::cout << "*it == " << *it << '\n'
                << "*r_ft == " << *r_ft << '\n'
                << "*r_ft.base() == " << *r_ft.base() << '\n'
                << "*(r_ft.base()-1) == " << *(r_ft.base() - 1) << '\n';

        std::cout << "*r_ft == " << *(++r_ft) << std::endl;
        std::cout << "*r_ft == " << *(r_ft++) << std::endl;
        std::cout << "*r_ft == " << *(r_ft--) << std::endl;
        std::cout << "*r_ft == " << *(--r_ft) << std::endl;

        std::cout << "*r_ft == " << *(r_ft - 2) << std::endl;
        std::cout << "*r_ft == " << *(r_ft + 2) << std::endl;

        r_ft += 2;
        std::cout << "r_ft == " << *(r_ft) << std::endl;
        r_ft -= 2;
        std::cout << "r_ft == " << *(r_ft) << std::endl;
        std::cout << "r_ft == " << r_ft[-1] << std::endl;
        std::cout << "r_ft == " << r_ft[0] << std::endl;
        std::cout << "r_ft == " << r_ft[1] << std::endl;

        Revft r_ft2 = 1 + r_ft;

        std::cout << "rft2 " << *r_ft2 << std::endl;
        std::cout << "value = " << r_ft2 - r_ft << std::endl;

        if (r_ft < r_ft2)
            std::cout << " < " << std::endl;
        if (r_ft <= r_ft2)
            std::cout << " <= " << std::endl;
        if (r_ft > r_ft2)
        {}
        else
            std::cout << " > " << std::endl;
        if (r_ft >= r_ft2)
        {}
        else
            std::cout << " >= " << std::endl;
        if (r_ft < r_ft)
            std::cout << " < " << std::endl;
        if (r_ft <= r_ft)
            std::cout << " <= " << std::endl;
        if (r_ft > r_ft)
            std::cout << " > " << std::endl;
        if (r_ft >= r_ft)
            std::cout << " >= " << std::endl;
        if (r_ft == r_ft)
            std::cout << " == " << std::endl;
        if (r_ft != r_ft) {}
        else
            std::cout << " != " << std::endl;
    }
    {
        std::map<int,std::string> numbers;
        numbers.insert (std::make_pair(1,"one"));
        numbers.insert (std::make_pair(2,"two"));
        numbers.insert (std::make_pair(3,"three"));

        typedef std::map<int,std::string>::iterator map_iter;

        ft::reverse_iterator<map_iter> rev_end (numbers.begin());

        ft::reverse_iterator<map_iter> rev_iterator (numbers.end());

        for ( ; rev_iterator != rev_end ; ++rev_iterator )
            std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
    }
}