#include <iostream>
#include <string>

int main(){
	std::string s = "abc";
	std::string s1("abd");
	std::string s2;

	s2 = s;
	std::cout << s << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	if (s == s2)
		std::cout << "good" << std::endl;
	if (s1 == s2)
		std::cout << "bad" << std::endl;
	if (s1 > s2)
		std::cout << "good" << std::endl;
	std::cout << s1.length() << std::endl;
}
