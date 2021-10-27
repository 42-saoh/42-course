#include <iostream>

void	use_reference(int &b)
{
	b = 7;
}

int main()
{
	int a;
	int &c = a;
	int *b;
	const int &d = 5;
	const int *e;

	a = 5;
	b = &a;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	b = &c;
	std::cout << "b : " << b << std::endl;
	use_reference(a);
	std::cout << "a : " << a << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "b : " << b << std::endl;
	b = &a;
	std::cout << "b : " << b << std::endl;
	e = &d;
	std::cout << "d : " << d << std::endl;
	std::cout << "e : " << e << std::endl;
}
