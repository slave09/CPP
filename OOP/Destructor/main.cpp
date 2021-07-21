/*
	Topic : Destructor
	* called automatically when object is destroyed
	* releases all the external resources like heap, files etc ..
	* when the class is accessing external resources then we must release those resources inside destructor otherwise memory leake issue will be there  
	* when we are creating a pointer to a class then we must use delete operator to call destructor otherwise destructor will not be called.
	* cannot be overloaded
*/

#include<iostream>
using namespace std;

class Demo{
	int *arr;
public: 
	Demo(){
		cout << "Constructor is invoked " << endl;
		arr = new int[10]; // must be deleted inside destructor 
	}
	~Demo(){
		cout << "Destructor is invoked " << endl;	// will called automatically after the class is used
	}
};

void function(){
	Demo * ptr = new Demo() ;
	delete ptr; // this will call destructor
}

int main(){
	Demo demo;
	function();
	return 0;
}