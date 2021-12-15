#include <iostream>

struct A
{
	void a(int x)
	{
		std::cout << "Do many times this : " << x << std::endl;
	}
};

template <typename... args>
void print_many(A a1, args... x)
{
	return (a1.a(x), ...);
}

int main()
{
	A a;
	
	print_many(a, 5, 4, 3, 2, 1);
}
