#include "utils.h"

namespace Miniexcel
{
	Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}

	void	Vector::push_back(string s)
	{
		if (capacity <= length)
		{
			string *temp = new string[capacity * 2];
			for (int i = 0; i < length; i++)
				temp[i] = data[i];
			delete[] data;
			data = temp;
			capacity *= 2;
		}
		data[length++] = s;
	}

	string	Vector::operator[](int i)
	{
		return (data[i]);
	}

	void	Vector::remove(int x)
	{
		for (int i = x + 1; i < length; i++)
			data[i - 1] = data[i];
		length--;
	}

	int	Vector::size(void)
	{
		return (length);
	}

	Vector::~Vector(void)
	{
		if (data)
			delete[] data;
	}

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
		return (s);
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

	NumStack::NumStack() : start(NULL, 0)
	{
		current = &start;
	}

	void NumStack::push(double s)
	{
		Node* n = new Node(current, s);
		current = n;
	}

	double NumStack::pop()
	{
		if (current == &start)
			return (0);
		double s = current->s;
		Node* prev = current;
		current = current->prev;
		delete prev;
		return (s);
	}

	double NumStack::peek()
	{
		return (current->s);
	}

	bool NumStack::is_empty()
	{
		if (current == &start)
			return (true);
		return (false);
	}

	NumStack::~NumStack()
	{
		while (current != &start)
		{
			Node* prev = current;
			current = current->prev;
			delete prev;
		}
	}
}
