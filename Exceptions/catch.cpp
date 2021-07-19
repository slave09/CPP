/*
	* we can write multiple catch block for multiple throw
	* There is special catch block will catch all the left exceptions,
	   it is called catch all
	* Catch all block must be written in the last of all catch blocks
	* catch all block takes three dots as an argument
	* we can write nested try catch blocks
	* catch block for child class is written first in OOP
*/
#include<iostream>
using namespace std;

class MyException1 : exception{
public:
	void message(){
		cout << "MyException 1" << endl;
	}
};

class MyException2 : public MyException1{
public:
	void message(){
		// cout << "MyException 2" << endl;
	}
};

int main(){
	try{
		try{
			throw 'F';
		}
		catch(char error_code){
			cout << "ERROR CODE " << error_code << endl;
		}
		// throw 400;
		// throw MyException2();
		throw string("FAILED !");

	}
	catch(int error_code){
		cout << "ERROR CODE " << error_code << endl;
	}

	catch(MyException2 e){
		e.message();
	}

	catch(MyException1 e){
		e.message();
	}
	catch(...){
		cout << "Catch All ! " << endl;
	}
}