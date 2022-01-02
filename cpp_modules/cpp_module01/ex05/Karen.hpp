#ifndef KAREN_HPP
# define KAREN_HPP
# include <string>
# include <iostream>

class Karen
{
    private:
        static std::string k_level[4];
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        void complain(std::string level);
};

#endif