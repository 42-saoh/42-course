#include "iterator.hpp"
#include "utils.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> i;

    i.push_back(5);
    i.push_back(6);
    i.push_back(7);
    ft::back_insert_iterator<std::vector<int> > b_i = ft::back_inserter(i);
    b_i = 8;
    b_i = 9;
    ft::vector_iterator<std::vector<int>::iterator> m_i = i.begin();
    ft::vector_iterator<std::vector<int>::iterator> m_e(i.end());
    ft::vector_iterator<std::vector<int>::iterator> k = m_i + 2;
    std::cout << m_e - m_i << std::endl;
    std::cout << *k << std::endl;
    if (m_i != k)
        std::cout << "!=" << std::endl;
    for (;m_i < m_e; m_i++)
    {
        std::cout << *m_i << std::endl;
    }
}