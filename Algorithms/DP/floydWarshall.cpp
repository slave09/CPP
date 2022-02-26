#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX

void print(vector<vector<int>>&shortestPathPairs){
	for(int index = 1; index < shortestPathPairs.size(); ++index){
		for(int node = 1; node < shortestPathPairs.size(); ++node){
			if(shortestPathPairs[index][node] == inf) cout << "inf ";
			else cout << shortestPathPairs[index][node] << " ";
		}
		cout << endl;
	}
}


vector<vector<int>> floydWarshall(vector<vector<int>>graph){
	for(int node = 1; node < graph.size(); ++node){
		for(int vertex1 = 1; vertex1 < graph.size(); ++vertex1){
			for(int vertex2 = 1; vertex2 < graph.size(); ++vertex2){
				if(graph[vertex1][node] == inf || graph[node][vertex2] == inf) continue;
				graph[vertex1][vertex2] = min(graph[vertex1][vertex2], graph[vertex1][node] + graph[node][vertex2]);
			}	
		}
	}
	return graph;
}

int main(){
	vector<vector<int>>graph = {
		{inf, inf , inf , inf , inf},
		{inf, 0, 3, inf,7},
		{inf, 8, 0, 2, inf},
		{inf, 5, inf, 0, 1},
		{inf, 2, inf, inf, 0},
	};
	vector<vector<int>>shortestPathPairs = floydWarshall(graph);
	print(shortestPathPairs);
	return 0;
}