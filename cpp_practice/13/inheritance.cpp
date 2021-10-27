#include <string>
#include <iostream>

class Base
{
	public:
		std::string parent;
		Base() : parent("기반") { std::cout << "기반 클래스" << std::endl; }
		void what() { std::cout << parent << std::endl; }
};

class Derived : public Base
{
	private:
		std::string child;

	public:
		Derived() : Base(), child("파생")
		{ std::cout << "파생 클래스" << std::endl;
			parent = "바 뀜";
		}
		void what() { std::cout << parent << std::endl; }
};

int main()
{
	Derived b;

	std::cout << b.parent << std::endl;
}
