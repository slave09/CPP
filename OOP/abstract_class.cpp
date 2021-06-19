#include<iostream>
using namespace std;

class Abstract{ // abstract class : contains atleast one pure virtual function
public:
	virtual void get_work() = 0; // pure virtual function initialized with value zero.
};

class Derived : Abstract{ // derived class of abstract class.
public:										// Must have simple implementation of pure virtual function here
	void get_data(){
		cout << "No Data Available";
	}
	void get_work(){
		cout << "I am unemployed" << endl;
	}
};

int main(){
	Derived derived;
	derived.get_work();
	derived.get_data();
	return 0;
}