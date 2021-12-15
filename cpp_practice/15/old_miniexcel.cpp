#include <iostream>
#include <string>
#include <fstream>

using std::string;

class Cell;
class Table;
class TxtTable;

class Cell
{
	protected:
		int	x, y;
		Table	*table;
		string	data;

	public:
		virtual string stringify(void);
		virtual int to_numeric(void);
		Cell(string data, int x, int y, Table *table);
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

CSVTable::CSVTable(int row, int col) : Table(row, col) {}

string CSVTable::print_table()
{
	string s = "";

	for (int i = 0; i < max_row_size; i++)
	{
		for (int j = 0; j < max_col_size; j++)
		{
			if (j >= 1)
				s += ",";
			string temp;
			if (data_table[i][j])
				temp = data_table[i][j]->stringify();
			for (int k = 0; k < temp.length(); k++)
			{
				if (temp[k] == '"')
				{
					temp.insert(k, 1, '"');
					k++;
				}
			}
			temp = '"' + temp + '"';
			s += temp;
		}
		s += '\n';
	}
	return s;
}

HtmlTable::HtmlTable(int row, int col) : Table(row, col) {}

string HtmlTable::print_table()
{
	string s = "<table border='1' cellpadding='10'>";
	for (int i = 0; i < max_row_size; i++)
	{
		s += "<tr>";
		for (int j = 0; j < max_col_size; j++)
		{
			s += "<td>";
			if (data_table[i][j]) s += data_table[i][j]->stringify();
			s += "</td>";
		}
		s += "</tr>";
	}
	s += "</table>";
	return s;
}

TxtTable::TxtTable(int row, int col) : Table(row, col) {}

string	TxtTable::print_table(void)
{
	string	total_table;
	int		*col_max_wide = new int[max_col_size];

	for (int i = 0; i < max_col_size; i++)
	{
		unsigned int max_wide = 2;
		for (int j = 0; j < max_row_size; j++)
		{
			if (data_table[j][i] && data_table[j][i]->stringify().length() > max_wide)
				max_wide = data_table[j][i]->stringify().length();
		}
		col_max_wide[i] = max_wide;
	}
	total_table += "    ";
	int	total_wide = 4;
	for (int i = 0; i < max_col_size; i++)
	{
		if (col_max_wide[i])
		{
			int max_len = std::max(2, col_max_wide[i]);
			total_table += " | " + col_num_to_str(i);
			total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');
			total_wide += (max_len + 3);
		}
   	}
	total_table += "\n";
	for (int i = 0; i < max_row_size; i++)\
	{
		total_table += repeat_char(total_wide, '-');
		total_table += "\n" + std::to_string(i + 1);
		total_table += repeat_char(4 - std::to_string(i + 1).length(), ' ');
		for (int j = 0; j < max_col_size; j++)
		{
			if (col_max_wide[j])
			{
				int max_len = std::max(2, col_max_wide[j]);
				string s = "";
				if (data_table[i][j])
					s = data_table[i][j]->stringify();
				total_table += " | " + s;
				total_table += repeat_char(max_len - s.length(), ' ');
			}
		}
		total_table += "\n";
	}
	return (total_table);
}

string TxtTable::repeat_char(int n, char c)
{
	string s = "";

	for (int i = 0; i < n; i++)
		s.push_back(c);
	return (s);
}

string	TxtTable::col_num_to_str(int n)
{
	string s = "";

	if (n < 26)
		s.push_back('A' + n);
	else
	{
		char first = 'A' + n / 26 - 1;
		char second = 'A' + n / 26;
		s.push_back(first);
		s.push_back(second);
	}
	return (s);
}

Table::Table(int max_row_size, int max_col_size)
	: max_row_size(max_row_size), max_col_size(max_col_size)
{
	data_table = new Cell**[max_row_size];
	for (int i = 0; i < max_row_size; i++)
	{
		data_table[i] = new Cell*[max_col_size];
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

Cell::Cell(string data, int x, int y, Table *table)
	: x(x), y(y), table(table), data(data) {}

string Cell::stringify(void)
{
	return (data);
}

int	Cell::to_numeric(void)
{
	return (0);
}

int main()
{
	CSVTable table(5, 5);
	std::ofstream out("test.csv");

	table.reg_cell(new Cell("Hello~", 0, 0, &table), 0, 0);
	table.reg_cell(new Cell("C++", 0, 1, &table), 0, 1);
	table.reg_cell(new Cell("Programming", 1, 1, &table), 1, 1);
	out << table;

	HtmlTable table2(5, 5);
	std::ofstream out2("test.html");

	table2.reg_cell(new Cell("Hello~", 0, 0, &table), 0, 0);
	table2.reg_cell(new Cell("C++", 0, 1, &table), 0, 1);
	table2.reg_cell(new Cell("Programming", 1, 1, &table), 1, 1);
	out2 << table2;
}
