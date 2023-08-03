#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;

	int ans = 0;
	int begin = 0;
	int curr = 0;

	while(curr < str.size() - 1){
		if(str[curr] != str[curr + 1]){
			ans = max(ans, curr - begin + 1);
			begin = curr + 1;
		}
		curr++;
	}
	ans = max(ans, curr - begin + 1);
	cout << ans << endl;

	return 0;
}	