#include <iostream>

template <typename... args>
int	sum(args... nums)
{
	return (... + nums);
}

template <typename... args>
double	average(args... nums)
{
	return (static_cast<double>(sum(nums...)) / sizeof...(nums));
}

int main()
{
	std::cout << average(1, 5, 2, 13, 10) << std::endl;
}
