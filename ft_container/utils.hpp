#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if {};
    
    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <class T, T v >
    struct integral_constant
    {
        typedef T value_type;
        typedef integral_constant<T, v> type;
        static const T value = v;
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template <typename T, typename U>
    struct is_same : public false_type {};

    template <typename T>
    struct is_same<T, T> : public true_type {};

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

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, \
                                    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return (false);
            else if (*first1 < *first2)
                return (true);
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, \
                                    InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while (first1!=last1)
        {
            if (first2 == last2 || !comp(*first1, *first2))
                return (false);
            else if (comp(*first1, *first2))
                return (true);
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair() : first(), second() {}
        template <class U, class V>
        pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}
        pair &operator=(const pair &pr)
        {
            first = pr.first;
            second = pr.second;
            return (*this);
        }
    };

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(lhs==rhs));
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }
    
    template <class _Arg1, class _Arg2, class _Result>
    struct binary_function
    {
        typedef _Arg1 first_argument_type;
        typedef _Arg2 second_argument_type;
        typedef _Result result_type;
    };


    template<typename _Arg, typename _Result>
    struct unary_function
    {
        typedef _Arg argument_type;
        typedef _Result result_type;
    };

    template<typename _Tp>
    struct _Identity : public ft::unary_function<_Tp, _Tp>
    {
        _Tp &operator()(_Tp &_x) const
        {
            return (_x);
        }

        const _Tp &operator()(const _Tp &_x) const
        {
            return (_x);
        }
    };

    template<typename _Pair>
    struct _Select1st : public unary_function<_Pair, typename _Pair::first_type>
    {
        typename _Pair::first_type &operator()(_Pair &_x) const
        {
            return (_x.first);
        }

        const typename _Pair::first_type &operator()(const _Pair &_x) const
        {
            return (_x.first);
        }
    };
}

#endif