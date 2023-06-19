/*
Given:

  A set of non negative integers.
  A target value (integer).

Objective:

  Determine whether there exists a subset of the given integers whose sum is equal to the target value.

Constraints:

  You can either include or exclude each integer from the given set.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>>dp(1000, vector<bool>(1000, false));


// Recursive Solution
// Considering negative values
bool isSubsetSum(vector<int>&arr, int sum, int size){
	if(size <= 0 || sum == 0) return sum == 0 ? true : false;
	if(sum >= 0 && dp[size][sum]) return true;
	return dp[size][sum] = isSubsetSum(arr, sum - arr[size - 1], size - 1) || isSubsetSum(arr, sum, size - 1);
}

// Iterative
bool isSubsetSum(vector<int>&arr, int sum){

	for(int index = 0; index < arr.size() + 1; ++index) dp[index][0] = true;

	for(int size = 1; size < arr.size() + 1; ++size){
		for(int currSum = 1; currSum < sum + 1; ++currSum){
			if(arr[size - 1] > sum) dp[size][currSum] = dp[size - 1][currSum];
			else dp[size][currSum] = dp[size - 1][currSum] || dp[size - 1][currSum - arr[size - 1]];
		}
	}
	return dp[arr.size()][sum];
}

int main(){
	vector<int>arr= {0,4,6,-1,2};
	int sum;
	while(true){
		cout << "Enter Sum or Enter CTRL ^ C to exit : ";
		cin >> sum;
		if(isSubsetSum(arr, sum, 5)) cout << "Subset Found" << endl;
		else cout << "Subset Not Found !" << endl;
	}
	return 0;
}