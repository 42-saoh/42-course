#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m)
{
	for (auto itr = m.begin(); itr != m.end(); ++itr)
		std::cout << itr->first << " " << itr->second << std::endl;
}

template <typename K, typename V>
void search_and_print(std::map<K, V>& m, K key)
{
	auto itr = m.find(key);
	if (itr != m.end())
		std::cout << key << " : " << itr->second << std::endl;
	else
		std::cout << key << "didn't exist index" << std::endl;
}

int main()
{
	std::map<std::string, double> p_lst;

	p_lst.insert(std::pair<std::string, double>("박세웅", 2.23));
	p_lst.insert(std::pair<std::string, double>("해커", 2.93));
	p_lst.insert(std::pair<std::string, double>("피어밴드", 2.95));
	p_lst.insert(std::make_pair("차우찬", 3.04));
	p_lst.insert(std::make_pair("장원준", 3.05));
	p_lst.insert(std::make_pair("헥터", 3.09));
	p_lst["니퍼트"] = 3.56;
	p_lst["박종훈"] = 3.76;
	p_lst["켈리"] = 3.90;
	print_map(p_lst);
	std::cout << "박세웅 방어율은? :: " << p_lst["박세웅"] << std::endl;
	search_and_print(p_lst, std::string("박세웅"));
	search_and_print(p_lst, std::string("류현진"));
}
