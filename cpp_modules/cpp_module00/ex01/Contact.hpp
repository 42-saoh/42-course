#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

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
        void add_data(void);
        void print_str_dada(int i);
        void print_data(void);
};

#endif