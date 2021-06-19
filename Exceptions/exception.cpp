#include<iostream>
using namespace std;

int main(){
	try {
		int age = 15;
		if (age >= 18) {
			cout << "Access granted - you are old enough.";
		} else {
			throw (age);
		}
	}
	catch (int age) {
		cout << "Access denied - You must be at least 18 years old.\n";
		cout << "Age is: " << age << endl;
	}

	try{
		string name = "Nazra Aman";
		if(name == "Fakhra Najm")
			cout << "It's Me !";
		else throw(name);		
	}
	catch(string name){
		cout << "Its not me, it's " << name << endl;
	}



	try{
		string name = "Ajra Faham";
		if(name == "Fakhra Najm")
			cout << "It's Me !";
		else throw 400;		
	}
	catch(int error_code){
		cout << "Its not me" << endl;
		cout << "Error Code : " << error_code << endl;

	}


	try {
		int age = 15;
		if (age >= 18) {
			cout << "Access granted - you are old enough.";
		} else {
			throw 505;
		}
	}
	catch (...) { // three dots handle type of exception
		cout << "Access denied - You must be at least 18 years old.\n";
	}

	return 0;
}