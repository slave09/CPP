#include<iostream>
using namespace std;

class Base{
private:
	int x;
protected:
	int y;
public:
	int z;
	Base(){
		cout << "Base class invoked " << endl;
		x = 10;
		y = 20;
		z = 120;
	}

};

class Derived : public Base{
public:
	Derived(){
		cout << "Derived class invoked ";
		cout << "protected : y = " << y;
		cout << " && public : z = " << z << endl;
	};
};

int main(){
	Base base;
	cout << "public : z = " << base.z << endl;
	Derived derive;
	return 0;
}