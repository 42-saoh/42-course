#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "utils.hpp"
# include "iterator.hpp"
# include <memory>
# include <algorithm>

namespace ft
{
    template <class _Tp, class _Alloc>
    struct Vector_base
    {
        typedef _Tp value_type;
        typedef value_type* pointer;
        typedef typename _Alloc::template rebind<_Tp>::other _Tp_alloc_type;

        struct _Vector_base : public _Tp_alloc_type
        {
            typename _Tp_alloc_type::pointer _M_start;
            typename _Tp_alloc_type::pointer _M_finish;
            typename _Tp_alloc_type::pointer _M_end_of_storage;
            _Vector_base() : _Tp_alloc_type(), _M_start(0), _M_finish(0), _M_end_of_storage(0) {}
            _Vector_base(_Tp_alloc_type const &_a) : _Tp_alloc_type(_a), _M_start(0), _M_finish(0), _M_end_of_storage(0) {}
        };

        typedef _Alloc allocator_type;
        typedef size_t size_type;
        _Vector_base _M_base;

        _Tp_alloc_type &_M_get_Tp_allocator()
        {
            return (*static_cast<_Tp_alloc_type *>(&this->_M_base));
        }

        const _Tp_alloc_type &_M_get_Tp_allocator() const
        {
            return (*static_cast<const _Tp_alloc_type *>(&this->_M_base));
        }

        allocator_type get_allocator() const
        {
            return (allocator_type(_M_get_Tp_allocator()));
        }

        typename _Tp_alloc_type::pointer _M_allocate(size_type _n)
        {
            return (_n != 0 ? _M_base.allocate(_n) : 0);
        }

        void _M_deallocate(typename _Tp_alloc_type::pointer _p, size_t _n)
        {
            if (_p)
                _M_base.deallocate(_p, _n);
        }

        Vector_base() : _M_base() {}
        Vector_base(const allocator_type &_a) : _M_base(_a) {}
        Vector_base(size_type _n) : _M_base()
        {
            _M_base._M_start = _M_allocate(_n);
            _M_base._M_finish = _M_base._M_start;
            _M_base._M_end_of_storage = _M_base._M_start + _n;
        }
        Vector_base(size_type _n, const allocator_type &_a) : _M_base(_a)
        {
            _M_base._M_start = _M_allocate(_n);
            _M_base._M_finish = _M_base._M_start;
            _M_base._M_end_of_storage = _M_base._M_start + _n;
        }
        ~Vector_base()
        {
            _M_deallocate(_M_base._M_start, _M_base._M_end_of_storage - _M_base._M_start);
        }
    };

    template <class _Tp, class _Alloc = std::allocator<_Tp> >
    class vector : protected Vector_base<_Tp, _Alloc>
    {
        private:
            typedef Vector_base<_Tp, _Alloc> _Base;
            typedef typename _Base::_Tp_alloc_type _Tp_alloc_type;

        protected:
            using _Base::_M_allocate;
            using _Base::_M_deallocate;
            using _Base::_M_base;
            using _Base::_M_get_Tp_allocator;

        public:
            typedef _Tp value_type;
            typedef typename _Tp_alloc_type::reference reference;
            typedef typename _Tp_alloc_type::const_reference const_reference;
            typedef typename _Tp_alloc_type::pointer pointer;
            typedef typename _Tp_alloc_type::const_pointer const_pointer;
            typedef ft::vector_iterator<pointer> iterator;
            typedef ft::vector_iterator<const_pointer> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef _Alloc allocator_type;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;
            using _Base::get_allocator;

            explicit vector(const allocator_type &_a = allocator_type()) : _Base(_a) {}
            explicit vector(size_type _n, const value_type &_val = value_type(), const allocator_type &_a = allocator_type())
                : _Base(_n, _a)
            {
                _M_fill_initialize(_n, _val);
            }

            template <typename _InputIterator>
            vector(_InputIterator _first, _InputIterator _last, const allocator_type &_a = allocator_type())
                : _Base(_a)
            {
                typedef typename ft::is_integral<_InputIterator>::type _Integral;
                _M_range_initialize(_first, _last, _Integral());
            }

            vector(const vector &_x) : _Base(_x.size(), _x._M_get_Tp_allocator())
            {
                this->_M_base._M_finish = uninitialized_copy_alloc(_x.begin(), _x.end(), this->_M_base._M_start, _M_get_Tp_allocator());
            }

