#include <iostream>

class Int
{
	private:
		int data;

	public:
		Int(int data) : data(data) {}
		Int(const Int &i) : data(i.data) {}
		int get_x(void) const { return (data); }
		Int &operator++(void);
		Int operator++(int);
};

Int &Int::operator++(void)
{
	++data;
	std::cout << " 전위 증감 연산자" << std::endl;
	return (*this);
}

void func(const Int &x)
{
	std::cout << "x : " << x.get_x() << std::endl;
}

Int Int::operator++(int)
{
	Int tmp(*this);

	++data;
	std::cout << " 후위 증감 연산자" << std::endl;
	return (tmp);
}

int main()
{
	Int x(3);

	func(x++);
	func(++x);
}
