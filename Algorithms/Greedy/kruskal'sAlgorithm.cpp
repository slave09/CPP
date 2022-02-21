#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

void fillHeap(vector<vector<int>> &matrix, priority_queue<vector<int>> &heap)	{
	for(int row = 1; row < matrix.size(); ++row){
		for(int col = 1; col <= row; ++col){
			if(matrix[row][col] != inf){
			 	heap.push({-1 * matrix[row][col], row, col});
			}
		}
	}
}

void Union(vector<int>&disjoint, int node1, int node2){
	if(disjoint[node2] < disjoint[node1]){
		disjoint[node2] += disjoint[node1];
		disjoint[node1] = node2;
	}
	else{
		disjoint[node1] += disjoint[node2];
		disjoint[node2] = node1;	
	}
}

int find(vector<int>&disjoint, int node){
	int parent = node;
	while(disjoint[parent] > 0){
		parent = disjoint[parent];
	}
	while(node != parent){
		int nextNode = disjoint[node];
		disjoint[node] = parent;
		node = nextNode;
	}
	return parent;
}

void kruskals(vector<vector<int>>&matrix){
	vector<int>disjoint(matrix.size(), -1); disjoint set to detect cycle
	priority_queue<vector<int>>heap;

	fillHeap(matrix, heap);

	int minCost = 0;
	while(!heap.empty()){
		auto node = heap.top();
		heap.pop();
		int parent1 = find(disjoint, node[1]);
		int parent2 = find(disjoint, node[2]);
		if(parent2 != parent1){
			Union(disjoint, parent1, parent2);
			minCost -= node.front();
			cout << node[1] << "->" << node[2] << " " << -node.front() << endl;
		}
	}

	cout << "Total cost : " << minCost << endl;
}	

int main(){
	vector<vector<int>>matrix = {
	{inf, inf, inf, inf, inf, inf, inf, inf},
	{inf, inf, 25, inf, inf, inf, 5, inf},
	{inf, 25, inf, 9, inf, inf, inf, 6},
	{inf, inf, 9, inf, 10, inf, inf, inf},
	{inf, inf, inf, 10, inf, 12, inf, 11},
	{inf, inf, inf, inf, 12, inf, 18, 16},
	{inf, 5, inf, inf, inf, 18, inf, inf},
	{inf, inf, 6, inf, 11, 16, inf, inf},
	};
	kruskals(matrix);
	return 0;
}