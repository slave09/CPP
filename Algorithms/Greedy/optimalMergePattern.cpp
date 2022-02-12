/*
	* Author : Fakhra Najm
	* Optimal Merge Pattern : 
	* Problem : Given the size and cost of n arrays find the minimum cost of merging these arrays
	* Apparoach => 2 way merging : Always select a pair of small size an merge them
	* Application: Merge n files into a single large file such that it get merge in minimum number of overhead movement
*/

#include<bits/stdc++.h>
using namespace std;

struct Array{
	int size;
	int cost;
};

struct comparator{
	bool operator()(Array min, Array max){
		return min.size > max.size;
	}
};

int optimalMergePatternCost(vector<Array>arr){
	priority_queue<Array, vector<Array>, comparator>pq;
	int maxCost = 0;
	for(auto A : arr){
		pq.push(A);
	}
	while(pq.size() > 1){
		auto first = pq.top();
		pq.pop();
		auto second = pq.top();
		pq.pop();
		maxCost += first.cost + second.cost;
		pq.push({first.size + second.size, first.cost + second.cost});
	}
	return maxCost;
}

int main(){
	vector<Array> arr = {{20, 20}, {30, 30}, {10, 10}, {5, 5}, {30, 30}};
	cout << optimalMergePatternCost(arr) << endl;
	return 0;
}