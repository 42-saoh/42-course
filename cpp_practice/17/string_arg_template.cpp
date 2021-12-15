#include <string>
#include <iostream>

int	get_length(const char *str)
{
	return (strlen(str));
}

int	get_length(const std::string &s)
{
	return (s.size());
}

template <typename arg, typename... args>
int	get_length(arg &s1, args... strs)
{
	return (get_length(s1) + get_length(strs...));
}

template <typename arg>
void append_str(std::string *result, arg s)
{
	result->append(s);
}

template <typename arg, typename... args>
void append_str(std::string *result, arg s, args... strs)
{
	result->append(s);
	return (append_str(result, strs...));
}

template <typename arg, typename... args>
std::string concat(arg s1, args... strs)
{
	int length = get_length(s1, strs...);
	std::string result;
	result.reserve(length);
	result = s1;
	append_str(&result, strs...);
	return (result);
}

int main()
{
	std::string s = concat("std", "::", "cout");
	std::cout << s << std::endl;
}
