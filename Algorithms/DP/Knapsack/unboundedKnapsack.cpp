/*
	* 0/1 Knapsack Problem where Repetition of items are allowed
*/

#include<bits/stdc++.h>
using namespace std;

int dp[1000][10000];

int unboundedKnapSack(vector<int>&weights, vector<int>&profits, int capacity, int index){
	if(capacity == 0 || index == 0) return 0;
	if(dp[index][capacity] != -1) return dp[index][capacity]; 
	// Keep including same item unitll capacity reaches or dont include the item at all and move to next item 
	if(weights[index - 1] <= capacity) 
		return dp[index][capacity] = max(profits[index - 1] + unboundedKnapSack(weights, profits, capacity - weights[index - 1], index), unboundedKnapSack(weights, profits, capacity, index - 1));
	return dp[index][capacity] = unboundedKnapSack(weights, profits, capacity, index - 1);
}


int unboundedKnapSack(vector<int>&weights, vector<int>&profits, int capacity){

	for(int i = 0; i <= weights.size(); ++i){
		for(int j = 0; j < capacity + 1; ++j){
			if(i == 0 || j == 0) dp[i][j] = 0;
		}
	}

	for(int i = 1; i <= profits.size(); ++i){
		for(int j = 1; j <= capacity; ++j){
			if(weights[i - 1] <= j){
				dp[i][j] = max(dp[i - 1][j], profits[i - 1] + dp[i][j - weights[i - 1]]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[weights.size()][capacity];
}

int main() {
	memset(dp, -1, sizeof(dp));
	vector<int>profits = {10, 30, 20};
	vector<int>weights = {5, 10, 15};
	int capacity;
	cout << " Eneter capacity : " ;
	cin >> capacity;
	cout << "Profit : " << unboundedKnapSack(weights, profits, capacity, profits.size()) << endl;
	cout << "Profit : " << unboundedKnapSack(weights, profits, capacity) << endl;

	return 0;
}