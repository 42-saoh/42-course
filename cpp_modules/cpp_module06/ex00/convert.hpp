#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <string>
# include <iostream>
# include <cmath>

class Convert
{
    private:
        std::string s;
        double val;
        bool _is_error;
        bool _is_nan;
        bool _is_inf;
        bool _is_exist_val;

    public:
        Convert();
        Convert(const std::string &str);
        Convert(const Convert &c);
        ~Convert();
        Convert &operator=(const Convert &c);
        void get_str(const std::string &str);
        void get_val();
        void tos();
        void toi();
        void tof();
        void tod();
        bool is_error();
};

#endif