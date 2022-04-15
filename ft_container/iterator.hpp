#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <cstddef>

namespace ft
{

    struct input_iterator_tag {};
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

    template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t, typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator
    {
        typedef _Category iterator_category;
        typedef _Tp value_type;
        typedef _Distance difference_type;
        typedef _Pointer pointer;
        typedef _Reference reference;
    };

    template <class Iterator>
    class iterator_traits
    {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference	reference;
        typedef typename Iterator::iterator_category	iterator_category;
    };

    template <class T>
    class iterator_traits<T*>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T*>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template<typename _Iter>
    typename iterator_traits<_Iter>::iterator_category _iterator_category(const _Iter &)
    {
        return (typename iterator_traits<_Iter>::iterator_category());
    }

    template<typename _Iterator, bool _HasBase>
    struct _Iter_base
    {
        typedef _Iterator iterator_type;
        static iterator_type _S_base(_Iterator _it)
        {
            return (_it);
        }
    };

    template<typename _Iterator>
    struct _Iter_base<_Iterator, true>
    {
        typedef typename _Iterator::iterator_type iterator_type;
        static iterator_type _S_base(_Iterator _it)
        {
            return (_it.base());
        }
    };

    template<typename _InputIterator>
    typename iterator_traits<_InputIterator>::difference_type _distance(_InputIterator _first, _InputIterator _last, input_iterator_tag)
    {
        typename iterator_traits<_InputIterator>::difference_type _n = 0;
        while (_first != _last)
        {
            ++_first;
            ++_n;
        }
        return (_n);
    }

    template<typename _RandomAccessIterator>
    typename iterator_traits<_RandomAccessIterator>::difference_type _distance(_RandomAccessIterator _first, _RandomAccessIterator _last, random_access_iterator_tag)
    {
        return (_last - _first);
    }

    template<typename _InputIterator>
    typename iterator_traits<_InputIterator>::difference_type distance(_InputIterator __first, _InputIterator __last)
    {
        return (_distance(__first, __last, _iterator_category(__first)));
    }

    template<typename _InputIterator, typename _Distance>
    void _advance(_InputIterator& _i, _Distance _n, input_iterator_tag)
    {
      while (_n--)
        ++_i;
    }

    template<typename _BidirectionalIterator, typename _Distance>
    void _advance(_BidirectionalIterator& _i, _Distance _n, bidirectional_iterator_tag)
    {
        if (_n > 0)
            while (_n--)
                ++_i;
        else
            while (_n++)
                --_i;
    }

    template<typename _RandomAccessIterator, typename _Distance>
    void _advance(_RandomAccessIterator& _i, _Distance _n, random_access_iterator_tag)
    {
        _i += _n;
    }

    template<typename _InputIterator, typename _Distance>
    void advance(_InputIterator& _i, _Distance _n)
    {
      typename iterator_traits<_InputIterator>::difference_type _d = _n;
      _advance(_i, _d, _iterator_category(_i));
    }

    template <class Iterator>
    class reverse_iterator
    {
        private:
            Iterator _iter;

        public:
            typedef Iterator iterator_type;
            typedef typename Iterator::iterator_category iterator_category;
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;

            reverse_iterator() {};
            explicit reverse_iterator (iterator_type it) : _iter(it) {};

            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter> &rev_it) : _iter(rev_it.base()) {};

            iterator_type base() const
            {
                return (_iter);
            }

            reference operator*() const
            {
                return (static_cast<reference>(*(_iter - 1)));
            }

            reverse_iterator operator+(difference_type n) const
            {
                return (static_cast<reverse_iterator>(_iter - n));
            }

            reverse_iterator &operator++()
            {
                --_iter;
                return (*this);
            }

            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp(*this);
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
                return (static_cast<reverse_iterator>(_iter + n));
            }

            reverse_iterator &operator--()
            {
                ++_iter;
                return (*this);
            }

            reverse_iterator operator--(int)
            {
                reverse_iterator tmp(*this);
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
                iterator_type tmp(_iter);
                --tmp;
                return (tmp.operator->());
            }

            reference operator[] (difference_type n) const
            {
                return (static_cast<reference>(*(_iter - 1 - n)));
            }
    };
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (!(rhs < lhs));
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (rhs < lhs);
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (!(lhs < rhs));
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, \
        const reverse_iterator<Iterator>& rev_it)
    {
        return (rev_it + n);
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, \
        const reverse_iterator<Iterator>& rhs)
    {
        return (rhs.base() - lhs.base());
    }
}

#endif