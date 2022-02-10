#ifndef Span_HPP
# define Span_HPP
# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int _capacity;
        unsigned int _size;
    
    public:
        Span(unsigned int n);
        void addNumber(int val);
        void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
        long shortestSpan(void);
        long longestSpan(void);
        unsigned int size(void);
        unsigned int capacity(void);
        int &operator[](int i);
        void print_all(void);
};

#endif