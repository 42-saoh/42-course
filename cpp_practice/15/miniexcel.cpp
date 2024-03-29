#include "miniexcel.h"

namespace MiniExcel
{
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

	int	ExprCell::to_numeric(void)
	{
		double result = 0;
		NumStack stack;

		for (int i = 0; i < exp_vec.size(); i++)
		{
			string s = exp_vec[i];
			if (isalpha(s[0]))
				stack.push(table->to_numeric(s));
			else if (isdigit(s[0]))
				stack.push(atoi(s.c_str()));
			else
			{
				double y = stack.pop();
				double x = stack.pop();
				if (s[0])
				{
					if (s[0] == '+')
						stack.push(x + y);
					else if (s[0] == '-')
						stack.push(x - y);
					else if (s[0] == '*')
						stack.push(x * y);
					else if (s[0] == '/')
						stack.push(x / y);
				}
			}
		}
		return (stack.pop());
	}

	int	ExprCell::precedence(char c)
	{
		if (!c)
			return (0);
		else if (c == '(' || c == '[' || c == '{')
			return (0);
		else if (c == '+' || c == '-')
			return (1);
		else if (c == '*' || c == '/')
			return (2);
		return (0);
	}

	void ExprCell::parse_expression(void)
	{
		Stack stack;

		data.insert(0, "(");
		data.push_back(')');
		for (int i = 0; i < data.length(); i++)
		{
			if (isalpha(data[i]))
			{
				exp_vec.push_back(data.substr(i, 2));
				i++;
			}
			else if (isdigit(data[i]))
				exp_vec.push_back(data.substr(i, 1));
			else if (data[i] == '(' || data[i] == '[' || data[i] == '{')
				stack.push(data.substr(i, 1));
			else if (data[i] == ')' || data[i] == ']' || data[i] == '}')
			{
				string t = stack.pop();
				while (t != "(" && t != "[" && t != "{")
				{
					exp_vec.push_back(t);
					t = stack.pop();
				}
			}
			else if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/')
			{
				while (!stack.is_empty() && precedence(stack.peek()[0]) >= precedence(data[i]))
					exp_vec.push_back(stack.pop());
				stack.push(data.substr(i, 1));
			}
		}
	}

	Cell::Cell(int x, int y, Table *table)
		: x(x), y(y), table(table) {}

	StringCell::StringCell(string data, int x, int y, Table* t)
		: Cell(x, y, t), data(data) {}

	string StringCell::stringify(void)
	{
		return (data);
	}

	int StringCell::to_numeric(void)
	{
		return (0);
	}

	NumberCell::NumberCell(int data, int x, int y, Table* t)
		: Cell(x, y, t), data(data) {}

	string NumberCell::stringify(void)
	{
		return (std::to_string(data));
	}

	int NumberCell::to_numeric(void)
	{
		return (data);
	}

	string DateCell::stringify(void)
	{
		char buf[50];
		tm temp;
		localtime_s(&temp, &data);

		strftime(buf, 50, "%F", &temp);
		return string(buf);
	}

	int DateCell::to_numeric(void)
	{
		return (static_cast<int>(data));
	}

	DateCell::DateCell(string s, int x, int y, Table* t) : Cell(x, y, t)
	{
		int year = atoi(s.c_str());
		int month = atoi(s.c_str() + 5);
		int day = atoi(s.c_str() + 8);
		tm timeinfo;

		timeinfo.tm_year = year - 1900;
		timeinfo.tm_mon = month - 1;
		timeinfo.tm_mday = day;
		timeinfo.tm_hour = 0;
		timeinfo.tm_min = 0;
		timeinfo.tm_sec = 0;
		data = mktime(&timeinfo);
	}
}
