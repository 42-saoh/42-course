#include "Karen.hpp"

std::string Karen::k_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Karen::debug(void)
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I just love it!" << std::endl;
}

void Karen::info(void)
{
    std::cout << "I cannot believe adding extra bacon cost more money." << std::endl;
    std::cout << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void)
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
    void (Karen::*karen_level[])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
 
    for (int i = 0; i < 4; i++)
    {
        if (level == k_level[i])
            ((this)->*karen_level[i])();
    }
}