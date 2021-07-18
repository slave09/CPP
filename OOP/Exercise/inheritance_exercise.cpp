#include<iostream>
using namespace std;

class Employee{
	int employee_id;
protected:
	string employee_name;
	Employee();
	Employee(string employee_name, int employee_id);
	Employee(Employee &employee);
	string getEmployeeName(){return employee_name;}
	int getEmployeeId(){return employee_id;}
	void setEmployeeName(string employee_name){this -> employee_name = employee_name;}
	void setEmployeeId(int employee_id){this -> employee_id = employee_id;}
	~Employee(){}
};

class FullTimeEmployee : public Employee{
	int employee_sallary;
public:
	FullTimeEmployee();
	FullTimeEmployee(string employee_name, int employee_id, int employee_sallary);
	FullTimeEmployee(FullTimeEmployee &employee);
	string getFullTimeEmployeeName(){return getEmployeeName();}
	int getFullTimeEmployeeSallary(){return employee_sallary;}
	int getFullTimeEmployeeId(){return getEmployeeId();}
	void setFullTimeEmployeeName(string employee_name);
	void setFullTimeEmployeeSallary(int employee_sallary);
	void setFullTimeEmployeeId(int employee_id);
	~FullTimeEmployee(){}
};

class PartTimeEmployee : public Employee{
	int employee_wage;
public:
	PartTimeEmployee();
	PartTimeEmployee(string employee_name, int employee_id, int employee_wage);
	PartTimeEmployee(PartTimeEmployee &part_time_employee);
	string getPartTimeEmployeeName(){return getEmployeeName();}
	int getPartTimeEmployeeWage(){return employee_wage;}
	int getPartTimeEmployeeId(){return getEmployeeId();}
	void setPartTimeEmployeeName(string employee_name);
	void setPartTimeEmployeeWage(int employee_wage);
	void setPartTimeEmployeeId(int employee_id);
	~PartTimeEmployee(){}
};

int main(){
	PartTimeEmployee part_time_employee("Fakhra", 27, 50000);
	FullTimeEmployee full_time_employee("Tahera", 19, 80000);

	cout << "Name : " << full_time_employee.getFullTimeEmployeeName() << "\t";
	cout << "Id : " << full_time_employee.getFullTimeEmployeeId() << "\t";
	cout << "Sallary : " << full_time_employee.getFullTimeEmployeeSallary() << endl;

	cout << "Name : " << part_time_employee.getPartTimeEmployeeName() << "\t";
	cout << "Id : " << part_time_employee.getPartTimeEmployeeId() << "\t";
	cout << "Wage : " << part_time_employee.getPartTimeEmployeeWage() << endl;

	return 0;
}

PartTimeEmployee :: PartTimeEmployee() : Employee(){
	cout << "PLEASE PROVIDE PART TIME EMPLOYEE DETAILS ! " << endl;	
}

PartTimeEmployee :: PartTimeEmployee(string employee_name, int employee_id, int employee_wage)
:Employee(employee_name, employee_id)
{
	setPartTimeEmployeeWage(employee_wage);
}

PartTimeEmployee :: PartTimeEmployee(PartTimeEmployee &employee)
:Employee(employee){
	setPartTimeEmployeeWage(employee.employee_wage);
}

void PartTimeEmployee :: setPartTimeEmployeeName(string employee_name){
	setEmployeeName(employee_name);
}

void PartTimeEmployee :: setPartTimeEmployeeWage(int wage){
	this -> employee_wage = employee_wage;
}
void PartTimeEmployee :: setPartTimeEmployeeId(int employee_id){
	setEmployeeId(employee_id);
}

Employee :: Employee(){
	setEmployeeName("none");
	setEmployeeId(0);
	cout << "PLEASE PROVIDE EMPLOYEE DETAILS ! " << endl;	
}

Employee :: Employee(string employee_name, int employee_id){
	setEmployeeName(employee_name);
	setEmployeeId(employee_id);
}

Employee :: Employee(Employee &employee){
	setEmployeeName(employee.employee_name);
	setEmployeeId(employee.employee_id);
}


FullTimeEmployee :: FullTimeEmployee()
: Employee()
{
	setFullTimeEmployeeSallary(0);
	cout << "PLEASE PROVIDE FULL TIME EMPLOYEE DETAILS ! " << endl;	
}

FullTimeEmployee :: FullTimeEmployee(string employee_name, int employee_id, int employee_sallary)
: Employee(employee_name, employee_id)
{
	setFullTimeEmployeeSallary(employee_sallary);
}

FullTimeEmployee :: FullTimeEmployee(FullTimeEmployee &employee)
:Employee(employee)
{
	setFullTimeEmployeeSallary(employee.employee_sallary);
}

void FullTimeEmployee :: setFullTimeEmployeeName(string employee_name){
	setEmployeeName(employee_name);
}
void FullTimeEmployee :: setFullTimeEmployeeSallary(int employee_sallary){
	this -> employee_sallary = employee_sallary;
}
void FullTimeEmployee :: setFullTimeEmployeeId(int employee_id){
	setEmployeeId(employee_id);
}
