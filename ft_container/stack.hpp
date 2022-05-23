#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft
{
    template <class _Tp, class _Container = vector<_Tp> >
    class stack
    {
        public:
            typedef _Container container_type;
            typedef typename container_type::value_type value_type;
            typedef typename container_type::reference reference;
            typedef typename container_type::const_reference const_reference;
            typedef typename container_type::size_type size_type;
            
        protected:
            container_type c;
        
        public:
            explicit stack(const container_type &_c = container_type()) : c(_c) {}

            bool empty() const
            {
                return (c.empty());
            }

            size_type size() const
            {
                return (c.size());
            }
        
            reference top()
            {
                return (c.back());
            }
        
            const_reference top() const
            {
                return (c.back());
            }

            void push(const value_type &_x)
            {
                c.push_back(_x);
            }
        
            void pop()
            {
                c.pop_back();
            }

            template<typename _Tp1, typename _Con>
            friend bool operator==(const stack<_Tp1, _Con> &, const stack<_Tp1, _Con> &);

            template<typename _Tp1, typename _Con>
            friend bool operator<(const stack<_Tp1, _Con> &, const stack<_Tp1, _Con> &);
    };

    template <typename _Tp, typename _Container>
    bool operator==(const stack<_Tp, _Container> &_x, const stack<_Tp, _Container> &_y)
    {
        return (_x.c == _y.c);
    }
  
    template <typename _Tp, typename _Container>
    bool operator<(const stack<_Tp, _Container> &_x, const stack<_Tp, _Container> &_y)
    {
        return (_x.c < _y.c);
    }

    template <typename _Tp, typename _Container>
    bool operator!=(const stack<_Tp, _Container> &_x, const stack<_Tp, _Container> &_y)
    {
        return (!(_x == _y));
    }

    template <typename _Tp, typename _Container>
    bool operator>(const stack<_Tp, _Container> &_x, const stack<_Tp, _Container> &_y)
    {
        return (_y < _x);
    }

    template <typename _Tp, typename _Container>
    bool operator<=(const stack<_Tp, _Container> &_x, const stack<_Tp, _Container> &_y)
    {
        return (!(_y < _x));
    }

    template <typename _Tp, typename _Container>
    bool operator>=(const stack<_Tp, _Container> &_x, const stack<_Tp, _Container> &_y)
    {
        return (!(_x < _y));
    }
}

#endif