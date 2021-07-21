#include<iostream>
using namespace std;

int main(){
	string first, second;
	cin >> first >> second;
	for(int i = 0; i < first.length(); ++i){
		int res = (first[i] - 48) ^ (second[i] - 48);
		cout << res;
	}
	return 0;
}