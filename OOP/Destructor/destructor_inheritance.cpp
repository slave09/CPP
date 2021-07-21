#include<iostream>
using namespace std;

class Base {
public:
	Base(){
		cout << "Base Class Constructor " << endl;
	}

	~Base(){
		cout << "Base class Destructor " << endl;
	}

};

class Derived : public Base{
public:
		Derived(){
		cout << "Derived Class Constructor " << endl;
	}

	~Derived(){
		cout << "Derived class Destructor " << endl;
	}
};

int main(){
	Derived d;	
	return 0;
}