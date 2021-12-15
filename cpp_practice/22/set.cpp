#include <iostream>
#include <set>
#include <string>

template <typename T>
void	print_set(std::set<T>& s)
{
	for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
		std::cout << *itr << std::endl;
}

class Todo
{
	private:
		int priority;
		std::string job_desc;

	public:
		Todo(int priority, std::string job_desc) : priority(priority), job_desc(job_desc) {}
		bool operator<(const Todo& t) const;
		friend struct Todo_cmp;
		friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

struct Todo_cmp
{
	bool operator()(const Todo& t1, const Todo& t2)
	{
		if (t1.priority == t2.priority)
			return (t1.job_desc < t2.job_desc);
		return (t1.priority > t2.priority);
	}
};

bool Todo::operator<(const Todo& t) const
{
	if (priority == t.priority)
		return (job_desc < t.job_desc);
	return (priority > t.priority);
}

std::ostream& operator<<(std::ostream& o, const Todo& td)
{
	o << "[ 중요도 : " << td.priority << "] " << td.job_desc;
	return (o);
}

int main()
{
	std::set<Todo> s;
	s.insert(Todo(1, "농구 하기"));
	s.insert(Todo(2, "수학 숙제 하기"));
	s.insert(Todo(1, "프로그래밍 프로젝트"));
	s.insert(Todo(3, "친구 만나기"));
	s.insert(Todo(2, "영화 보기"));

	print_set(s);
	s.erase(s.find(Todo(2, "수학 숙제 하기")));
	print_set(s);
}
