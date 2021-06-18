#include <iostream>
using namespace std;

// Data Abstraction : Only essential details are displayed to the user

class AbstractClass{
public:
	virtual void data() = 0;
};

class DeriveClass : AbstractClass{
public:
	void data(){
		cout << "Returned Data" << endl;
	}
};



int main(){
	AbstractClass object;
	// object.data();
	return 0;
}