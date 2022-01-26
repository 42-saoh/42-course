#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <string>
# include <iostream>
# include <cmath>

class convert
{
    private:
        std::string s;
        double val;
        bool _is_error;
        bool _is_nan;
        bool _is_inf;

    public:
        convert(const std::string &str);
        void tos();
        void toi();
        void tof();
        void tod();
        bool is_error();
};

#endif