#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        static Zombie* newZombie(std::string name);
        static void randomChump(std::string name);
        void announce(void);
        Zombie(std::string name);
        ~Zombie(void);
};

#endif