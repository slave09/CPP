#include<iostream>
#include<sstream>
using namespace std;

int main(){

	// int manipulators
	cout << "234 in decimal : " << dec << 234 << endl; 
	cout << "234 in hexadecimal : " << hex << 234 << endl;
	cout << "234 in octal : " << oct << 234 << endl;

	//float manipulators
	cout << "Fixed : " << fixed << 1.345 << endl;
	cout << "Scientific : " << scientific << 1.345 << endl;

	return 0;
}