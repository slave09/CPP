#include<iostream>
using  namespace std;

float divide(float num, float den){
	if(den == 0) throw 0;
	else return num/den;
}

int main(){
	float num, den;
	cout << "Enter numerator : " << endl;
	cin >> num;

	cout << "Enter denominator : " << endl;
	cin >> den;

	try{
		float division = divide(num, den);
		cout << division << endl;
	}
	catch(int error_code){
		cout << "ERROR CODE : " << error_code << endl;
	}
	cout << "Finished" << endl;
	return 0;
}