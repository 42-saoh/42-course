#include "span.hpp"

Span::Span() : _capacity(0), _size(0) {}
Span::Span(unsigned int n) : _capacity(n), _size(0) {}
Span::~Span() {}
Span::Span(const Span &s) : vec(s.vec), _capacity(s._capacity), _size(s._size) {}

Span &Span::operator=(const Span &s)
{
    _capacity = s._capacity;
    _size = s._size;
    vec = s.vec;
    return (*this);
}

bool is_big(int i, int j)
{
    return (i > j);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    while(start < end)
    {
        if (size() == capacity())
            throw std::runtime_error("Put too many val");
        std::vector<int>::iterator iter = std::find_first_of(vec.begin(), vec.end(), start, start + 1, is_big);
        vec.insert(iter, *start);
        _size++;
        start++;
    }
}

void Span::addNumber(int val)
{
    int _val[2];

    if (size() == capacity())
        throw std::runtime_error("Put too many val");
    _val[0] = val;
    _val[1] = 0;
    std::vector<int>::iterator iter = std::find_first_of(vec.begin(), vec.end(), _val, _val + 1, is_big);
    vec.insert(iter, val);
    _size++;
}

long Span::shortestSpan(void)
{
    if (size() < 2)
        throw std::runtime_error("Span have Too few val");
    long result = -2147483648;
    for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end() - 1; iter++)
    {
        if (*iter - *(iter + 1) > result)
            result = *iter - *(iter + 1);
    }
    result *= -1;
    return (result);
}

long Span::longestSpan(void)
{
    if (size() < 2)
        throw std::runtime_error("Span have Too few val");
    long result = *(vec.end() - 1) - *vec.begin();
    return (result);
}

unsigned int Span::size(void)
{
    return (_size);
}

unsigned int Span::capacity(void)
{
    return (_capacity);
}

int &Span::operator[](int i)
{
    return (vec[i]);
}

void print(int val)
{
    std::cout << val << ", ";
}

void Span::print_all(void)
{
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
}