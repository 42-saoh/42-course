#include <string>
#include <iostream>

using std::string;

class Vector
{
	private:
		string	*data;
		int		capacity;
		int		length;

	public:
		Vector(int n = 1);
		void	push_back(string s);
		string	operator[](int i);
		void	remove(int x);
		int		size(void);
		~Vector(void);
};

Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}

void	Vector::push_back(string s)
{
	if (capacity <= length)
	{
		string *temp = new string[capacity * 2];
		for (int i = 0; i < length; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		capacity *= 2;
	}
	data[length++] = s;
}

string	Vector::operator[](int i)
{
	return (data[i]);
}

void	Vector::remove(int x)
{
	for (int i = x + 1; i < length; i++)
		data[i - 1] = data[i];
	length--;
}

int	Vector::size(void)
{
	return (length);
}

Vector::~Vector(void)
{
	if (data)
		delete[] data;
}
