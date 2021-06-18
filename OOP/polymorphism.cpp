#include<iostream>
using namespace std;

class Employee{
	string name;
	string email;
protected:
	string company;
public:
	Employee(string name, string email, string company){
		this -> name = name;
		this -> email = email;
		this -> company = company;
	}

	virtual void get_company(){
		cout << company << endl;
	}
};

class Developer : Employee {
public:
	Developer(string name, string email, string company)
	:Employee(name, email, company){}
	void get_company(){
		cout << company << endl;
	}
	void get_work(){
		cout << "SDE 1 in " << company << endl;
	}
};

class Intern : Employee {
public:
	Intern(string name, string email, string company)
	:Employee(name, email, company){}
	void get_company(){
		cout << company << endl;
	}
	void get_work(){
		cout << "Ui intern in " << company << endl;
	}
};


int main(){
	Developer dev = Developer("Sharique Shahab", "shariqueshaba@gmial.com", 
		"Amazon");
	Intern UIintern = Intern("Tahera Saman", "tahera.saman@payu.in", "Payu");
	dev.get_company();
	UIintern.get_company();
	dev.get_work();
	UIintern.get_work();
	return 0;
}