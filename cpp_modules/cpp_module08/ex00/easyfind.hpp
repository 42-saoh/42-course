#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <deque> 
# include <algorithm>

void add_string(int i, std::string &msg)
{
    std::string tmp("");

    if (i == 0)
    {
        msg += '0';
        return ;
    }
    while(i > 0)
    {
        tmp += (i % 10) + '0';
        i /= 10;
    }
    int tmp_size = tmp.size();
    for (int i = 0; i < tmp_size; i++)
    {
        msg += tmp[tmp_size - 1 - i];
    }
}

template <typename T>
typename T::iterator easyfind(T &array, int i)
{
    typename T::iterator a = find(array.begin(), array.end(), i);
    if (a == array.end())
    {
        std::string msg = "don't have value : ";
        add_string(i, msg);
        throw std::runtime_error(msg.c_str());
    }
    return (a);
}

#endif