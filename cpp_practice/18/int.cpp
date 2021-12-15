#include <iostream>

template <int N>
struct Int
{
	static const int n = N;
};

template <typename T, typename U>
struct add
{
	typedef Int<T::n + U::n> result;
};

int main()
{
	typedef Int<1> one;
	typedef Int<2> two;

	typedef add<one, two>::result three;
	std::cout << "this is singi : " << three::n << std::endl;
}
