#include "phonebook.hpp"

int main()
{
    PhoneBook pb;

    while (1)
    {
        std::cout << "'ADD', 'SEARCH', 'EXIT'" << std::endl;
        std::string input;
        if (!std::getline(std::cin, input))
            break ;
        if (input == "ADD")
            pb.add();
        else if (input == "SEARCH")
        {
            int index;
            while (1)
            {
                std::cout << "INPUT INDEX 0 ~ 9 (0 : ALL CONTACT SHOW, 1 ~ 8 : INDEX, 9 : EXIT)" << std::endl;
                std::cin >> index;
                if (index == 0)
                {
                    pb.show_all();
                    break ;
                }
                else if (index >= 1 && index <= 8)
                    pb.search(index);
                else if (index == 9)
                    break ;
            }
            std::cin.ignore();
            std::cin.clear();
        }
        else if (input == "EXIT")
            break ;
        else
            std::cout << "Retry" << std::endl;
    }
}