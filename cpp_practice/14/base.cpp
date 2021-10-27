#include <iostream>
#include <string>

class Base
{
	private:
		std::string s;

	public:
		Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }
		void what() { std::cout << s << std::endl; }
};

class Derived : public Base
{
	private:
		std::string s;

	public:
		Derived() : Base(), s("파생")
		{
			std::cout << "파생 클래스" << std::endl;
		}
		void what() { std::cout << s << std::endl; }
};

int main()
{
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	p.what();

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	c.what();
	
	std::cout << " === 포인터 생성 ===" << std::endl;
	Base *p_c = &c;
	p_c->what();
}
