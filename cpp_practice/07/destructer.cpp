#include <iostream>

class Animal {
	private:
		int food;
		int weight;
		int	pet_number;
		char *name;

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

	Animal(int _food, int _weight, const char *_name)
	{
		std::cout << "This is 3 arguments constructer" << std::endl;
		name = new char[strlen(_name) + 2];
		strcpy(name, _name);
		pet_number = 0;
		std::cout << "my name is " << name << pet_number <<std::endl;
		set_animal(_food, _weight);
		view_stat();
	}

	Animal(const Animal &animal)
	{
		std::cout << "This is dup constructer" << std::endl;
		name = new char[strlen(animal.name) + 1];
		strcpy(name, animal.name);
		pet_number = animal.pet_number + 1;
		std::cout << "my name is " << name << pet_number <<std::endl;
		set_animal(animal.food, animal.weight);
		view_stat();
	}

	Animal()
	{
		std::cout << "This is default constructer" << std::endl;
		set_animal(50, 100);
		name = 0;
		view_stat();
	}
	
	~Animal()
	{
		if (name != 0)
		{
			std::cout << name << pet_number <<"의 소멸 !" << std::endl;
			delete[] name;
		}
	}
};

void	test(void)
{
	Animal animal2(50, 100, "dog");
}

int main()
{
	Animal animal1(100, 50, "cat");
	Animal animal2(animal1);
	Animal animal3 = animal2;
	Animal animal4 = animal3;

	test();
	return (0);
}
