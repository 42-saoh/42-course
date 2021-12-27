#include "phonebook.hpp"

PhoneBook::PhoneBook() : is_full(false), index(1) {}

void PhoneBook::add(void)
{
    contact[index - 1].add_data();
    if (index == 8)
    {
        index = 1;
        is_full = true;
    }
    else
        index++;
}

void PhoneBook::search(int num)
{
    if (num >= index && !is_full)
    {
        std::cout << "This index does not exist" << std::endl;
        return ;

    }
    std::cout << "|Index     |First name|Last name |Nick name |" << std::endl;
    std::cout << "|" << num << "         |";
    contact[num - 1].print_data();
}

void PhoneBook::show_all()
{
    std::cout << "|Index     |First name|Last name |Nick name |" << std::endl;
    if (index == 1 && !is_full)
        return ;
    int i = 1;
    if (is_full)
    {
        while (i < 9)
        {
            std::cout << "|" << i << "         |";
            contact[i - 1].print_data();
            i++;
        }
    }
    else
    {
        while (i < index)
        {
            std::cout << "|" << i << "         |";
            contact[i - 1].print_data();
            i++;
        }
    }
}
