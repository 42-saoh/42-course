#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>
# include <stdexcept>
# include "utils.hpp"

namespace ft
{

    template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t, typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator
    {
        typedef _Category iterator_category;
        typedef _Tp value_type;
        typedef _Distance difference_type;
        typedef _Pointer pointer;
        typedef _Reference reference;
    };

    template <class _Iterator>
    struct iterator_traits
    {
        typedef typename _Iterator::difference_type difference_type;
        typedef typename _Iterator::value_type value_type;
        typedef typename _Iterator::pointer pointer;
        typedef typename _Iterator::reference reference;
        typedef typename _Iterator::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename _Iterator>
    typename iterator_traits<_Iterator>::iterator_category _iterator_category(const _Iterator &)
    {
        return (typename iterator_traits<_Iterator>::iterator_category());
    }

    template <typename _InputIterator>
    typename iterator_traits<_InputIterator>::difference_type
    _distance(_InputIterator _first, _InputIterator _last, std::input_iterator_tag)
    {
        typename iterator_traits<_InputIterator>::difference_type _n = 0;
        while (_first != _last)
        {
            ++_first;
            ++_n;
        }
        return (_n);
    }

    template <typename _RandomAccessIterator>
    typename iterator_traits<_RandomAccessIterator>::difference_type
    _distance(_RandomAccessIterator _first, _RandomAccessIterator _last, std::random_access_iterator_tag)
    {
        return (_last - _first);
    }

    template <typename _InputIterator>
    typename iterator_traits<_InputIterator>::difference_type distance(_InputIterator __first, _InputIterator __last)
    {
        return (_distance(__first, __last, _iterator_category(__first)));
    }

    template <typename _InputIterator, typename _Distance>
    void _advance(_InputIterator &_i, _Distance _n, std::input_iterator_tag)
    {
        while (_n--)
            ++_i;
    }

    template <typename _BidirectionalIterator, typename _Distance>
    void _advance(_BidirectionalIterator &_i, _Distance _n, std::bidirectional_iterator_tag)
    {
        if (_n > 0)
            while (_n--)
                ++_i;
        else
            while (_n++)
                --_i;
    }

    template <typename _RandomAccessIterator, typename _Distance>
    void _advance(_RandomAccessIterator &_i, _Distance _n, std::random_access_iterator_tag)
    {
        _i += _n;
    }

    template <typename _InputIterator, typename _Distance>
    void advance(_InputIterator &_i, _Distance _n)
    {
        typename iterator_traits<_InputIterator>::difference_type _d = _n;
        _advance(_i, _d, _iterator_category(_i));
    }

    template <typename _Iterator>
    class reverse_iterator
    {
        protected:
            _Iterator _iter;

        public:
            typedef _Iterator iterator_type;
            typedef typename iterator_traits<_Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<_Iterator>::value_type value_type;
            typedef typename iterator_traits<_Iterator>::difference_type difference_type;
            typedef typename iterator_traits<_Iterator>::pointer pointer;
            typedef typename iterator_traits<_Iterator>::reference reference;

            reverse_iterator() {};
            explicit reverse_iterator (iterator_type it) : _iter(it) {};

            template <class _Iter>
            reverse_iterator (const reverse_iterator<_Iter> &rev_it) : _iter(rev_it.base()) {};

            iterator_type base() const
            {
                return (_iter);
            }

            reference operator*() const
            {
                iterator_type tmp = _iter;
                return (*--tmp);
            }

            reverse_iterator operator+(difference_type n) const
            {
                return (reverse_iterator(_iter - n));
            }

            reverse_iterator &operator++()
            {
                --_iter;
                return (*this);
            }

            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp = *this;
                --_iter;
                return (tmp);
            }

