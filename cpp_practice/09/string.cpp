#include <iostream>

class String {
  char	*str;
  int	len;

 public:
  String(char c, int c_len);
  String(char *string);
  int	strlen(char *string);
  void	add_str(String &st);
  void	strsub(String &st);
  int	strcmp(String &st);
};

String::String(char c, int c_len)
{
	len = c_len;
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
		str[i] = c;
	str[len] = 0;
}

String::String(char *string)
{
	len = strlen(string);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
		str[i] = string[i];
	str[len] = 0;
}

int	String::strlen(char *string)
{
	int i = 0;

	while (string[i])
		i++;
	return (i);
}

void	String::add_str(String &st)
{
	char *tmp_str;

	tmp_str = new char[len + st.len + 1];
	for (int i = 0; i < len; i++)
		tmp_str[i] = str[i];
	for (int i = 0; i < st.len; i++)
		tmp_str[len + i] = st.str[i];
	len = len + st.len;
	tmp_str[len] = 0;
}

void	String::strsub(String &st)
{
	int i;
	int j;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < st.len; j++)
		{
			if (str[i + j] != st.str[j] || i + j == len)
				break ;
		}
		if (j == st.len)

	}
}

int	String::strcmp(String &st)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != st.str[i])
			return (str[i] - st.str[i]);
	}
	if (!str[i] && st.str[i])
		return (-st.str[i]);
	return (0);
}

int main() {
}
