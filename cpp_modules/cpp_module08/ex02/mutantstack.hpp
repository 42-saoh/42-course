#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &m) : std::stack<T>(m) {}
        ~MutantStack() {}
        MutantStack &operator=(const MutantStack &m)
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