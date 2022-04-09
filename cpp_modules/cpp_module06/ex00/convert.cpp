#include "Convert.hpp"

Convert::Convert() : s(""), val(0.0), _is_error(false), _is_nan(false), _is_inf(false), _is_exist_val(false) {}
Convert::~Convert() {}
Convert::Convert(const std::string &str) : s(str), val(0.0), _is_error(false), _is_nan(false), _is_inf(false), _is_exist_val(true)
{
    get_val();
}

Convert::Convert(const Convert &c)
    : s(c.s), val(c.val), _is_error(c._is_error), _is_nan(c._is_nan), _is_inf(c._is_inf), _is_exist_val(c._is_exist_val) {}

Convert &Convert::operator=(const Convert &c)
{
    s = c.s;
    val = c.val;
    _is_error = c._is_error;
    _is_nan = c._is_nan;
    _is_inf = c._is_inf;
    _is_exist_val = c._is_exist_val;
    return (*this);
}

void Convert::get_val()
{
    try
    {
        char *remainder;
        val = std::strtod(s.c_str(), &remainder);
        if (val == 0.0 && (s[0] != '-' && s[0] != '+' && !std::isdigit(s[0])))
            throw std::invalid_argument("Enter the correct number.");
        else if (*remainder && std::strcmp(remainder, "f"))
            throw std::invalid_argument("Enter the correct number.");
        if (std::isnan(val))
            _is_nan = true;
        if (std::isinf(val))
            _is_inf = true;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        _is_error = true;
    }
}

void Convert::get_str(const std::string &str)
{
    s = str;
}

void Convert::tos()
{
    if (_is_exist_val)
    {
        std::cout << "char: ";
        if (_is_nan || _is_inf || val > 255 || val < 0)
            std::cout << "impossible" << std::endl;
        else if ((val >= 9 && val <= 13) || (val >= 32 && val <= 126))
            std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "You have no value" << std::endl;
}

void Convert::toi()
{
    if (_is_exist_val)
    {
        std::cout << "int: ";
        if (_is_nan || _is_inf || val > INT32_MAX || val < INT32_MIN)
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(val) << std::endl;
    }
    else
        std::cout << "You have no value" << std::endl;
}

void Convert::tof()
{
    if (_is_exist_val)
    {
        if (val - ceil(val))
            std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
    }
    else
        std::cout << "You have no value" << std::endl;
}

void Convert::tod()
{
    if (_is_exist_val)
    {
        if (val - ceil(val))
            std::cout << "double: " << val << std::endl;
        else
            std::cout << "double: " << val << ".0" << std::endl;
    }
    else
        std::cout << "You have no value" << std::endl;
}

bool Convert::is_error(void)
{
    return (_is_error);
}