#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end)
{
	while (begin != end)
	{
		std::cout << "[" << *begin << "] ";
		begin++;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(4);
	std::cout << "처을 vec 상태 ------" << std::endl;
	print(vec.begin(), vec.end());
	std::cout << "벡터에서 값이 3인 원소 제거 -----" << std::endl;
	vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
	print(vec.begin(), vec.end());
}
