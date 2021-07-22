#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	
	ofstream Data("data.txt", ios :: trunc);
	Data << "Fakhra Najm";
	Data.close();
	
	string detail;

	string firstName;
	string secondName;

	ifstream myData("data.txt");

	myData >> firstName >> secondName;

	myData.close();

	cout << firstName << " " << secondName ;

	return 0;

}