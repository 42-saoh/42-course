#include <iostream>

template <int N>
struct Factorial
{
	static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1>
{
	static const int result = 1;
};


int main()
{
	std::cout << Factorial<5>::result << std::endl;
}
