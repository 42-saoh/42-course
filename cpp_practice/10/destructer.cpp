#include <iostream>

class Animal {
	private:
		static int number_of_pet;
		int food;
		int weight;
		int	pet_number;
		const int defualt_weight_cut;
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
		static void show_number_of_pet(void)
		{
			std::cout << "The total number of pet is " << number_of_pet <<std::endl;
		}
		int	weight_traing();
		void operator==(Animal &a1);
		Animal &worked_out(int cut_weight);

	Animal(int _food, int _weight, const char *_name) : defualt_weight_cut(5)
	{
		number_of_pet++;
		std::cout << "This is 3 arguments constructer" << std::endl;
		name = new char[strlen(_name) + 2];
		strcpy(name, _name);
		pet_number = 0;
		std::cout << "my name is " << name << pet_number <<std::endl;
		set_animal(_food, _weight);
		view_stat();
	}

	Animal(const Animal &animal) : defualt_weight_cut(5)
	{
		number_of_pet++;
		std::cout << "This is dup constructer" << std::endl;
		name = new char[strlen(animal.name) + 1];
		strcpy(name, animal.name);
		pet_number = animal.pet_number + 1;
		std::cout << "my name is " << name << pet_number <<std::endl;
		set_animal(animal.food, animal.weight);
		view_stat();
	}

	Animal() : defualt_weight_cut(5)
	{
		number_of_pet++;
		std::cout << "This is default constructer" << std::endl;
		set_animal(50, 100);
		name = 0;
		view_stat();
	}
	
	~Animal()
	{
		number_of_pet--;
		if (name != 0)
		{
			std::cout << name << pet_number <<"의 소멸 !" << std::endl;
			delete[] name;
		}
	}
};


int	Animal::weight_traing(void) { return defualt_weight_cut; }

void Animal::operator==(Animal &a1)
{
	a1.worked_out(a1.weight_traing());
}

Animal &Animal::worked_out(int cut_weight)
{
	weight -= cut_weight;
	return *this;
}

int Animal::number_of_pet = 0;

void	test(void)
{
	Animal animal2(50, 100, "dog");
	Animal::show_number_of_pet();
}

int main()
{
	Animal animal1(100, 50, "cat");
	Animal animal2(animal1);
	Animal animal3 = animal2;
	Animal animal4 = animal3;

	animal1.worked_out(animal1.weight_traing()).worked_out(animal1.weight_traing());
	animal1.view_stat();
	animal1==animal2;
	animal2.view_stat();
	test();
	Animal::show_number_of_pet();
	return (0);
}
