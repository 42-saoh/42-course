#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
    private:
        bool    is_full;
        int     index;
        Contact contact[8];
    
    public:
        PhoneBook();
        void add(void);
        void search(int num);
        void show_all();
};

#endif