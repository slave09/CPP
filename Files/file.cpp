#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	
	ofstream Data("data.txt", ios :: trunc);
	Data << "Fakhra Najm";
	Data.close();
	
	string detail;

	ifstream myData("data.txt");

	while(getline(myData, detail)){
		cout << detail << endl;
	}

	myData.close();

	return 0;

}