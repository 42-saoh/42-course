#include <iostream>

class String{
	private:
		char	*str;
		int		len;

	public:
		String(char c, int n);
		String(const char *s);
		String(const String &s);
		~String();
	
		void 	add_string(const String &s);
		void	copy_string(const String &s);
		void	print_string();
		int		strlen();
};

int String::strlen(void)
{
	int		i = 0;
	char	*clone;

	clone = str;
	while(*clone++)
		i++;
	return (i);
}

void	String::add_string(const String &s)
{
	char *tmp_str;

	tmp_str = new char[len + s.len + 1];
	strcpy(tmp_str, str);
	for (int i = 0; i < s.len; i++)
		tmp_str[len + i] = s.str[i];
	len = len + s.len;
	tmp_str[len] = 0;
	delete[] str;
	str = tmp_str;
}

void	String::copy_string(const String &s)
{
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

void	String::print_string(void)
{
	std::cout << str << std::endl;
	std::cout << "len : " << strlen() << std::endl;
}

String::String(char c, int n)
{
	len = n;
	str = new char[n + 1];
	for (int i = 0; i < len; i++)
		str[i] = c;
	str[len] = 0;
}

String::String(const char *s)
{
	int i = 0;
	
	while (s[i])
		i++;
	len = i;
	str = new char[len + 1];
	strcpy(str, s);
}

String::String(const String &s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

String::~String()
{
	if (str)
		delete[] str;
}

int main()
{
	String s1('a', 10);
	String s2(s1);
	String s3("aaaaaaaaaa");

	s1.print_string();
	s2.print_string();
	s3.print_string();

	s1.add_string(s2);
	s1.print_string();
	s2.print_string();
	
	s3.copy_string(s1);
	s1.print_string();
	s3.print_string();
}
