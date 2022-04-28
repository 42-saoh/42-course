#include "vector.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include "stack.hpp"

int main()
{
    ft::stack<int> a;
    std::stack<int, std::vector<int> > q;

    std::cout << a.empty() << std::endl;
    std::cout << q.empty() << std::endl;
    a.pop();
    q.pop();
    std::cout << a.empty() << std::endl;
    std::cout << q.empty() << std::endl;
}