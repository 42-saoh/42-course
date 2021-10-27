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
		void increase_food(int inc_food)
		{
			food += inc_food;
			weight += (inc_food / 3);
		}
		void view_stat(void)
		{
			std::cout << "this pet food : " << food << std::endl;
			std::cout << "this pet weight : " << weight << std::endl;
		}
};

int main()
{
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return (0);
}
