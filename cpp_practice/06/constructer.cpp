#include <iostream>

class Animal {
	private:
		int food;
		int weight;

	public:
		void set_animal(int _food, int _weight)
		{
			food = _food;
			weight = _weight;
		}
		void view_stat(void)
		{
			std::cout << "this pet food : " << food << std::endl;
			std::cout << "this pet weight : " << weight << std::endl;
		}

	Animal(int _food, int _weight)
	{
		std::cout << "This is 2 arguments constructer" << std::endl;
		set_animal(_food, _weight);
		view_stat();
	}

	Animal()
	{
		std::cout << "This is default constructer" << std::endl;
		set_animal(50, 100);
		view_stat();
	}
};

int main()
{
	Animal animal(100, 50);
	Animal animal1;
	return (0);
}
