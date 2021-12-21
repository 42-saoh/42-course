#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
        std::string *str_array[3];

    public:
        void add_data(void)
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
        void print_str_dada(int i)
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
        void print_data(void)
        {
            int i = 0;
            while (i < 3)
            {
                print_str_dada(i);
                i++;
            }
            std::cout << std::endl;
        }
};

class PhoneBook
{
    private:
        bool    is_full;
        int     index;
        Contact contact[8];
    
    public:
        PhoneBook() : is_full(false), index(1) {}
        void add(void)
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
        void search(int num)
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
        void show_all()
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

};
#endif