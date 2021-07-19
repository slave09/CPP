#include <iostream>
using namespace std;

template <class T>
T Max(T a, T b){
	return a > b ? a : b;
}

int main(){

	int a = Max(3, 4);
	double b = Max(4.5, 6.8);

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	return 0;
}