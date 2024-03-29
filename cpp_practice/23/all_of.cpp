#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end)
{
	while (begin != end)
	{
		std::cout << "[" << *begin << "] ";
		begin++;
	}
	std::cout << std::endl;
}

struct User
{
	std::string name;
	int level;

	User(std::string name, int level) : name(name), level(level) {}
	bool operator==(const User &user) const
	{
		if (name == user.name && level == user.level)
			return (true);
		return (false);
	}
};

class Party
{
	private:
		std::vector<User> users;

	public:
		bool add_user(std::string name, int level)
		{
			User new_user(name, level);
			if (std::find(users.begin(), users.end(), new_user) != users.end())
				return (false);
			users.push_back(new_user);
			return (true);
		}
		bool can_join_dungeon()
		{
			return (std::all_of(users.begin(), users.end(), [](User &user) { return (user.level >= 15);}));
		}
		bool can_user_special_item()
		{
			return (std::any_of(users.begin(), users.end(), [](User &user) { return (user.level >= 19);}));
		}
};

int main()
{
	Party party;
	party.add_user("철수", 15);
	party.add_user("동수", 18);
	party.add_user("금수", 12);
	party.add_user("은수", 19);

	std::cout << std::boolalpha;
	std::cout << "던전 입장 가능 ? " << party.can_join_dungeon() << std::endl;
	std::cout << "특별 아이템 사용 가능 ?" << party.can_user_special_item() << std::endl;
}
