#include "convert.hpp"

convert::convert(const std::string &str) : s(str), _is_error(false), _is_nan(false), _is_inf(false)
{
    try
    {
        char *remainder;
        val = std::strtod(s.c_str(), &remainder);
        if (val == 0.0 && (s[0] != '-' && s[0] != '+' && !std::isdigit(s[0])))
            throw (0);
        else if (*remainder && std::strcmp(remainder, "f"))
            throw (1);
        if (std::isnan(val))
            _is_nan = true;
        if (std::isinf(val))
            _is_inf = true;
    }
    catch(int i)
    {
        switch (i)
        {
            case 0:
                std::cout << "Enter the number." << std::endl;
                break ;
            
            case 1:
                std::cout << "Enter the correct number." << std::endl;
                break ;
        }
        _is_error = true;
    }
    
}

void convert::tos()
{
    std::cout << "char: ";
    if (_is_nan || _is_inf || val > 255 || val < 0)
        std::cout << "impossible" << std::endl;
    else if ((val >= 9 && val <= 13) || (val >= 32 && val <= 126))
    {
        char c = val;
        std::cout << "'" << c << "'" << std::endl;
    }
    else
        std::cout << "Non displayable" << std::endl;
}

void convert::toi()
{
    std::cout << "int: ";
    if (_is_nan || _is_inf || val > INT32_MAX || val < INT32_MIN)
        std::cout << "impossible" << std::endl;
    else
    {
        int i = val;
        std::cout << i << std::endl;
    }

}

void convert::tof()
{
    float i = val;
    std::cout << "float: " << i << "f" << std::endl;
}

void convert::tod()
{
    std::cout << "double: " << val << std::endl;
}

bool convert::is_error(void)
{
    return (_is_error);
}