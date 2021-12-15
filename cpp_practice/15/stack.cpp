#include <string>
#include <iostream>

using	std::string;

class Stack
{
	private:
		struct Node
		{
			Node	*prev;
			string	s;

			Node(Node *prev, string s) : prev(prev), s(s) {}
		};
		Node	*current;
		Node	start;

	public:
		Stack(void);
		void	push(string s);
		string	pop(void);
		string	peek(void);
		bool	is_empty(void);
		~Stack(void);
};

Stack::Stack(void) : start(NULL, "")
{
	current = &start;
}

void	Stack::push(string s)
{
	Node *n = new Node(current, s);
	current = n;
}

string	Stack::pop(void)
{
	if (current == &start)
		return ("");
	string s = current->s;
	Node *prev = current;
	current = current->prev;
	delete prev;
	return s;
}

string	Stack::peek(void)
{
	return (current->s);
}

bool	Stack::is_empty(void)
{
	if (current == &start)
		return (true);
	return (false);
}

Stack::~Stack(void)
{
	while (current != &start)
	{
		Node *prev = current;
		current = current->prev;
		delete prev;
	}
}
