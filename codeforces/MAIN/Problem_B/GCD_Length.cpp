#include<iostream>
#include <math.h>
using namespace std;

void gcd_length(){
	int a, b, c, factora, factorb;
	cin >> a >> b >> c;

	int gcd = pow(10, c) + 1;
	if(a == c)
		factora = gcd;
	else
		factora = (pow(10, c - a) + 1) * gcd;
	
	if(b == a)
		factorb = 2 * factora;
	else if(b == c)
		factorb = gcd;
	else 
		factorb = (pow(10, c- b) + 1) * gcd;
	cout << factora << " " << factorb <<  endl;
}

int main(){
	int test_cases;
	cin >> test_cases;
	while(test_cases--)
		gcd_length();
	return 0;
} 