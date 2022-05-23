#ifndef SET_HPP
# define SET_HPP
# include <memory>
# include "utils.hpp"
# include "tree.hpp"

namespace ft
{
    template <class _Key, class _Compare = std::less<_Key>, class _Alloc = std::allocator<_Key> >
    class set
    {
        public:
            typedef _Key key_type;
            typedef _Key value_type;
            typedef _Compare key_compare;
            typedef _Compare value_compare;
            typedef _Alloc   allocator_type;

        private:
            typedef typename _Alloc::template rebind<_Key>::other _Key_alloc_type;
            typedef ft::_Rb_tree<key_type, value_type, ft::_Identity<value_type>, key_compare, _Key_alloc_type> _RBT_type;
            _RBT_type _M_t;

        public:
            typedef typename _Key_alloc_type::pointer pointer;
            typedef typename _Key_alloc_type::const_pointer const_pointer;
            typedef typename _Key_alloc_type::reference reference;
            typedef typename _Key_alloc_type::const_reference const_reference;
            typedef typename _RBT_type::const_iterator iterator;
            typedef typename _RBT_type::const_iterator const_iterator;
            typedef typename _RBT_type::const_reverse_iterator reverse_iterator;
            typedef typename _RBT_type::const_reverse_iterator const_reverse_iterator;
            typedef typename _RBT_type::size_type size_type;
            typedef typename _RBT_type::difference_type difference_type;

            set() : _M_t() {}
            explicit set(const _Compare &_comp, const allocator_type &_a = allocator_type()) : _M_t(_comp, _a) {}

            template<typename _InputIterator>
            set(_InputIterator _first, _InputIterator _last) : _M_t()
            {
                _M_t.insert(_first, _last);
            }

            template<typename _InputIterator>
            set(_InputIterator _first, _InputIterator _last, const _Compare &_comp, const allocator_type &_a = allocator_type())
                : _M_t(_comp, _a)
            {
                _M_t.insert(_first, _last);
            }

            set(const set &_x) : _M_t(_x._M_t) {}
            
            set &operator=(const set &_x)
            {
                _M_t = _x._M_t;
                return (*this);
            }

            key_compare key_comp() const
            {
                return (_M_t.key_comp());
            }

            value_compare value_comp() const
            {
                return (_M_t.key_comp());
            }

            allocator_type get_allocator() const
            {
                return (_M_t.get_allocator());
            }

            iterator begin() const
            {
                return (_M_t.begin());
            }
 
            iterator end() const
            {
                return (_M_t.end());
            }

            reverse_iterator rbegin() const
            {
                return (_M_t.rbegin());
            }

            reverse_iterator rend() const
            {
                return (_M_t.rend());
            }

            bool empty() const
            {
                return (_M_t.empty());
            }

            size_type size() const
            {
                return (_M_t.size());
            }

            size_type max_size() const
            {
                return (_M_t.max_size());
            }

            void swap(set &_x)
            {
                _M_t.swap(_x._M_t);
            }

            ft::pair<iterator, bool> insert(const value_type &_x)
            {
                ft::pair<typename _RBT_type::iterator, bool> _p = _M_t.insert(_x);
                return (ft::pair<iterator, bool>(_p.first, _p.second));
            }

            iterator insert(const iterator _pos, const value_type &_x)
            {
                return (_M_t.insert(_pos, _x));
            }

            template<typename _InputIterator>
            void insert(_InputIterator _first, _InputIterator _last)
            {
                _M_t.insert(_first, _last);
            }

            void erase(iterator _pos)
            {
                _M_t.erase(_pos);
            }

            size_type erase(const key_type &_x)
            {
                return (_M_t.erase(_x));
            }

            void erase(iterator _first, iterator _last)
            {
                _M_t.erase(_first, _last);
            }

            void clear()
            {
                _M_t.clear();
            }

            size_type count(const key_type &_x) const
            {
                return (_M_t.find(_x) == _M_t.end() ? 0 : 1);
            }
            
            iterator find(const key_type &_x)
            {
                return (_M_t.find(_x));
            }

            const_iterator find(const key_type &_x) const
            {
                return (_M_t.find(_x));
            }

            iterator lower_bound(const key_type &_x)
            {
                return (_M_t.lower_bound(_x));
            }

            const_iterator lower_bound(const key_type &_x) const
            {
                return (_M_t.lower_bound(_x));
            }

            iterator upper_bound(const key_type &_x)
            {
                return (_M_t.upper_bound(_x));
            }

            const_iterator upper_bound(const key_type &_x) const
            {
                return (_M_t.upper_bound(_x));
            }

            ft::pair<iterator, iterator> equal_range(const key_type &_x)
            {
                return (_M_t.equal_range(_x));
            }

            ft::pair<const_iterator, const_iterator> equal_range(const key_type &_x) const
            {
                return (_M_t.equal_range(_x));
            }

            template <typename _K, typename _Comp, typename _Al>
            friend bool operator==(const set<_K, _Comp, _Al> &_x,
                                    const set<_K, _Comp, _Al> &_y);
            
            template <typename _K, typename _Comp, typename _Al>
            friend bool operator<(const set<_K, _Comp, _Al> &_x,
                                    const set<_K, _Comp, _Al> &_y);
    };

    template <typename _Key, typename _Compare, typename _Alloc>
    bool operator==(const set<_Key, _Compare, _Alloc> &_x,
                    const set<_Key, _Compare, _Alloc> &_y)
    {
        return (_x._M_t == _y._M_t);
    }

    template <typename _Key, typename _Compare, typename _Alloc>
    bool operator<(const set<_Key, _Compare, _Alloc> &_x,
                    const set<_Key, _Compare, _Alloc> &_y)
    {
        return (_x._M_t < _y._M_t);
    }

    template <typename _Key, typename _Compare, typename _Alloc>
    bool operator!=(const set<_Key, _Compare, _Alloc> &_x,
                    const set<_Key, _Compare, _Alloc> &_y)
    {
        return (!(_x == _y));
    }

    template <typename _Key, typename _Compare, typename _Alloc>
    bool operator>(const set<_Key, _Compare, _Alloc> &_x,
                    const set<_Key, _Compare, _Alloc> &_y)
    {
        return (_y < _x);
    }

    template <typename _Key, typename _Compare, typename _Alloc>
    bool operator<=(const set<_Key, _Compare, _Alloc> &_x,
                    const set<_Key, _Compare, _Alloc> &_y)
    {
        return (!(_y < _x));
    }

    template <typename _Key, typename _Compare, typename _Alloc>
    bool operator>=(const set<_Key, _Compare, _Alloc> &_x,
                    const set<_Key, _Compare, _Alloc> &_y)
    {
        return (!(_x < _y));
    }

    template <typename _Key, typename _Compare, typename _Alloc>
    void swap(set<_Key, _Compare, _Alloc> &_x, set<_Key, _Compare, _Alloc> &_y)
    {
        _x.swap(_y);
    }
}

#endif