#include <iostream>
using namespace std;

class Base{
	int base;

public:
	Base();
	Base(int Base);
};

Base :: Base(){
	cout << "Base class invoked !" << endl;
}

Base :: Base(int base){
	this -> base = base;
	cout << "Base class parameter : " << this -> base << endl;
}

class Derived : public Base{
	int derive;
public: 

	Derived();
	Derived(int derive);
	Derived(int derive, int base);
};

Derived :: Derived(){
	cout << "Derived class invoked" << endl;
}

Derived :: Derived(int derive){
	this -> derive = derive;
	cout << "Derived class parameter : " << this -> derive << endl;
}

Derived :: Derived(int derive, int base) : Base(base){
		this -> derive  = derive;
		cout << "Derived class constructor called with value " << derive << endl;
	}

int main(){

	Derived drived;

	Derived derived2(5);

	Derived derived3(5, 10);
	return 0;
}