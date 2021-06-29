#include<iostream>
using namespace std;
int members[5];
int main(){
	int groups,mem;
	cin >> groups;
	while(groups--){
		cin >> mem;
		members[mem]++;
	}
	members[1] = max(members[1] - members[3], 0);
	cout << members[3] + members[4] + (members[1] + 2 * members[2] + 3) / 4;
	return 0;
}

