/*
	Topic : inclass initialization and delegation of constructor
	* delegation : any constructor can call another constructor of the same class
*/

#include <iostream>
using	namespace std;
class Test{
	// inclass initialization
	int a = 0; 
	int b = 0;
public:
	Test(int a , int b){
		this -> a = a;
		this -> b = b;
	}
	Test() : Test(1,1){} // delegation of constructors

	void Display(){
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}
};

int main(){
	Test test;
	test.Display();
	return 0;
}