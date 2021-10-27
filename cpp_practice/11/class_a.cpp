#include <iostream>

class A
{
	private:
		int a;
		
		friend class B;
		friend void print_a();
	public:
		A(int a): a(a) {}
		void print_a(void) { std::cout << a << std::endl; }
};

class B
{
	private:
		int b;

	public:
		B(int b): b(b) {}
		void trans_b(A &a) { a.a = b; }

};

class C
{
	private:
		int c;

	public:
		C(int d): c(d) {
			A a(c);

			a.print_a();
		}
};

int main()
{
	A a(5);
	C c(7);

	a.print_a();
	B b(3);
	b.trans_b(a);
	a.print_a();
}
