/*
	* finding the number of subsets of a given set that add up to a specified target sum
	* Constraints : integers are positive
*/

#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>&arr, int sum){
	vector<vector<int>>dp(arr.size() + 1, vector<int>(sum + 1, 0));
	for(int index = 0; index < arr.size() + 1; ++index) dp[index][0] = 1;
	for(int row = 1; row <= arr.size(); ++row){
		for(int col = 1; col < sum + 1; ++col){
			if(arr[row - 1] <= col) dp[row][col] = dp[row - 1][col] + dp[row - 1][col - arr[row - 1]];
			else dp[row][col] = dp[row - 1][col];
		}
	}
	return dp[arr.size()][sum];
}

int main(){
	vector<int>arr= {2,3,5,6,8,10};
	int sum;
	while(true){
		cout << "Enter Sum or Enter CTRL ^ C to exit : ";
		cin >> sum;
		cout << "No of subsets : " << countSubsets(arr, sum) << endl;
	}
	return 0;
}