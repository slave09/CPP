#include<bits/stdc++.h>
using namespace std;

int  matrixChain(vector<int>dimensions){
	int size = dimensions.size();

	vector<vector<int>>matrix(size, vector<int>(size,0));

	for(int diff = 1; diff < size - 1; ++diff){
		for(int row = 1; row < size - diff; ++row){
			int col = diff + row;
			int min = INT_MAX;
			for(int k = row; k < col; ++k){
				int cost = matrix[row][k] + matrix[k + 1][col] + (dimensions[row - 1] * dimensions[k] * dimensions[col]);
				if(min > cost){
					min = cost;
				}
			}
			matrix[row][col] = min;
		}	
	}
	return matrix[1][size - 1];
}


int matrixChainRecursive(vector<vector<int>>&dp, vector<int>&nums, int i, int j){
	if(i >= j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int minCost = INT_MAX;
	for(int k = i; k <= j - 1; ++k){
		minCost = min(matrixChainRecursive(dp, nums, i, k) + matrixChainRecursive(dp, nums, k + 1, j) + nums[i - 1]*nums[k]*nums[j], minCost);
	}
	return dp[i][j] = minCost;
}


int main(){
	vector<int>dimensions = {5,4,6,2,7};
	vector<vector<int>>dp(dimensions.size() + 1, vector<int>(dimensions.size() + 1, -1));
	cout << matrixChainRecursive(dp, dimensions, 1, dimensions.size() - 1) << endl;
	cout << matrixChain(dimensions) << endl;
	return 0;
}