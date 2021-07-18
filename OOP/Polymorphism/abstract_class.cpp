#include<iostream>
using namespace std;

class Abstract{
public:
	virtual void display() = 0;
};

class Derived : public Abstract{
public:
	void display(){
		cout << "Derived class Invoked" << endl;
	}
};

int main(){
	Abstract *abst;
	abst = new Derived;

	abst -> display();
	return 0;
}