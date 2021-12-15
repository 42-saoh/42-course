#include <iostream>

template <typename T>
void	print(T arg)
{
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void	print(T arg, Types... args)
{
	std::cout << arg << ", ";
	print(args...);
}

int main()
{
	print("asd", 3, 5.5);
	print("asd", 3, 5.5);
}
