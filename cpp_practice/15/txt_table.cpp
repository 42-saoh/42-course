#include <string>
#include <iostream>

using std::string;

class TxtTable : public Table
{
	private:
		string	repeat_char(int n, char c);
		string	col_num_to_str(int n);

	public:
		TxtTable(int row, int col);
		string	print_table(void);
};

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
				max_wide = date_table[j][i]->stringify().length();
		}
		col_max_wide[i] = max_wide;
	}
	total_table += "    ";
	int	total_wide = 4;
	for (int i = 0; i < max_col_size; i++)
	{
		if (col_max_wide[i])
		{
			int max_len = max(2, col_max_wide[i]);
			total_table += " | " + col_num_to_str(i);
			total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');
			total_wide += (max_len + 3);
		}
   	}
	total_table += "\n";
	for (int i = 0; i < max_row_size; i++)\
	{
		total_table += repeat_char(total_wide, '-');
		total_table += "\n" + to_string(i + 1);
		total_table += repeat_char(4 - to_string(i + 1).length(), ' ');
		for (int j = 0; j < max_col_size; j++)
		{
			if (col_max_wide[j])
			{
				int max_len = max(2, col_max_wide[j]);
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
