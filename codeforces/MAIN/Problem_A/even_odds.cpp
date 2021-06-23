#include<iostream>
using namespace std;

int main(){
	
	long long n, k;
	cin >> n >> k;

	long long floor_value = (n/2) + (n % 2);

	if(floor_value >= k)
		cout <<  ((2 * k ) - 1) << endl;

	else cout << 2 * (k - floor_value) << endl;

	return 0;
}