#include <string>
#include <iostream>

using std::string;

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

Table::Table(int max_row_size, int max_col_size)
	: max_row_size(max_row_size), max_col_size(max_col_size)
{
	data_table = new Cell**[max_row_size];
	for (int i = 0; i < max_row_size; i++)
	{
		data_table = new Cell*[max_col_size];
		for (int j = 0; j < max_col_size; j++)
			data_table[i][j] = NULL;
	}
}

Table::~Table(void)
{
	for (int i = 0; i < max_row_size; i++)
	{
		for (int j = 0; j < max_col_size; j++)
		{
			if (data_table[i][j])
				delete data_table[i][j];
		}
		delete[] data_table[i];
	}
	delete[] data_table;
}

void	Table::reg_cell(Cell *c, int row, int col)
{
	if (!(row < max_row_size && col < max_col_size))
		return ;
	if (data_table[row][col])
		delete data_table[row][col];
	data_table[row][col] = c;

}

int	Table::to_numeric(const string &s)
{
	int	col = s[0] - 'A';
	int	row = atoi(s.c_str() + 1) - 1;

	if (row < max_row_size && col < max_col_size)
	{
		if (data_table[row][col])
			return (data_table[row][col]->to_numeric());
	}
	return (0);
}

int	Table::to_numeric(int row, int col)
{
	if (row < max_row_size && col < max_col_size)
	{
		if (data_table[row][col])
			return (data_table[row][col]->to_numeric());
	}
	return (0);
}

string Table::stringify(const string &s)
{
	int col = s[0] - 'A';
	int row = atoi(s.c_str() + 1) - 1;

	if (row < max_row_size && col < max_col_size)
	{
		if (data_table[row][col])
			return data_table[row][col]->stringify();
	}
	return ("");
}

string	Table::stringify(int row, int col)
{
	if (row < max_row_size && col < max_col_size)
	{
		if (data_table[row][col])
			return data_table[row][col]->stringify();
	}
	return ("");
}

std::ostream &operator<<(std::ostream &o, Table &table)
{
	o << table.print_table();
	return (o);
}
