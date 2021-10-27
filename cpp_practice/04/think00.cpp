#include <iostream>

class Date {
	private:
		int year;
		int month;
		int day;

	public:
		void set_date(int _year, int _month, int _date)
		{
			year = _year;
			month = _month;
			day = _date;
		}
		void add_day(int inc_date)
		{
			day += inc_date;
			if ((month < 8 && month % 2) || (month >= 8 && month % 2 == 0))
			{
				if (day > 31)
				{
					day -= 31;
					add_month(1);
				}
			}
			else if (month == 2)
			{
				if (day > 28)
				{
					day -= 28;
					add_month(1);
				}
			}
			else
			{
				if (day > 30)
				{
					day -= 30;
					add_month(1);
				}
			}
		}
		void add_month(int inc_month)
		{
			month += inc_month;
			if (month > 12)
			{
				month -= 1;
				add_year(1);
			}
		}
		void add_year(int inc_year)
		{
			day += inc_year;
		}

		void show_date(void)
		{
			std::cout << "year : " << year << std::endl;
			std::cout << "month : " << month << std::endl;
			std::cout << "day : " << day << std::endl;
		}
};

int main()
{
	Date date;
	date.set_date(2000, 10, 5);
	date.add_day(30);

	date.show_date();
	return (0);
}
