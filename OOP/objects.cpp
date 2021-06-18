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

int main(){
	Person first;
	first.name = "Fakhra Najm";
	first.age = 20;
	first.email = "fnajm09@gmail.com";
	first.read_details();
	return 0;
}