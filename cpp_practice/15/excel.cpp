#include <string>

using std::string;

class Excel
{
	private:
		Table *current_table;

	public:
		Excel(int max_row, int max_col, int choice);
		int parse_user_input(string s);
		void command_line(void);
};

Excel::Excel(int max_row, int max_col, int choice = 0)
{
	if (choice == 0)
      current_table = new TxtTable(max_row, max_col);
	else if (choice ==  1)
      current_table = new CSVTable(max_row, max_col);
	else
      current_table = new HtmlTable(max_row, max_col);
}

int Excel::parse_user_input(string s)
{
	int next = 0;
	string command = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			command = s.substr(0, i);
			next = i + 1;
			break ;
		}
		else if (i == s.length() - 1)
		{
			command = s.substr(0, i + 1);
			next = i + 1;
			break ;
		}
	}
	string to = "";
	for (int i = next; i < s.length(); i++)
	{
		if (s[i] == ' ' || i == s.length() - 1)
		{
			to = s.substr(next, i - next);
			next = i + 1;
			break ;
		}
		else if (i == s.length() - 1)
		{
			to = s.substr(0, i + 1);
			next = i + 1;
			break ;
		}
	}
	int col = to[0] - 'A';
	int row = atoi(to.c_str() + 1) - 1;
	string rest = s.substr(next);

	if (command == "sets")
		current_table->reg_cell(new StringCell(rest, row, col, current_table), row, col);
	else if (command == "setn") 
		current_table->reg_cell(new NumberCell(atoi(rest.c_str()), row, col, current_table), row, col);
	else if (command == "setd")
		current_table->reg_cell(new DateCell(rest, row, col, current_table), row, col);
	else if (command == "sete")
		current_table->reg_cell(new ExprCell(rest, row, col, current_table), row, col);
	else if (command == "out")
	{
		ofstream out(to);
		out << *current_table;
		std::cout << to << " 에 내용이 저장되었습니다" << std::endl;
	}
	else if (command == "exit")
		return 0;
	return 1;
}

void Excel::command_line()
{
	string s;
	std::getline(cin, s);

	while (parse_user_input(s))
	{
		std::cout << *current_table << std::endl << ">> ";
		getline(cin, s);
	}
}
