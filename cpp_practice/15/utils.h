#ifndef UTILS_CPP
# define UTILS_CPP

#include <string>

using std::string;

namespace	Miniexcel
{
	class Vector
	{
		private:
			string	*data;
			int		capacity;
			int		length;

		public:
			Vector(int n = 1);
			void	push_back(string s);
			string	operator[](int i);
			void	remove(int x);
			int		size(void);
			~Vector(void);
	};

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

	class NumStack
	{
		private:
			struct Node
			{
				Node* prev;
				double s;

				Node(Node* prev, double s) : prev(prev), s(s) {}
			};
			Node* current;
			Node start;

		public:
			NumStack();
			void push(double s);
			double pop();
			double peek();
			bool is_empty();
			~NumStack();
	};
}

#endif
