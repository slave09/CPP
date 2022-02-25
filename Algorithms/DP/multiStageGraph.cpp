/* 
	* Multistage graph
	* used in resource allocation
*/
#include<bits/stdc++.h>
using namespace std;

void displayPath(vector<int>&path, int source, int target){
	while(source != target){
		cout << source << "->";
		source = path[source];
	}
	cout << source << endl;
}

int minDistance(vector<vector<int>>&graph, int source, int target){
	vector<int>distance(graph.size());
	vector<int>path(graph.size());
	distance[target] = 0;
	path[target] = target;

	for(int vertex = target - 1; vertex >= 1; --vertex){
		int minCost = INT_MAX;
		for(int node = vertex + 1; node <= target; ++node){
			int cost = graph[vertex][node];
			if(cost != 0 && minCost > cost + distance[node]){
				minCost = cost + distance[node];
				distance[vertex] = minCost;
				path[vertex] = node;
			}
		}
	}
	displayPath(path, source, target);
	return distance[source];
}


int main(){
	vector<vector<int>>graph = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,2,1,3,0,0,0,0},
		{0,0,0,0,0,2,3,0,0},
		{0,0,0,0,0,6,7,0,0},
		{0,0,0,0,0,6,8,9,0},
		{0,0,0,0,0,0,0,0,6},
		{0,0,0,0,0,0,0,0,4},
		{0,0,0,0,0,0,0,0,5},
		{0,0,0,0,0,0,0,0,0}
	};
	cout << minDistance(graph, 1, 8) << endl;
	return 0;
}