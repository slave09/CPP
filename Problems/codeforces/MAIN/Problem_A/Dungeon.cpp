#include <bits/stdc++.h>
using namespace std;

int main (){
	int test_cases, a, b, c;
	cin >> test_cases;
	while(test_cases--){
		cin >> a >> b >> c;
		if((a + b + c) % 9 != 0)
			cout << "NO" << endl;
		else {
			int mini = min(a,b);
			mini = min(mini,c);
			if(mini >= (a+b+c) / 9) cout << "YES" << endl;
			else cout << "NO" << endl ;
		}
	}
	return 0;
}