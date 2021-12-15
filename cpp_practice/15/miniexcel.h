#ifndef MINIEXCEL_H
# define MINIEXCEL_H

# include <string>
# include <iostream>
# include <fstream>
# include <sys/time.h>
# include <unistd.h>

using std::string;

namespace	MiniExcel
{
	class Cell;

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

	class Table
	{
		protected:
			int		max_row_size, max_col_size;
			Cell	***data_table;

		public:
			Table(int max_row_size, int max_col_size);
			~Table(void);
			void	reg_cell(Cell *c, int row, int col);
			int		to_numeric(const string &s);
			int		to_numeric(int row, int col);
			string	stringify(const string &s);
			string	stringify(int row, int col);
			virtual	string print_table() = 0;
	};

	class TxtTable : public Table
	{
		private:
			string	repeat_char(int n, char c);
			string	col_num_to_str(int n);

		public:
			TxtTable(int row, int col);
			string	print_table(void);
	};

	class HtmlTable : public Table
	{
		public:
			HtmlTable(int row, int col);
			string print_table();
	};

	class CSVTable : public Table
	{
		public:
			CSVTable(int row, int col);
			string print_table();
	};

	class Cell
	{
		protected:
			int	x, y;
			Table	*table;

		public:
			virtual string stringify(void) = 0;
			virtual int to_numeric(void) = 0;
			Cell(int x, int y, Table *table);
	};

	class StringCell : public Cell
	{
		private:
			string data;

		public:
			string stringify(void);
			int to_numeric(void);
			StringCell(string data, int x, int y, Table* t);
	};

	class NumberCell : public Cell
	{
		private:
			int data;

		public:
			string stringify(void);
			int to_numeric(void);
			NumberCell(int data, int x, int y, Table* t);
	};

	class DateCell : public Cell
	{
		private:
			time_t data;

		public:
			string stringify(void);
			int to_numeric(void);
			DateCell(string s, int x, int y, Table* t);
	};

	class ExprCell : public Cell
	{
		private:
			string	data;
			string	*parsed_expr;
			Vector	exp_vec;
			int precedence(char c);
			void parse_expression(void);

		public:
			ExprCell(string data, int x, int y, Table* t);
			string stringify(void);
			int to_numeric(void);
	};

	class Excel
	{
		private:
			Table *current_table;

		public:
			Excel(int max_row, int max_col, int choice);
			int parse_user_input(string s);
			void command_line(void);
	};
}

#endif
