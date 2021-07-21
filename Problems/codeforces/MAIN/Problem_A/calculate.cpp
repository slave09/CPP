#include<iostream>

int main(){
	long long range ;
	std :: cin >> range;
	std :: cout << (range / 2)*(1 + range / 2) - (range - range/2)*(range - range/2);
	return 0;
}