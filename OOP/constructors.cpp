#include<iostream>
using namespace std;

class Const{

	// Encapsulation : bundling class methods and data of a class.
	// Encapsulation restricts outsiders to interact and modify classes.

	string name;
	string institution;
	string Department;
	string about;

	public : 

	// We can create as many constructors as wanted
	// class supports constructor overloading

		Const(string name, string institution, string Department, string about){
			this -> name = name;
			this -> institution = institution;
			this -> Department = Department ;
			this -> about = about;
		}

		Const(){
			cout << "You invoked a class in cpp" << endl;
		}

		void get_data(){
			cout << name << endl;
			cout << institution << endl;
			cout << Department << endl;
			cout << about << endl;
		}
};

int main()
{
	string name = "Fakhra Najm";
	string institution = "Jamia Millia Islamia";
	string Department = "Electrical Engineering";
	string about = "Programmer";
	Const person = Const(name, institution, Department, about);
	Const People;
	person.get_data();
	return 0;
}