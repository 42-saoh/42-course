#include <iostream>

int main()
{
	char input;

	while (1)
	{
		std::cout << "입력 : ";
		std::cin >> input;
		if (input == '0')
		{
			std::cout << "it's so good\n";
			break ;
		}
		else
			std::cout << "nono it's not cool\n";
	}
	return (0);
}
