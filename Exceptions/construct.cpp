#include<iostream>
using namespace std;

int main(){
	int age;
	cout << "Enter age : ";
	cin >> age;
	try{
		if(age < 18)
			throw 300;
		else cout << "Driving License Assigned" << endl;
	}
	catch(int err_code){
		cout << "Error Code : "<< err_code << endl;
		cout << "under age for a driving license !" << endl;
	}
	cout << "Finished !" << endl;
	return 0;
}