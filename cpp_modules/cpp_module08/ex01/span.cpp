#include "span.hpp"

Span::Span(unsigned int n) : _capacity(n), _size(0) {}

bool is_big(int i, int j)
{
    return (i > j);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    while(start < end)
    {
        addNumber(*start);
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
    long result = -4294967296;
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