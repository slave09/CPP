#include<iostream>
using namespace std;

int main(){
	int number_of_magnets ;
	cin >> number_of_magnets;

	string last_combination = "";
	int groups = 0q;

	while(number_of_magnets--){
		string present_combination;
		cin >> present_combination;
		if(present_combination != last_combination)
			groups++;
		last_combination = present_combination;
	}

	cout << groups;

	return 0;
}