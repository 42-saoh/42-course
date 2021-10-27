#include <iostream>

class A
{
	private:
		int x;

	public:
		int &access_x();
		int get_x();
		A(int c);
		void show_x();
};

A::A(int c) : x(c) {}

int &A::access_x(void)
{
	return x;
}

int A::get_x(void)
{
	return x;
}

void A::show_x(void)
{
	std::cout << "x : " << x << std::endl;
}

int main()
{
	A a(5);
	a.show_x();

	int &c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	std::cout << "d : " << d << std::endl;
	d = 3;
	a.show_x();

	int f = a.get_x();
	std::cout << "f : " << f << std::endl;
	f = 1;
	a.show_x();
}
