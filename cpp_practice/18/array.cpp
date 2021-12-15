#include <iostream>

template <typename T, unsigned int N>
class Array
{
	private:
		T data[N];

	public:
		Array(T (&arr)[N])
		{
			for(int i = 0; i < N; i++)
				data[i] = arr[i];
		}
		T *get_array(void)
		{
			return (data);
		}
		unsigned int size(void)
		{
			return (N);
		}
		void print_all(void)
		{
			for (int i = 0; i < N - 1; i++)
				std::cout << data[i] << ", ";
			std::cout << data[N - 1] << std::endl;
		}
};

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	Array<int, 5> arr(array);
	std::cout << arr.size() << std::endl;
	arr.print_all();
}
