#include <iostream>
using namespace std;

#define PI 3.14
#define max(x, y) (x > y ? x : y)
#define message(x) #x

#ifndef PI
	#define PI  3
#endif

int main(){

	cout << "PI : " << PI << endl;
	cout << "greater value : " << max(10 , 23) << endl;
	cout << message(Done) << endl;
	return 0;
}