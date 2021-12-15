#include <string>

using std::string;

class Cell
{
	protected:
		int	x, y;
		Table	*table;
		string	data;

	public:
		virtual string stringify(void) = 0;
		virtual int to_numeric(void) = 0;
		Cell(string data, int x, int y, Table *table);
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
			stack.push(atoi(s.c_str()))
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

Cell::Cell(string data, int x, int y, Table *table)
	: x(x), y(y), table(table), data(data) {}

StringCell::StringCell(string data, int x, int y, Table* t)
    : data(data), Cell(x, y, t) {}

string StringCell::stringify(void)
{
	return (data);
}

int StringCell::to_numeric(void)
{
	return (0);
}

NumberCell::NumberCell(int data, int x, int y, Table* t)
    : data(data), Cell(x, y, t) {}

string NumberCell::stringify(void)
{
	return (to_string(data));
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
