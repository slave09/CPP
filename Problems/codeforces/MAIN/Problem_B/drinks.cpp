#include<iostream>
using namespace std;

int main(){
	int total_drinks;
	cin >> total_drinks;
	double sum = 0;
	for(int i = 0; i < total_drinks; ++i){
		double val;
		cin >> val;
		sum += (val / 100);
	}
	sum = sum / total_drinks;
	cout << (sum * 100) ;
	return 0;
}