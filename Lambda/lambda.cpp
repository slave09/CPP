#include<iostream>
using namespace std;

template<typename T>
void temp_function(T lambda){
	lambda();
}

int main(){
	int x = 10;
	int y = 20;

	[](){cout << "this is Lambda" << endl;}();

	int number = [](int x, int y)->int{return x + y;}(10, 20);
	cout << number << endl;
	
	auto func = []()->void{cout << "Auto declaration" << endl;};
	func();

	// [x,y](){x++;y--;}();
	// cout << "x : " << x << "\t" << "y : " << y << endl;
	// cannot modify read only variable

	[&x, &y](){x++;y--;}();
	cout << "x : " << x << "\t" << "y : " << y << endl;

	[&](){x++;y--;}();
	cout << "x : " << x << "\t" << "y : " << y << endl;

	auto lambda = [](){cout << "Passing as Parameter" << endl;};

	temp_function(lambda);

	return 0;
}