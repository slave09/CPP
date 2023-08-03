#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>nums(n + 1, 0);
	while(n-- >= 1){
		int val;
		cin >> val;
		nums[val] = val;
	} 

	for(int index = 1; index < nums.size(); ++index){
		// cout << index << " " << nums[index] << endl;
		if(nums[index] != index) cout << index << endl;
	}
	return 0;
}