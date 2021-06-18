#include<iostream>
using namespace std;

class Person {
public:
	string name;
	int age;
	string email;

	void read_details(){
		cout << "Name - " << name << endl;
		cout << "Age - " << age << endl;
		cout << "Email - " << email <<endl;
	}
};

Person modify_details(Person p){
	p.name = "Nazra Aman";
	p.email = "amannazra01@gmail.com";
	p.age = p.age - 1;
	return p;
}

int main(){
	Person first;
	first.name = "Fakhra Najm";
	first.age = 20;
	first.email = "fnajm09@gmail.com";
	first.read_details();
	Person modified = modify_details(first);
	cout << "Name - " << modified.name << endl;
	cout << "Email - " << modified.email << endl;
	cout << "Age - " << modified.age << endl;
	return 0;
}