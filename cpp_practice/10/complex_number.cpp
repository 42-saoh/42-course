#include <iostream>

class Complex
{
	private:
		double	real, img;

	public:
		Complex(double real, double img);
		Complex plus(const Complex &c) const;
		Complex minus(const Complex &c) const;
		Complex times(const Complex &c) const;
		Complex	divide(const Complex &c) const;
		Complex operator+(const Complex &c);
		Complex operator+(const char *str);
		Complex &operator+=(const Complex &c);
		Complex operator-(const Complex &c);
		Complex &operator-=(const Complex &c);
		Complex operator*(const Complex &c);
		Complex &operator*=(const Complex &c);
		Complex operator/(const Complex &c);
		Complex &operator/=(const Complex &c);
		Complex &operator=(const Complex &c);
		double	get_number(const char *str, int begin, int end);
		void println(void);
};

double	Complex::get_number(const char *str, int begin, int end)
{
	int minus = 1;
	double num = 0.0;

	if (begin > end)
		return 0;
	if (str[begin] == '-' || str[begin] == '+')
	{
		if (str[begin] == '-')
			minus *= -1;
		begin++;
	}
	for (int i = begin; i <= end; i++)
	{
		if (isdigit(str[i]))
			num = (num * 10) + (str[i] - '0');
		else if (str[i] == '.')
		{
			int k = i;
			double decimal = 1.0;
			for (int j = k + 1; j <= end; j++)
			{
				if (isdigit(str[j]))
				{
					decimal /= 10;
					num += ((str[j] - '0') * decimal);
					i = j;
				}
				else
					break ;
			}
		}
		else
			break ;
	}
	num *= minus;
	return (num);
}

Complex::Complex(double real, double img) : real(real), img(img)
{
}

void Complex::println(void)
{
	std::cout << "( " << real << " , " << img << " ) " << std::endl;
}

Complex &Complex::operator+=(const Complex &c)
{
	(*this) = (*this) + c;
	return *this;
}

Complex &Complex::operator-=(const Complex &c)
{
	(*this) = (*this) - c;
	return *this;
}

Complex &Complex::operator*=(const Complex &c)
{
	(*this) = (*this) * c;
	return *this;
}

Complex &Complex::operator/=(const Complex &c)
{
	(*this) = (*this) / c;
	return *this;
}

Complex Complex::operator/(const Complex &c)
{
	return (divide(c));
}

Complex Complex::operator*(const Complex &c)
{
	return (times(c));
}

Complex Complex::operator-(const Complex &c)
{
	return (minus(c));
}

Complex Complex::operator+(const char *str)
{
	int begin = 0, end = strlen(str);
	double str_img = 0.0, str_real = 0.0;

	int pos_i = -1;
	for (int i = 0; i < end; i++)
	{
		if (str[i] == 'i')
		{
			pos_i = i;
			break;
		}
	}
	if (pos_i == -1)
	{
		str_real = get_number(str,begin, end - 1);
		Complex temp(str_real, str_img);
		return (*this) + temp;
	}
	str_real = get_number(str, begin, pos_i - 1);
	str_img = get_number(str, pos_i + 1, end - 1);
	if (pos_i >= 1 && str[pos_i - 1] == '-')
		str_img *= -1.0;
	Complex temp(str_real, str_img);
	return (*this) + temp;
}

Complex Complex::operator+(const Complex &c)
{
	return (plus(c));
}

Complex &Complex::operator=(const Complex &c)
{
	real = c.real;
	img = c.img;
	return *this;
}

Complex Complex::plus(const Complex &c) const
{
	Complex temp(real + c.real, img + c.img);
	return (temp);
}

Complex Complex::minus(const Complex &c) const
{
	Complex temp(real - c.real, img - c.img);
	return (temp);
}

Complex Complex::times(const Complex &c) const
{
	Complex temp((real * c.real) - (img * c.img), (real * c.img) + (img * c.real));
	return (temp);
}

Complex Complex::divide(const Complex &c) const
{
	Complex temp(
			(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
			(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return (temp);
}

int main()
{
	Complex a(0.0, 0.0);

	a = a + "-1.1 + i3.923";
	a.println();
}
