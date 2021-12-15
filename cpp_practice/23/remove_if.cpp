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

template <typename T>
class is_odd
{
	private:
		int *delete_num;

	public:
		is_odd(int *delete_num) : delete_num(delete_num) {}
		bool operator () (const T &i)
		{
			if (*delete_num < 2 && i % 2 == 1)
			{
				(*delete_num)++;
				return (true);
			}
			return (false);
		}
};

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
	std::cout << "벡터에서 값이 odd인 원소 제거 -----" << std::endl;
	int delete_num = 0;
	vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd<int>(&delete_num)), vec.end());
	print(vec.begin(), vec.end());
}
