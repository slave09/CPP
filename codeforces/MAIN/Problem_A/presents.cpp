#include<bits/stdc++.h>
using namespace std;

int main(){
	int number_of_friends;
	cin >> number_of_friends;
	map<int,int>indices;

	int i = 1;

	while(number_of_friends--){
		int val;
		cin >> val;
		indices[val] = i++;
	}

	for(int i = 1; i <= indices.size(); ++i){
		cout << indices[i] << " ";
	}
	return 0;
}