#include <iostream>

int main()
{
	int a;
	int& another_a = a;
	int *b;

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
	b = &a;
	std::cout << "b : " << b << std::endl;
	b = &another_a;
	std::cout << "b : " << b << std::endl;
}
