#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long ans = 0;
	long long last = -1;
	while(n--){
		long long curr;
		cin >> curr;
		if(curr < last){
			ans += (last - curr);
			curr = last;
		}
		last = curr;
	}
	cout << ans << endl;
	return 0;
}

// 3 1 4 2 