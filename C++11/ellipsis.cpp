/*
	Topic : Ellipsis
	* Used to pass variarable number of arguments t oa function
*/

#include<iostream>
#include <cstdarg>

using namespace std;

int sum(int n, ...){
	va_list list; // object created 
	va_start(list, n); // access all arguments in list

	int sum = 0;
	int x;

	for(int i = 0; i < n; ++i){
		x = va_arg(list, int ); // retreiving value and adding
		sum += x;
	}

	return sum;
}

int main(){

	cout << sum(5, 1,2,3,4,5) << endl;
	cout << sum(8, 1,2,3,4,5,6,7,8) << endl;

	return 0;
}