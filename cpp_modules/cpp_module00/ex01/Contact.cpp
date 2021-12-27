#include "Contact.hpp"

void Contact::add_data(void)
{
    std::cout << "Write your contact one by one" << std::endl;
    std::cout << "First name" << std::endl;
    std::getline(std::cin, first_name);
    std::cout << "last name" << std::endl;
    std::getline(std::cin, last_name);
    std::cout << "nickname" << std::endl;
    std::getline(std::cin, nick_name);
    std::cout << "phone number" << std::endl;
    std::getline(std::cin, phone_number);
    std::cout << "darkest secret" << std::endl;
    std::getline(std::cin, darkest_secret);
    std::cout << "Add End" << std::endl;
    str_array[0] = &first_name;
    str_array[1] = &last_name;
    str_array[2] = &nick_name;
}

void Contact::print_str_dada(int i)
{
    std::string tmp = *str_array[i];
    int j = 0;
    while (j < 10)
    {
        if (tmp[j])
        {
            if (j == 9)
                std::cout << ".";
            else
                std::cout << tmp[j];
        }
        else
            std::cout << " ";
        j++;
    }
    std::cout << "|";
}

void Contact::print_data(void)
{
    int i = 0;
    while (i < 3)
    {
        print_str_dada(i);
        i++;
    }
    std::cout << std::endl;
}