            ~vector()
            {
                if (this->_M_base._M_start != nullptr)
                    ft::_Destroy_alloc(this->_M_base._M_start, this->_M_base._M_finish, _M_get_Tp_allocator());
            }

            vector &operator=(const vector &_x)
            {
                if (&_x != this)
                {
                    const size_type _xlen = _x.size();
                    if (_xlen > capacity())
                    {
                        pointer tmp = _M_allocate_and_copy(_xlen, _x.begin(), _x.end());
                        ft::_Destroy_alloc(this->_M_base._M_start, this->_M_base._M_finish, _M_get_Tp_allocator());
                        _M_deallocate(this->_M_base._M_start, this->_M_base._M_end_of_storage - this->_M_base._M_start);
                        this->_M_base._M_start = tmp;
                        this->_M_base._M_end_of_storage = this->_M_base._M_start + _xlen;
                    }
                    else if (size() >= _xlen)
                    {
                        ft::_Destroy_alloc(std::copy(_x.begin(), _x.end(), begin()), end(), _M_get_Tp_allocator());
                    }
                    else
                    {
                        std::copy(_x._M_base._M_start, _x._M_base._M_start + size(), this->_M_base._M_start);
                        ft::uninitialized_copy_alloc(_x._M_base._M_start + size(), _x._M_base._M_finish, this->_M_base._M_finish, _M_get_Tp_allocator());
                    }
                    this->_M_base._M_finish = this->_M_base._M_start + _xlen;
                }
                return (*this);
            }

            void assign(size_type _n, const value_type &_val)
            {
                _M_fill_assign(_n, _val);
            }

            template <typename _InputIterator>
            void assign(_InputIterator _first, _InputIterator _last)
            {
                typedef typename ft::is_integral<_InputIterator>::type _Integral;
                _M_range_assign(_first, _last, _Integral());
            }

            iterator begin()
            {
                return (iterator(this->_M_base._M_start));
            }

            const_iterator begin() const
            {
                return (const_iterator(this->_M_base._M_start));
            }

            iterator end()
            {
                return (iterator(this->_M_base._M_finish));
            }

            const_iterator end() const
            {
                return (const_iterator(this->_M_base._M_finish));
            }

