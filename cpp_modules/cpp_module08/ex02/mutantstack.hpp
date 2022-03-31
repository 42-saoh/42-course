#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <algorithm>

template <typename T>
class mutantstack : public std::stack<T>
{
    public:
        mutantstack() : std::stack<T>() {}
        mutantstack(const mutantstack &m) : std::stack<T>(m) {}
        ~mutantstack() {}
        mutantstack &operator=(const mutantstack &m)
        {
            static_cast<std::stack<T> >(*this) = static_cast<std::stack<T> >(m);
            return (*this);
        }
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