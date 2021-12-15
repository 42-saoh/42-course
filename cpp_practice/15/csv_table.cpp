#include <string>

using std::string;

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