            reverse_iterator rbegin()
            {
                return (reverse_iterator(end()));
            }
    
            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(end()));
            }
    
            reverse_iterator rend()
            {
                return (reverse_iterator(begin()));
            }
    
            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(begin()));
            }

            size_type size() const
            {
                return (size_type(this->_M_base._M_finish - this->_M_base._M_start));
            }
            
            size_type max_size() const
            {
                return (_M_get_Tp_allocator().max_size());
            }

            void resize(size_type new_size, value_type _x = value_type())
            {
                if (new_size > size())
                    _M_fill_insert(end(), new_size - size(), _x);
                else if (new_size < size())
                    _M_erase_at_end(this->_M_base._M_start + new_size);
            }

            size_type capacity() const
            {
                return (size_type(this->_M_base._M_end_of_storage - this->_M_base._M_start));
            }

            bool empty() const
            {
                return (begin() == end());
            }

            void reserve(size_type _n)
            {
                if (_n > max_size())
                    throw std::length_error("vector::reserve");
                if (capacity() < _n)
                {
                    const size_type _old_size = size();
                    pointer tmp = _M_allocate_and_copy(_n, this->_M_base._M_start, this->_M_base._M_finish);
                    ft::_Destroy_alloc(this->_M_base._M_start, this->_M_base._M_finish, _M_get_Tp_allocator());
                    _M_deallocate(this->_M_base._M_start, this->_M_base._M_end_of_storage - this->_M_base._M_start);
                    this->_M_base._M_start = tmp;
                    this->_M_base._M_finish = tmp + _old_size;
                    this->_M_base._M_end_of_storage = this->_M_base._M_start + _n;
                }
            }

            reference operator[](size_type _n)
            {
                return (*(this->_M_base._M_start + _n));
            }

            const_reference operator[](size_type _n) const
            {
                return (*(this->_M_base._M_start + _n));
            }

            reference at(size_type _n)
            {
                _M_range_check(_n);
                return ((*this)[_n]); 
            }

            const_reference at(size_type _n) const
            {
                _M_range_check(_n);
                return ((*this)[_n]);
            }

            reference front()
            {
                return (*begin());
            }

            const_reference front() const
            {
                return (*begin());
            }

            reference back()
            {
                return (*(end() - 1));
            }
        
            const_reference back() const
            {
                return (*(end() - 1));
            }

            void push_back(const value_type &_x)
            {
                if (this->_M_base._M_finish != this->_M_base._M_end_of_storage)
                {
                    this->_M_base.construct(this->_M_base._M_finish, _x);
                    ++this->_M_base._M_finish;
                }
                else
                    _M_single_insert(end(), _x);
            }

            void pop_back()
            {
                --this->_M_base._M_finish;
                this->_M_base.destroy(this->_M_base._M_finish);
            }

            iterator insert(iterator _pos, const value_type &_x)
            {
                const size_type _n = _pos - begin();
                if (this->_M_base._M_finish != this->_M_base._M_end_of_storage && _pos == end())
                {
                    this->_M_base.construct(this->_M_base._M_finish, _x);
                    ++this->_M_base._M_finish;
                }
                else
                    _M_single_insert(_pos, _x);
                return (iterator(this->_M_base._M_start + _n));
            }

            void insert(iterator _pos, size_type _n, const value_type &_x)
            {
                _M_fill_insert(_pos, _n, _x);
            }

            template <typename _InputIterator>
            void insert(iterator _pos, _InputIterator _first, _InputIterator _last)
            {
                typedef typename ft::is_integral<_InputIterator>::type _Integral;
                _M_range_insert(_pos, _first, _last, _Integral());
            }

            iterator erase(iterator _pos)
            {
                if (_pos + 1 != end())
                    std::copy(_pos + 1, end(), _pos);
                --this->_M_base._M_finish;
                this->_M_base.destroy(this->_M_base._M_finish);
                return (_pos);
            }

            iterator erase(iterator _first, iterator _last)
            {
                if (_first != _last)
                {
                  if (_last != end())
                    std::copy(_last, end(), _first);
                  _M_erase_at_end(_first.base() + (end() - _last));
                }
                return (_first);
            }

            void swap(vector &_x)
            {
                std::swap(this->_M_base._M_start, _x._M_base._M_start);
                std::swap(this->_M_base._M_finish, _x._M_base._M_finish);
                std::swap(this->_M_base._M_end_of_storage, _x._M_base._M_end_of_storage);
            }

            void clear()
            {
                _M_erase_at_end(this->_M_base._M_start);
            }

        protected:
            void _M_range_check(size_type _n) const
            {
                if (_n >= this->size())
                    throw std::out_of_range("vector::_M_range_check");
            }

            template <typename _ForwardIterator>
            pointer _M_allocate_and_copy(size_type _n, _ForwardIterator _first, _ForwardIterator _last)
            {
                pointer _result = this->_M_allocate(_n);
                try
                {
                    uninitialized_copy_alloc(_first, _last, _result, _M_get_Tp_allocator());
                    return (_result);
                }
                catch(...)
                {
                    _M_deallocate(_result, _n);
                    throw std::runtime_error("_M_allocate_and_copy");
                }
            }

            template <typename _Integer>
            void _M_range_initialize(_Integer _n, _Integer _val, ft::true_type)
            {
                this->_M_base._M_start = _M_allocate(static_cast<size_type>(_n));
                this->_M_base._M_end_of_storage = this->_M_base._M_start + static_cast<size_type>(_n);
                _M_fill_initialize(static_cast<size_type>(_n), _val);
            }

            template <typename _InputIterator>
            void _M_range_initialize(_InputIterator _first, _InputIterator _last, ft::false_type)
            {
                const size_type _n = ft::distance(_first, _last);

                this->_M_base._M_start = this->_M_allocate(_n);
                this->_M_base._M_end_of_storage = this->_M_base._M_start + _n;
                this->_M_base._M_finish = ft::uninitialized_copy_alloc(_first, _last, this->_M_base._M_start, _M_get_Tp_allocator());
            }

            void _M_fill_initialize(size_type _n, const value_type& _val)
            {
                ft::uninitialized_fill_alloc(this->_M_base._M_start, _n, _val, _M_get_Tp_allocator());
                this->_M_base._M_finish = this->_M_base._M_end_of_storage;
            }

            template <typename _Integer>
            void _M_range_assign(_Integer _n, _Integer _val, ft::true_type)
            {
                _M_fill_assign(_n, _val);
            }

            template <typename _InputIterator>
            void _M_range_assign(_InputIterator _first, _InputIterator _last, ft::false_type)
            {
                const size_type _len = ft::distance(_first, _last);
                if (_len > capacity())
                {
                    pointer _tmp(_M_allocate_and_copy(_len, _first, _last));
                    ft::_Destroy_alloc(this->_M_base._M_start, this->_M_base._M_finish, _M_get_Tp_allocator());
                    _M_deallocate(this->_M_base._M_start, this->_M_base._M_end_of_storage - this->_M_base._M_start);
                    this->_M_base._M_start = _tmp;
                    this->_M_base._M_finish = this->_M_base._M_start + _len;
                    this->_M_base._M_end_of_storage = this->_M_base._M_finish;
                }
                else if (size() >= _len)
                    _M_erase_at_end(std::copy(_first, _last, this->_M_base._M_start));
                else
                {
                    _InputIterator _mid = _first;
                    ft::advance(_mid, size());
                    std::copy(_first, _mid, this->_M_base._M_start);
                    this->_M_base._M_finish = ft::uninitialized_copy_alloc(_mid, _last, this->_M_base._M_finish, _M_get_Tp_allocator());
                }
            }

            void _M_fill_assign(size_type _n, const value_type &_val)
            {
                if (_n > capacity())
                {
                    pointer _tmp(this->_M_allocate(_n));
                    try
                    {
                        ft::uninitialized_fill_alloc(_tmp, _n, _val, _M_get_Tp_allocator());
                    }
                    catch(...)
                    {
                        _M_deallocate(_tmp, _n);
                        throw std::runtime_error("_M_fill_assign");
                    }
                    ft::_Destroy_alloc(this->_M_base._M_start, this->_M_base._M_finish, _M_get_Tp_allocator());
                    _M_deallocate(this->_M_base._M_start, this->_M_base._M_end_of_storage - this->_M_base._M_start);
                    this->_M_base._M_start = _tmp;
                    this->_M_base._M_finish = this->_M_base._M_start + _n;
                    this->_M_base._M_end_of_storage = this->_M_base._M_finish;
                }
                else if (_n > size())
                {
                    std::fill(begin(), end(), _val);
                    ft::uninitialized_fill_alloc(this->_M_base._M_finish, _n - size(), _val, _M_get_Tp_allocator());
                    this->_M_base._M_finish += _n - size();
                }
                else
                    _M_erase_at_end(std::fill_n(this->_M_base._M_start, _n, _val));
            }

            template <typename _Integer>
            void _M_range_insert(iterator _pos, _Integer _n, _Integer _val, ft::true_type)
            {
                _M_fill_insert(_pos, _n, _val);
            }

            template <typename _InputIterator>
            void _M_range_insert(iterator _pos, _InputIterator _first, _InputIterator _last, ft::false_type)
            {
                if (_first != _last)
                {
                    const size_type _n = ft::distance(_first, _last);
                    if (size_type(this->_M_base._M_end_of_storage - this->_M_base._M_finish) >= _n)
                    {
                        const size_type _elems_after = end() - _pos;
                        pointer _old_finish(this->_M_base._M_finish);
                        if (_elems_after > _n)
                        {
                            ft::uninitialized_copy_alloc(this->_M_base._M_finish - _n, this->_M_base._M_finish, this->_M_base._M_finish, _M_get_Tp_allocator());
                            this->_M_base._M_finish += _n;
                            std::copy_backward(_pos.base(), _old_finish - _n, _old_finish);
                            std::copy(_first, _last, _pos);
                        }
                        else
                        {
                            _InputIterator _mid = _first;
                            ft::advance(_mid, _elems_after);
                            ft::uninitialized_copy_alloc(_mid, _last, this->_M_base._M_finish, _M_get_Tp_allocator());
                            this->_M_base._M_finish += _n - _elems_after;
                            ft::uninitialized_copy_alloc(_pos.base(), _old_finish, this->_M_base._M_finish, _M_get_Tp_allocator());
                            this->_M_base._M_finish += _elems_after;
                            std::copy(_first, _mid, _pos);
                        }
                    }
                    else
                    {
                        const size_type _len = _M_check_len(_n, "vector::_M_range_insert");
                        pointer _new_start(this->_M_allocate(_len));
                        pointer _new_finish(_new_start);
                        try
                        {
                            _new_finish = ft::uninitialized_copy_alloc(this->_M_base._M_start, _pos.base(), _new_start, _M_get_Tp_allocator());
                            _new_finish = ft::uninitialized_copy_alloc(_first, _last, _new_finish, _M_get_Tp_allocator());
                            _new_finish = ft::uninitialized_copy_alloc(_pos.base(), this->_M_base._M_finish, _new_finish, _M_get_Tp_allocator());
                        }
                        catch(...)
                        {
                            ft::_Destroy_alloc(_new_start, _new_finish, _M_get_Tp_allocator());
                            _M_deallocate(_new_start, _len);
                            throw std::runtime_error("_M_range_insert");
                        }
                        ft::_Destroy_alloc(this->_M_base._M_start, this->_M_base._M_finish, _M_get_Tp_allocator());
                        _M_deallocate(this->_M_base._M_start, this->_M_base._M_end_of_storage - this->_M_base._M_start);
                        this->_M_base._M_start = _new_start;
                        this->_M_base._M_finish = _new_finish;
                        this->_M_base._M_end_of_storage = _new_start + _len;
                    }
                }
            }

            void _M_fill_insert(iterator _pos, size_type _n, const value_type &_x)
            {
                if (_n != 0)
                {
                    if (size_type(this->_M_base._M_end_of_storage - this->_M_base._M_finish) >= _n)
                    {
                        value_type _x_copy = _x;
                        const size_type _elems_after = end() - _pos;
                        pointer _old_finish(this->_M_base._M_finish);
                        if (_elems_after > _n)
                        {
                            ft::uninitialized_copy_alloc(this->_M_base._M_finish - _n, this->_M_base._M_finish, this->_M_base._M_finish, _M_get_Tp_allocator());
                            this->_M_base._M_finish += _n;
                            std::copy_backward(_pos.base(), _old_finish - _n, _old_finish);
                            std::fill(_pos.base(), _pos.base() + _n, _x_copy);
                        }
                        else
                        {
                            ft::uninitialized_fill_alloc(this->_M_base._M_finish, _n - _elems_after, _x_copy, _M_get_Tp_allocator());
                            this->_M_base._M_finish += _n - _elems_after;
                            ft::uninitialized_copy_alloc(_pos.base(), _old_finish, this->_M_base._M_finish, _M_get_Tp_allocator());
                            this->_M_base._M_finish += _elems_after;
                            std::fill(_pos.base(), _old_finish, _x_copy);
                        }
                    }
                    else
                    {
                        const size_type _len = _M_check_len(_n, "vector::_M_fill_insert");
                        const size_type _elems_before = _pos - begin();
                        pointer _new_start(this->_M_allocate(_len));
                        pointer _new_finish(_new_start);
                        try
                        {
                            ft::uninitialized_fill_alloc(_new_start + _elems_before, _n, _x, _M_get_Tp_allocator());
                            _new_finish = 0;
                            _new_finish = ft::uninitialized_copy_alloc(this->_M_base._M_start, _pos.base(), _new_start, _M_get_Tp_allocator());
                            _new_finish += _n;
                            _new_finish = ft::uninitialized_copy_alloc(_pos.base(), this->_M_base._M_finish, _new_finish, _M_get_Tp_allocator());
                        }
                        catch(...)
                        {
                            if (!_new_finish)
                                ft::_Destroy_alloc(_new_start + _elems_before, _new_start + _elems_before + _n, _M_get_Tp_allocator());
                            else
                                ft::_Destroy_alloc(_new_start, _new_finish, _M_get_Tp_allocator());
                            _M_deallocate(_new_start, _len);
                            throw std::runtime_error("_M_fill_insert");
                        }
                        ft::_Destroy_alloc(this->_M_base._M_start, this->_M_base._M_finish, _M_get_Tp_allocator());
                        _M_deallocate(this->_M_base._M_start, this->_M_base._M_end_of_storage - this->_M_base._M_start);
                        this->_M_base._M_start = _new_start;
                        this->_M_base._M_finish = _new_finish;
                        this->_M_base._M_end_of_storage = _new_start + _len;
                    }
                }
            }
    
            void _M_single_insert(iterator _pos, const value_type &_x)
            {
                if (this->_M_base._M_finish != this->_M_base._M_end_of_storage)
                {
                    this->_M_base.construct(this->_M_base._M_finish, *(this->_M_base._M_finish - 1));
                    ++this->_M_base._M_finish;
                    std::copy_backward(_pos.base(), this->_M_base._M_finish - 2, this->_M_base._M_finish - 1);
                    *_pos = _x;
                }
                else
                {
                    const size_type _len = _M_check_len(size_type(1), "vector::_M_single_insert");
                    const size_type _elems_before = _pos - begin();
                    pointer _new_start(this->_M_allocate(_len));
                    pointer _new_finish(_new_start);
                    try
                    {
                        this->_M_base.construct(_new_start + _elems_before, _x);
                        _new_finish = 0;
                        _new_finish = ft::uninitialized_copy_alloc(this->_M_base._M_start, _pos.base(), _new_start, _M_get_Tp_allocator());
                        ++_new_finish;
                        _new_finish = ft::uninitialized_copy_alloc(_pos.base(), this->_M_base._M_finish, _new_finish, _M_get_Tp_allocator());
                    }
                    catch(...)
                    {
                        if (!_new_finish)
                            this->_M_base.destroy(_new_start + _elems_before);
                        else
                            ft::_Destroy_alloc(_new_start, _new_finish, _M_get_Tp_allocator());
                        _M_deallocate(_new_start, _len);
                        throw std::runtime_error("_M_single_insert");
                    }
                    ft::_Destroy_alloc(this->_M_base._M_start, this->_M_base._M_finish, _M_get_Tp_allocator());
                    _M_deallocate(this->_M_base._M_start, this->_M_base._M_end_of_storage - this->_M_base._M_start);
                    this->_M_base._M_start = _new_start;
                    this->_M_base._M_finish = _new_finish;
                    this->_M_base._M_end_of_storage = _new_start + _len;
                }
            }

            size_type _M_check_len(size_type _n, const char *_s) const
            {
                if (max_size() - size() < _n)
                    throw std::range_error(_s);
                const size_type _len = size() + std::max(size(), _n);
                return ((_len < size() || _len > max_size()) ? max_size() : _len);
            }

            void _M_erase_at_end(pointer _pos)
            {
                ft::_Destroy_alloc(_pos, this->_M_base._M_finish, _M_get_Tp_allocator());
                this->_M_base._M_finish = _pos;
            }
    };

    template <typename _Tp, typename _Alloc>
    bool operator==(const vector<_Tp, _Alloc> &_x, const vector<_Tp, _Alloc> &_y)
    {
        return (_x.size() == _y.size() && ft::equal(_x.begin(), _x.end(), _y.begin()));
    }

    template <typename _Tp, typename _Alloc>
    bool operator<(const vector<_Tp, _Alloc> &_x, const vector<_Tp, _Alloc> &_y)
    {
        return (ft::lexicographical_compare(_x.begin(), _x.end(), _y.begin(), _y.end()));
    }

    template <typename _Tp, typename _Alloc>
    bool operator!=(const vector<_Tp, _Alloc> &_x, const vector<_Tp, _Alloc> &_y)
    {
        return (!(_x == _y));
    }
    
    template <typename _Tp, typename _Alloc>
    bool operator>(const vector<_Tp, _Alloc> &_x, const vector<_Tp, _Alloc> &_y)
    {
        return (_y < _x);
    }
    
    template <typename _Tp, typename _Alloc>
    bool operator<=(const vector<_Tp, _Alloc> &_x, const vector<_Tp, _Alloc> &_y)
    {
        return (!(_y < _x));
    }
    
    template <typename _Tp, typename _Alloc>
    bool operator>=(const vector<_Tp, _Alloc> &_x, const vector<_Tp, _Alloc> &_y)
    {
        return (!(_x < _y));
    }

    template<typename _Tp, typename _Alloc>
    void swap(vector<_Tp, _Alloc> &_x, vector<_Tp, _Alloc> &_y)
    {
        _x.swap(_y);
    }
}

#endif