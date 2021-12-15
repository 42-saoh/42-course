#include <iostream>

template <int N, int D>
struct is_divide
{
	static const bool result = (N % D == 0) || is_divide<N, D + 1>::result;
};

template <int N>
struct is_divide<N, N / 2>
{
	static const bool result = (N % (N / 2) == 0);
};

template <int N>
struct is_prime
{
	static const bool result = !is_divide<N, 2>::result;
};

template <>
struct is_prime<2>
{
	static const bool result = true;
};

template <>
struct is_prime<3>
{
	static const bool result = true;
};

int main()
{
  std::cout << std::boolalpha;
  std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl; // true
  std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl; // false
  std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl; // true
  std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl; // true
}
