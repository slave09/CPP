/*
	* Author : Fakhra Najm
	* Optimal Merge Pattern : 
	* Problem : Given the size and cost of n arrays find the minimum cost of merging these arrays
	* Apparoach => 2 way merging : Always select a pair of small size an merge them
	* Application: Merge n files into a single large file such that it get merge in minimum number of overhead movement
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>pattern;
struct Array{
	int id;
	int size;
	int cost;
};

struct comparator{
	bool operator()(Array min, Array max){
		return min.size > max.size;
	}
};

void printPattern(){
	for(auto group : pattern){
		for(auto arr : group){
			cout << arr << " ";
		}
		cout << endl;
	}
}

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
		pattern.push_back({first.id, second.id});
		pq.push({first.size + second.size, first.cost + second.cost});
	}
	return maxCost;
}

int main(){
	vector<Array> arr = {{1,20,20}, {2,30,30}, {3,10,10}, {4,5,5}, {5,30,30}};
	cout << optimalMergePatternCost(arr) << endl;
	printPattern();	
	return 0;
}