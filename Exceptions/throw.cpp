/*
	* We can throw any data type as an exception 
	* we can throw user defined data type as well
	* There is a built in exception class in c++
	
	* we can also declare the type of exception int the function declaration:
			`return_type functionName(param1, param2,...)throw(data_type)`
	
	* If throw() is left empty in the declaration of function then that means that
		function is not throwing anything:
			`return_type functionName(param1, param2,...)throw()`
		* here function is not throwing anything
*/

#include <iostream>
using namespace std;

class MyException {
public:
	void message(){cout << "check your internet connection";}
};

int multiply(int a, int b)throw(){ // No exception is present in the function
	return a * b;
}

int divide(int num, int den){
	if(den == 0) throw string("Divided by zero ! ");
	else return num/den;
}

void display(string name){
	if(name == " ") {throw MyException();}
	else cout << "Hello " << name << "....!!!";
	cout << endl;
}

int main(){
	int num, den, a, b;
	string str;
	cout << "Enter numerator and denominator : " << endl;
	cin >> num >> den;

	try{
		int division = divide(num, den);
		cout << "Division result : " << division << endl;
	}
	catch(string error_message){
		cout << error_message << endl;
	}

	cout << "Enter a and b : " << endl;
	cin >> a >> b;
	cout << "Multiplication Result : " << a * b << endl;

	cout << "Enter your First Name : " << endl;
	cin >> str;

	try{
		display(str);
	}
	catch(MyException error){
		error.message();
	}
	return 0;
}