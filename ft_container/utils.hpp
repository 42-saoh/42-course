#ifndef UTILS_HPP
# define UTILS_HPP
# include <string>
# include <iostream>

namespace ft
{
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
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T*>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

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
        return (lhs.base() == rhs.base() ? true : false);
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base() ? false : true);
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base() ? false : true);
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base() ? false : true);
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base() ? false : true);
    }

    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base() ? false : true);
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
        return (lhs.base().base() - rhs.base().base());
    }

    template<bool Cond, class T = void>
    struct enable_if {};
    
    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <class T, T v >
    struct integral_constant
    {
        typedef T value_type;
        typedef integral_constant<T,v> type;
        static const T value = v;
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template <class T>
    struct is_integral : false_type {};

    template <>
    struct is_integral<bool> : public true_type {};

    template <>
    struct is_integral<char> : public true_type {};

    template <>
    struct is_integral<wchar_t> : public true_type {};

    template <>
    struct is_integral<signed char> : public true_type {};

    template <>
    struct is_integral<short int> : public true_type {};

    template <>
    struct is_integral<int> : public true_type {};

    template <>
    struct is_integral<long int> : public true_type {};

    template <>
    struct is_integral<long long int> : public true_type {};

    template <>
    struct is_integral<unsigned char> : public true_type {};

    template <>
    struct is_integral<unsigned short int> : public true_type {};

    template <>
    struct is_integral<unsigned int> : public true_type {};

    template <>
    struct is_integral<unsigned long int> : public true_type {};

    template <>
    struct is_integral<unsigned long long int> : public true_type {};

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while(first1 != last1)
        {
            if (!(*first1 == *first2))
                return (false);
            ++first1;
            ++first2;
        }
        return (true);
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return (false);
            ++first1;
            ++first2;
        }
        return (true);
    }
}

#endif