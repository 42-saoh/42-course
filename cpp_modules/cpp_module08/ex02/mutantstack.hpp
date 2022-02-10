#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <algorithm>

template <typename T>
class mutantstack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        iterator begin(void)
        {
            return (this->c.begin());
        }
        iterator end(void)
        {
            return (this->c.end());
        }
        reverse_iterator rbegin(void)
        {
            return (this->c.rbegin());
        }
        reverse_iterator rend(void)
        {
            return (this->c.rend());
        }
};

#endif