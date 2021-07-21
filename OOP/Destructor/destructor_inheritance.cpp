#include<iostream>
using namespace std;

class Base {
public:
	Base(){
		cout << "Base Class Constructor " << endl;
	}

	virtual ~Base(){ // so that during runtime polymorphism all the destructors are called
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

void function(){
	Base *ptr = new Derived();
	delete ptr;
}

int main(){
	Derived d;	
	function();	
	return 0;
}