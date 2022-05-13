#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "utils.hpp"
# include "tree.hpp"

namespace ft
{
    template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
                typename _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
    class map
    {
        public:
            typedef _Key key_type;
            typedef _Tp mapped_type;
            typedef ft::pair<const _Key, _Tp> value_type;
            typedef _Compare key_compare;
            typedef _Alloc allocator_type;

        protected:
            typedef typename _Alloc::value_type _Alloc_value_type;
            typedef typename _Alloc::template rebind<value_type>::other _Pair_alloc_type;
            typedef ft::_Rb_tree<key_type, value_type, ft::_Select1st<value_type>,
                                    key_compare, _Pair_alloc_type> _RBT_type;
            _RBT_type _M_t;

        public:
            typedef typename _Pair_alloc_type::pointer pointer;
            typedef typename _Pair_alloc_type::const_pointer const_pointer;
            typedef typename _Pair_alloc_type::reference reference;
            typedef typename _Pair_alloc_type::const_reference const_reference;
            typedef typename _RBT_type::iterator iterator;
            typedef typename _RBT_type::const_iterator const_iterator;
            typedef typename _RBT_type::size_type size_type;
            typedef typename _RBT_type::difference_type difference_type;
            typedef typename _RBT_type::reverse_iterator reverse_iterator;
            typedef typename _RBT_type::const_reverse_iterator const_reverse_iterator;

            map() : _M_t() {}
            
            explicit map(const _Compare &_comp, const allocator_type &_a = allocator_type()) : _M_t(_comp, _a) {}

            map(const map &_x) : _M_t(_x._M_t) {}

            template<typename _InputIterator>
            map(_InputIterator _first, _InputIterator _last) : _M_t()
            {
                _M_t._M_insert_unique(_first, _last);
            }

            template<typename _InputIterator>
            map(_InputIterator _first, _InputIterator _last, const _Compare &_comp,
                    const allocator_type &_a = allocator_type()) : _M_t(_comp, _a)
            {
                _M_t._M_insert_unique(_first, _last);
            }

            map &operator=(const map &_x)
            {
                _M_t = _x._M_t;
                return (*this);
            }

            allocator_type get_allocator() const
            {
                return (_M_t.get_allocator());
            }

            iterator begin()
            {
                return (_M_t.begin());
            }

            const_iterator begin() const
            {
                return (_M_t.begin());
            }

            iterator end()
            {
                return (_M_t.end());
            }

            const_iterator end() const
            {
                return (_M_t.end());
            }

            reverse_iterator rbegin()
            {
                return (_M_t.rbegin());
            }

            const_reverse_iterator rbegin() const
            {
                return (_M_t.rbegin());
            }

            reverse_iterator rend()
            {
                return (_M_t.rend());
            }

            const_reverse_iterator rend() const
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

            mapped_type &operator[](const key_type &_k)
            {
                iterator _i = lower_bound(_k);
                if (_i == end() || key_comp()(_k, (*_i).first))
                    _i = insert(_i, value_type(_k, mapped_type()));
                return ((*_i).second);
            }

            mapped_type &at(const key_type &_k)
            {
                iterator _i = lower_bound(_k);
                if (_i == end() || key_comp()(_k, (*_i).first))
                    std::out_of_range("map::at");
                return ((*_i).second);
            }

            const mapped_type &at(const key_type &_k) const
            {
                const_iterator _i = lower_bound(_k);
                if (_i == end() || key_comp()(_k, (*_i).first))
                    std::out_of_range("map::at");
                return ((*_i).second);
            }

            ft::pair<iterator, bool> insert(const value_type &_x)
            {
                return (*_M_t._M_insert_unique(_x));
            }

            iterator insert(iterator _pos, const value_type &_x)
            {
                return (_M_t._M_insert_unique_(_pos, _x));
            }

            template<typename _InputIterator>
            void insert(_InputIterator _first, _InputIterator _last)
            {
                _M_t._M_insert_unique(_first, _last);
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

            void swap(map &_x)
            {
                _M_t.swap(_x._M_t);
            }

            void clear()
            {
                _M_t.clear();
            }

            key_compare key_comp() const
            {
                return (_M_t.key_comp());
            }

            class value_compare : public ft::binary_function<value_type, value_type, bool>
            {
                friend class ft::map<_Key, _Tp, _Compare, _Alloc>;

                protected:
                    _Compare comp;
                    value_compare(_Compare _c) : comp(_c) { }

                public:
                    bool operator()(const value_type &_x, const value_type &_y) const
                    {
                        return comp(_x.first, _y.first);
                    }
            };

            value_compare value_comp() const
            {
                return (value_compare(_M_t.key_comp()));
            }

            iterator find(const key_type &_x)
            {
                return (_M_t.find(_x));
            }

            const_iterator find(const key_type &_x) const
            {
                return (_M_t.find(_x));
            }

            size_type count(const key_type &_x) const
            {
                return (_M_t.find(_x) == _M_t.end() ? 0 : 1);
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

            template<typename _K, typename _T, typename _Comp, typename _Al>
            friend bool operator==(const map<_K, _T, _Comp, _Al> &_x, const map<_K, _T, _Comp, _Al> &_y);

            template<typename _K, typename _T, typename _Comp, typename _Al>
            friend bool operator<(const map<_K, _T, _Comp, _Al> &_x, const map<_K, _T, _Comp, _Al> &_y);
    };

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator==(const map<_Key, _Tp, _Compare, _Alloc> &_x,
                    const map<_Key, _Tp, _Compare, _Alloc> &_y)
    {
        return (_x._M_t == _y._M_t);
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator<(const map<_Key, _Tp, _Compare, _Alloc> &_x,
                    const map<_Key, _Tp, _Compare, _Alloc> &_y)
    {
        return (_x._M_t < _y._M_t);
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator!=(const map<_Key, _Tp, _Compare, _Alloc> &_x,
                    const map<_Key, _Tp, _Compare, _Alloc> &_y)
    {
        return (!(_x == _y));
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator>(const map<_Key, _Tp, _Compare, _Alloc> &_x,
                    const map<_Key, _Tp, _Compare, _Alloc> &_y)
    {
        return (_y < _x);
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator<=(const map<_Key, _Tp, _Compare, _Alloc> &_x,
                    const map<_Key, _Tp, _Compare, _Alloc> &_y)
    {
        return (!(_y < _x));
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    bool operator>=(const map<_Key, _Tp, _Compare, _Alloc> &_x,
                    const map<_Key, _Tp, _Compare, _Alloc> &_y)
    {
        return (!(_x < _y));
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    void swap(map<_Key, _Tp, _Compare, _Alloc> &_x,
                map<_Key, _Tp, _Compare, _Alloc> &_y)
    {
        _x.swap(_y);
    }
}

#endif