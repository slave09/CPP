#include <iostream>
using namespace std;

class Base_class{
private : 
	string name;
	int age;
public :

	Base_class(string name, int age){
		this -> name = name;
		this -> age = age;
	}

	void getName(){
		cout << name << endl;
	}

};

class Derived_class : public Base_class{
public:
	Derived_class(string name, int age): Base_class(name, age){}
};

int main(){
	Derived_class child = Derived_class("Fakhra", 19);
	child.getName();
	return 0;
}