            reverse_iterator &operator+=(difference_type n)
            {
                _iter -= n;
                return (*this);
            }

            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(_iter + n));
            }

            reverse_iterator &operator--()
            {
                ++_iter;
                return (*this);
            }

            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                ++_iter;
                return (tmp);
            }

            reverse_iterator &operator-=(difference_type n)
            {
                _iter += n;
                return (*this);
            }

            pointer operator->() const
            {
                return (&(operator*()));
            }

            reference operator[] (difference_type n) const
            {
                return (*(*this + n));
            }
    };
    
    template <class _Iterator1, class _Iterator2>
    bool operator==(const reverse_iterator<_Iterator1> &lhs, const reverse_iterator<_Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class _Iterator1, class _Iterator2>
    bool operator!=(const reverse_iterator<_Iterator1> &lhs, const reverse_iterator<_Iterator2> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <class _Iterator1, class _Iterator2>
    bool operator<(const reverse_iterator<_Iterator1> &lhs, const reverse_iterator<_Iterator2> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class _Iterator1, class _Iterator2>
    bool operator<=(const reverse_iterator<_Iterator1> &lhs, const reverse_iterator<_Iterator2> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <class _Iterator1, class _Iterator2>
    bool operator>(const reverse_iterator<_Iterator1> &lhs, const reverse_iterator<_Iterator2> &rhs)
    {
        return (rhs < lhs);
    }

    template <class _Iterator1, class _Iterator2>
    bool operator>=(const reverse_iterator<_Iterator1> &lhs, const reverse_iterator<_Iterator2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <class _Iterator>
    reverse_iterator<_Iterator> operator+ (typename reverse_iterator<_Iterator>::difference_type n, \
        const reverse_iterator<_Iterator> &rev_it)
    {
        return (rev_it + n);
    }

    template <class _Iterator1, class _Iterator2>
    typename reverse_iterator<_Iterator1>::difference_type operator- (const reverse_iterator<_Iterator1> &lhs, \
        const reverse_iterator<_Iterator2> &rhs)
    {
        return (rhs.base() - lhs.base());
    }

    template <typename _Container>
    class back_insert_iterator : public iterator<std::output_iterator_tag, void, void, void, void>
    {
        protected:
            _Container *container;

        public:
            typedef _Container container_type;
            explicit back_insert_iterator(_Container &x) : container(&x) {}
            back_insert_iterator &operator=(const typename _Container::value_type &value)
            {
                container->push_back(value);
                return (*this);
            }

            back_insert_iterator &operator*()
            {
                return (*this);
            }

            back_insert_iterator &operator++()
            {
                return (*this);
            }

            back_insert_iterator operator++(int)
            {
                return (*this);
            }
    };

    template <typename _Container>
    back_insert_iterator<_Container> back_inserter(_Container &x)
    {
        return (back_insert_iterator<_Container>(x));
    }

    template <typename _Container>
    class front_insert_iterator : public iterator<std::output_iterator_tag, void, void, void, void>
    {
        protected:
            _Container *container;

        public:
            typedef _Container container_type;
            explicit front_insert_iterator(_Container &x) : container(&x) {}
            front_insert_iterator &operator=(const typename _Container::value_type &value)
            {
                container->push_front(value);
                return (*this);
            }

            front_insert_iterator &operator*()
            {
                return (*this);
            }

            front_insert_iterator &operator++()
            {
                return (*this);
            }

            front_insert_iterator operator++(int)
            {
                return (*this);
            }
    };

    template <typename _Container>
    front_insert_iterator<_Container> front_inserter(_Container &x)
    {
        return (front_insert_iterator<_Container>(x));
    }

    template <typename _Container>
    class insert_iterator : public iterator<std::output_iterator_tag, void, void, void, void>
    {
        protected:
            _Container *container;
            typename _Container::iterator _iter;

        public:
            typedef _Container container_type;
            insert_iterator(_Container &x, typename _Container::iterator _i)
                : container(&x), _iter(_i) {}

            insert_iterator &operator=(const typename _Container::value_type &value)
            {
                _iter = container->insert(_iter, value);
                ++_iter;
                return (*this);
            }

            insert_iterator &operator*()
            {
                return (*this);
            }
            
            insert_iterator &operator++()
            {
                return (*this);
            }

            insert_iterator &operator++(int)
            {
                return (*this);
            }
    };

    template <typename _Container, typename iterator>
    insert_iterator<_Container> inserter(_Container &x, iterator _iter)
    {
        return (insert_iterator<_Container>(x, typename _Container::iterator(_iter)));
    }

    template <typename _Iterator>
    class vector_iterator
    {
        private:
            _Iterator _iter;
        
        public:
            typedef _Iterator iterator_type;
            typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename iterator_traits<iterator_type>::value_type value_type;
            typedef typename iterator_traits<iterator_type>::difference_type difference_type;
            typedef typename iterator_traits<iterator_type>::pointer pointer;
            typedef typename iterator_traits<iterator_type>::reference reference;

            vector_iterator() : _iter(_Iterator()) {}
            explicit vector_iterator(const _Iterator &_i) : _iter(_i) {}
            template <typename _Iter>
            vector_iterator(const vector_iterator<_Iter> _i, typename ft::enable_if<ft::is_same<_Iter, iterator_type>::value> * = 0)
                : _iter(_i.base()) {}

            reference operator*() const
            {
                return (*_iter);
            }

            pointer operator->() const
            { 
                return (_iter);
            }

            vector_iterator &operator++()
            {
                ++_iter;
                return (*this);
            }

            vector_iterator operator++(int)
            {
                return (vector_iterator(_iter++));
            }

            vector_iterator &operator--()
            {
                --_iter;
                return (*this);
            }

            vector_iterator operator--(int)
            {
                return (vector_iterator(_iter--));
            }

            reference operator[](const difference_type &n) const
            {
                return (_iter[n]);
            }

            vector_iterator &operator+=(const difference_type &n)
            {
                _iter += n;
                return (*this);
            }

            vector_iterator operator+(const difference_type &n) const
            {
                return (vector_iterator(_iter + n));
            }

            vector_iterator &operator-=(const difference_type &n)
            {
                _iter -= n;
                return (*this);
            }

            vector_iterator operator-(const difference_type &n) const
            {
                return (vector_iterator(_iter - n));
            }

            const _Iterator &base() const
            {
                return (_iter);
            }
    };

    template <typename _IteratorL, typename _IteratorR>
    bool operator==(const vector_iterator<_IteratorL> &lhs, const vector_iterator<_IteratorR> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename _Iterator>
    bool operator==(const vector_iterator<_Iterator> &lhs, const vector_iterator<_Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename _IteratorL, typename _IteratorR>
    bool operator!=(const vector_iterator<_IteratorL> &lhs, const vector_iterator<_IteratorR> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <typename _Iterator>
    bool operator!=(const vector_iterator<_Iterator> &lhs, const vector_iterator<_Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <typename _IteratorL, typename _IteratorR>
    bool operator<(const vector_iterator<_IteratorL> &lhs, const vector_iterator<_IteratorR> &rhs)
    { 
        return (lhs.base() < rhs.base());
    }

    template <typename _Iterator>
    bool operator<(const vector_iterator<_Iterator> &lhs, const vector_iterator<_Iterator> &rhs)
    { 
        return (lhs.base() < rhs.base());
    }

    template <typename _IteratorL, typename _IteratorR>
    bool operator<=(const vector_iterator<_IteratorL> &lhs, const vector_iterator<_IteratorR> &rhs)
    { 
        return (lhs.base() <= rhs.base());
    }

    template <typename _Iterator>
    bool operator<=(const vector_iterator<_Iterator> &lhs, const vector_iterator<_Iterator> &rhs)
    { 
        return (lhs.base() <= rhs.base());
    }

    template <typename _IteratorL, typename _IteratorR>
    bool operator>(const vector_iterator<_IteratorL> &lhs, const vector_iterator<_IteratorR> &rhs)
    { 
        return (lhs.base() > rhs.base());
    }

    template <typename _Iterator>
    bool operator>(const vector_iterator<_Iterator> &lhs, const vector_iterator<_Iterator> &rhs)
    { 
        return (lhs.base() > rhs.base());
    }

    template <typename _IteratorL, typename _IteratorR>
    bool operator>=(const vector_iterator<_IteratorL> &lhs, const vector_iterator<_IteratorR> &rhs)
    { 
        return (lhs.base() >= rhs.base());
    }

    template <typename _Iterator>
    bool operator>=(const vector_iterator<_Iterator> &lhs, const vector_iterator<_Iterator> &rhs)
    { 
        return (lhs.base() >= rhs.base());
    }

    template <typename _IteratorL, typename _IteratorR>
    typename vector_iterator<_IteratorL>::difference_type operator-(const vector_iterator<_IteratorL> &lhs, const vector_iterator<_IteratorR> &rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template <typename _Iterator>
    typename vector_iterator<_Iterator>::difference_type operator-(const vector_iterator<_Iterator> &lhs, const vector_iterator<_Iterator> &rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template <typename _Iterator>
    vector_iterator<_Iterator> operator+(typename vector_iterator<_Iterator>::difference_type n, const vector_iterator<_Iterator> &i)
    {
        return (vector_iterator<_Iterator>(i.base() + n));
    }

    template <typename _ForwardIterator, typename _Allocator>
    void _Destroy_alloc(_ForwardIterator _first, _ForwardIterator _last, _Allocator &_alloc)
    {
        for (; _first != _last; ++_first)
            _alloc.destroy(&*_first);
    }

    template <class _InputIterator, class _ForwardIterator, class _Allocator>
    _ForwardIterator uninitialized_copy_alloc(_InputIterator _first, _InputIterator _last, \
                    _ForwardIterator _result, _Allocator &_alloc)
    {
        _ForwardIterator _cur = _result;
        try
        {
            for (; _first != _last; ++_cur, ++_first)
                _alloc.construct(&*_cur, typename ft::iterator_traits<_ForwardIterator>::value_type(*_first));
            return (_cur);
        }
        catch(...)
        {
            ft::_Destroy_alloc(_result, _cur, _alloc);
            throw std::runtime_error("uninitialized_copy_alloc");
        }
    }

    template <class _ForwardIterator, class T, class _Allocator>
    void uninitialized_fill_alloc(_ForwardIterator _first, size_t n, const T &x, _Allocator &_alloc)
    {
        _ForwardIterator _cur = _first;
        try
        {
            for (; n--; ++_cur)
                _alloc.construct(&*_cur, typename ft::iterator_traits<_ForwardIterator>::value_type(x));
        }
        catch(...)
        {
            ft::_Destroy_alloc(_first, _cur, _alloc);
            throw std::runtime_error("uninitialized_fill_alloc");
        }
    }
}

#endif