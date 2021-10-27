#include <iostream>
#include <string>

class Employee;
class Employee_lst;
class Manager;

class Employee
{
	protected:
		std::string	name;
		int			age;
		std::string	position;
		int			rank;

	public:
		Employee(std::string name, int age, std::string position, int rank)
			: name(name), age(age), position(position), rank(rank) {}
		Employee(const Employee &em)
			: name(em.name), age(em.age), position(em.position), rank(em.rank) {}
		Employee() {}
		virtual void print_info() {
			std::cout << name << "(" << position << ", " << age << ") ==> " \
				<< calculate_pay() << "만원" << std::endl;
		}
		virtual int calculate_pay() { return (200 + rank * 50); }
};

class Manager : public Employee
{
	private:
		int			year_of_service;

	public:
		Manager(std::string name, int age, std::string position, int rank, int year_of_service)
			  : Employee(name, age, position, rank), year_of_service(year_of_service) {}
		Manager(const Manager &ma)
			: Employee(ma.name, ma.age, ma.position, ma.rank), \
			  year_of_service(ma.year_of_service) {}
		Manager() : Employee() {}
		int calculate_pay() override { return (200 + rank * 50 + 5 * year_of_service) ;}
		void print_info() override {
			std::cout << name << "(" << position << ", " << age << ", " << \
				year_of_service << "년차) ==> " << calculate_pay() << "만원" << std::endl;
		}
};

class Employee_lst
{
	private:
		int			alloc_employee;
		int			current_employee;
		Employee	**employee_lst;

	public:
		Employee_lst(int _alloc_employee) : alloc_employee(_alloc_employee)
		{
			employee_lst = new Employee*[alloc_employee];
			current_employee = 0;
		}
		void add_employee(Employee *employee)
		{
			employee_lst[current_employee] = employee;
			current_employee++;
		}
		int current_employee_num() { return (current_employee); }
		void printf_employee_info()
		{
			int total_pay = 0;
			for (int i = 0; i < current_employee; i++)
			{
				employee_lst[i]->print_info();
				total_pay += employee_lst[i]->calculate_pay();
			}
			std::cout << "총 비용 : " << total_pay << std::endl;
		}
		~Employee_lst()
		{
			for (int i = 0; i < current_employee; i++)
				delete employee_lst[i];
			delete[] employee_lst;
		}
};

int main()
{
	Employee_lst emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
	emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.printf_employee_info();
}
