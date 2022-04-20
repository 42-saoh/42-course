#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "utils.hpp"
# include "iterator.hpp"

namespace ft
{
    template <class _Tp, class _Alloc>
    struct Vector_base
    {
        typedef _Tp value_type;
        typedef value_type *pointer;
        typedef typename _Alloc::template rebind<_Tp>::other _Tp_alloc_type;

        struct _Vector_impl : public _Tp_alloc_type
        {
            typename _Tp_alloc_type::pointer _M_start;
            typename _Tp_alloc_type::pointer _M_finish;
            typename _Tp_alloc_type::pointer _M_end_of_storage;
            _Vector_impl() : _Tp_alloc_type(), _M_start(0), _M_finish(0), _M_end_of_storage(0) {}
            _Vector_impl(_Tp_alloc_type const &_a) : _Tp_alloc_type(_a), _M_start(0), _M_finish(0), _M_end_of_storage(0) {}
        };

        typedef _Alloc allocator_type;
        typedef size_t size_type;
        _Vector_impl _M_impl;

        _Tp_alloc_type &_M_get_Tp_allocator()
        {
        return (*static_cast<_Tp_alloc_type *>(&this->_M_impl));
        }

        const _Tp_alloc_type &_M_get_Tp_allocator() const
        {
        return (*static_cast<const _Tp_alloc_type *>(&this->_M_impl));
        }

        allocator_type get_allocator() const
        {
        return (allocator_type(_M_get_Tp_allocator()));
        }

        typename _Tp_alloc_type::pointer _M_allocate(size_type _n)
        {
            return (_n != 0 ? _M_impl.allocate(_n) : 0);
        }

        void _M_deallocate(typename _Tp_alloc_type::pointer _p, size_t _n)
        {
            if (_p)
                _M_impl.deallocate(_p, _n);
        }

        Vector_base() : _M_impl() {}
        Vector_base(const allocator_type &_a) : _M_impl(_a) {}
        Vector_base(size_type _n) : _M_impl()
        {
            _M_impl._M_start = _M_allocate(_n);
            _M_impl._M_finish = _M_impl._M_start;
            _M_impl._M_end_of_storage = _M_impl._M_start + _n;
        }
        Vector_base(size_type _n, const allocator_type &_a) : _M_impl(_a)
        {
            _M_impl._M_start = _M_allocate(_n);
            _M_impl._M_finish = _M_impl._M_start;
            _M_impl._M_end_of_storage = _M_impl._M_start + _n;
        }
        ~Vector_base()
        {
            _M_deallocate(_M_impl._M_start, _M_impl._M_end_of_storage - _M_impl._M_start);
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
            using _Base::_M_impl;
            using _Base::_M_get_Tp_allocator;
            template<typename _ForwardIterator>
            pointer _M_allocate_and_copy(size_type _n, _ForwardIterator _first, _ForwardIterator _last)
            {
                pointer _result = this->_M_allocate(_n);
                try
                {
                    std::__uninitalized_copy_a(_first, _last, _result, _M_get_Tp_allocator());
                    return (_result);
                }
                catch(...)
                {
                    _M_deallocate(_result, _n);
                    __throw_exception_again;
                }
            }
            template<typename _Integer>
            void _M_initial_dispatch(_Integer _n, _Integer _value, __true_type)
            {
                this->_M_impl._M_start = _M_allocate(static_cast<size_type>(_n));
                this->_M_impl._M_end_of_storage = this->_M_impl._M_start + static_case<size_type>(_n);
                _M_fill_initailize(static_cast<size_type>(_n), _value);
            }

            
        public:
            typedef _Tp value_type;
            typedef typename _Tp_alloc_type::reference reference;
            typedef typename _Tp_alloc_type::const_reference const_reference;
            typedef typename _Tp_alloc_type::pointer pointer;
            typedef typename _Tp_alloc_type::const_pointer const_pointer;
            typedef ft::vector_iterator<pointer> iterator;
            typedef ft::vector_iterator<const_pointer> const_iterator;
            typedef ft::reverse_iterator<iterator> iterator;
            typedef ft::reverse_iterator<const_iterator> const_iterator;
            typedef _Alloc allocator_type;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;

            vector() : _Base() {}
            explicit vector(const allocator_type &_a) : _Base(_a) {}
            explicit vector(size_type _n, const value_type &_value = value_type(), const allocator_type &_a = allocator_type())
                : _Base(_n, _a)
            {
                _M_fill_initialize(_n, _value);
            }
            vector(const vector &_x) : _Base(_x.size(), _x._M_get_Tp_allocator())
            {
                this->_M_impl._M_finish = std::__uninitialize_copy_a(_x.begin(), _x.end(), this->_M_impl._M_start, _M_get_Tp_allocator());
            }

    };
}

#endif