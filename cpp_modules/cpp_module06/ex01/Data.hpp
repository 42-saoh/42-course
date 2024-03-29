#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>
# include <string>

class Data
{
    private:
        int a;
        std::string b;
        long c;
        float d;
        double e;

    public:
        Data();
        Data(const Data &_d);
        ~Data();
        Data &operator=(const Data &_d);
        void print_data(void);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif