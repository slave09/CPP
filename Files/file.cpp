#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	
	ofstream Data("data.txt", ios :: trunc);
	Data << "Fakhra Najm";
	Data.close();
	
	string firstName;
	string secondName;

	// ifstream myData("data.txt");

	ifstream myData;

	myData.open("data.txt");

	if(myData.is_open()){
		
		myData >> firstName >> secondName;
		myData.close();

		cout << firstName << " " << secondName ;
	}

	return 0;

}