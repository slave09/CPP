#include<iostream>
using namespace std;

class Base{
public:
	void Display(){cout << "Base class Display" << endl;}
};

class Derived : public Base{
public:
	void Display(){cout << "Derived class Display" << endl;}
};

int main(){
	Base base;
	Derived derive;
	base.Display();
	derive.Display();
	derive.Base::Display();
	return 0;
}