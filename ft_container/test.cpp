#include <vector>
#include <iostream>

int main()
{
    std::vector<int> k;
    int **q;
    int *p;

    k.push_back(5);
    k.push_back(4);
    k.push_back(3);
    k.push_back(2);
    k.push_back(1);

    std::vector<int>::iterator i = k.begin();
    std::cout << i.base() << std::endl;
    std::cout << &i << std::endl;
    q = (int **)(&i); // < i == int *
    k.insert(i, 3);
    std::cout << i.base() << std::endl;
}