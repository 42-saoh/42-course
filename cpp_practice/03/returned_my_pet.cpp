#include <iostream>

typedef struct	s_animal
{
	char	name[30];
	int		age;
	int		health;
	int		food;
	int		clean;
}				t_animal;

void	show_stat(t_animal *a_list, int num)
{
	std::cout << "pet name : " << a_list[num].name << std::endl;
	std::cout << "pet age : " << a_list[num].age << std::endl;
	std::cout << "pet health : " << a_list[num].health << std::endl;
	std::cout << "pet food : " << a_list[num].food << std::endl;
	std::cout << "pet clean : " << a_list[num].clean << std::endl;
}

void	play(t_animal *a_list, int max_list_num)
{
	for (int i = 0; i < max_list_num; i++)
	{
		a_list[i].age += 1;
		a_list[i].health -= 3;
		a_list[i].food -= 5;
		a_list[i].clean -= 1;
	}
}

int main()
{
	t_animal *a_list = new t_animal[30];
	int	max_list_num;
	
	{
		int yes_or_no;
		int i = 0;
		while(i < 30)
		{
			std::cout << "Create your pet? yes : 1, no : 0" << std::endl;
			std::cin >> yes_or_no;
			if (yes_or_no == 1)
			{
				std::cout << "Put your pet name : ";
				std::cin >> a_list[i].name;
				std::cout << "Put your pet age : ";
				std::cin >> a_list[i].age;
				std::cout << "Put your pet health : ";
				std::cin >> a_list[i].health;
				std::cout << "Put your pet food : ";
				std::cin >> a_list[i].food;
				std::cout << "Put your pet clean : ";
				std::cin >> a_list[i].clean;
				i++;
			}
			else if (!yes_or_no)
				break ;
			else
				std::cout << "Are you idot? why push other key?" << std::endl;
		}
		max_list_num = i;
	}
	{
		int choice;
		while(1)
		{

			play(a_list, max_list_num);
			show_stat(a_list, num);
		}
	}
	delete[] a_list;
}
