#include "phonebook.hpp"

int main()
{
    PhoneBook pb;

    while (1)
    {
        std::cout << "ADD, SEARCH, EXIT" << std::endl;
        std::string input;
        if (!std::getline(std::cin, input))
            break ;
        if (input == "ADD")
            pb.add();
        else if (input == "SEARCH")
        {
            std::cout << "INPUT INDEX 0 ~ 8 (0 : ALL CONTACT SHOW)" << std::endl;
            int index;
            std::cin >> index;
            if (index == 0)
                pb.show_all();
            else if (index >= 1 && index <= 8)
                pb.search(index);
            std::cin.ignore();
        }
        else if (input == "EXIT")
            break ;
        else
            std::cout << "Retry" << std::endl;
    }
}