
/*
Given:

  - A set of items, each with a weight and a value.
  - The maximum weight capacity of the knapsack.

Objective:

  - Select a subset of items to maximize the total value while ensuring that the total weight does not exceed the capacity of the knapsack.

Constraints:

  - Each item can be either included (1) or not included (0) in the knapsack (hence the name "0/1" problem).
  - The total weight of the selected items cannot exceed the knapsack's capacity.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp(102, vector<int>(1002, -1));

// Recursion + Memoization => top down
int getKnapsackProfit(vector<int>&weights, vector<int>&profits, int capacity, int size){
	if(size == 0 || capacity == 0) return 0;
	if(dp[size][capacity] != -1) return dp[size][capacity];
	if(weights[size - 1] <= capacity){
		return dp[size][capacity] = max(profits[size - 1] + getKnapsackProfit(weights, profits, capacity - weights[size - 1], size  - 1),getKnapsackProfit(weights, profits, capacity, size - 1));
	}
	return dp[size][capacity] = getKnapsackProfit(weights, profits, capacity, size - 1);
}

// Iterative => Bottom up
int getKnapsackProfit(vector<int>&weights, vector<int>&profits, int capacity){
	if(capacity == 0 || weights.size() == 0) return 0;
	vector<vector<int>>dp(weights.size() + 1, vector<int>(capacity + 1, 0));
	for(int size = 1; size < profits.size() + 1; ++size){
		for(int weight = 1; weight < capacity + 1; ++weight){
			if(weights[size - 1] > weight) dp[size][weight] = dp[size - 1][weight];
			else dp[size][weight] = max(profits[size - 1] + dp[size - 1][weight - weights[size - 1]], dp[size - 1][weight]);
		}
	}
	return dp[weights.size()][capacity];
}

int main() {
	vector<int>weights = {10, 20, 30};
	vector<int>profits = {60, 100, 120};
	cout << "MaxProfit Iterative : " << getKnapsackProfit(weights, profits, 50) << endl;
	cout << "MaxProfit Recursive : " << getKnapsackProfit(weights, profits, 50, 3) << endl;
	return 0;
}