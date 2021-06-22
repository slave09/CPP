#include<iostream>
using namespace std;

int main(){
	int no_of_people;
	cin >> no_of_people;

	int sum = 0;

	while(no_of_people--){
		int response;
		cin >> response;
		sum += response;
	}

	sum == 0 ? cout << "EASY" : cout << "HARD" << endl;
 	return 0;
}