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

int main(){
	vector<int>dimensions = {5,4,6,2,7};
	cout << matrixChain(dimensions) << endl;
	return 0;
}