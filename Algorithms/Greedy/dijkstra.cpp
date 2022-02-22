#include<bits/stdc++.h>
using namespace std;


#define inf INT_MAX

void displayPath(map<pair<int,int>, int>shortestPath){
	for(auto path : shortestPath){
		cout << path.first.first << " ";
		cout << path.first.second << " ";
		cout << path.second << endl;
	}
}

void dijkstra(vector<vector<int>>&adjacencyMatrix, int source){
	vector<bool>isVertexVisited(adjacencyMatrix.size(), false);
	map<pair<int, int>, int>shortestPath;
	priority_queue<vector<int>>heap;
	int minEdge = INT_MAX;
	int neighbour;
	for(int col = 1; col < adjacencyMatrix.size(); ++col){
		if(minEdge > adjacencyMatrix[source][col]){
			minEdge = min(minEdge, adjacencyMatrix[source][col]);
			neighbour = col;
		}
	}
	isVertexVisited[source] = true;
	shortestPath[make_pair(source, neighbour)] = minEdge;
	heap.push({-minEdge, neighbour});
	while(!heap.empty()){
		int minEdge = -heap.top().front();
		int vertex = heap.top().back();
		heap.pop();
		if(isVertexVisited[vertex]) continue;
		isVertexVisited[vertex] = true;
		for(int col = 1; col < adjacencyMatrix.size(); ++col){
			if(isVertexVisited[col]) continue;
			if(adjacencyMatrix[source][col] > minEdge + adjacencyMatrix[vertex][col] && adjacencyMatrix[vertex][col] != inf){
				shortestPath[make_pair(source, col)] =  minEdge + adjacencyMatrix[vertex][col];
				heap.push({-(minEdge + adjacencyMatrix[vertex][col]), col});
			} 
		}
	}

	displayPath(shortestPath);
}

int main(){
	vector<vector<int>>matrix = {
		{inf, inf, inf, inf, inf, inf, inf},
		{inf, inf, 2, 4, inf, inf, inf},
		{inf, inf, inf, 1, 7, inf, inf},
		{inf, inf, inf, inf, inf, 3, inf},
		{inf, inf, inf, inf, inf, inf, 1},
		{inf, inf, inf, inf, 2, inf, 5},
		{inf, inf, inf, inf, 1, inf, inf}
	};
	dijkstra(matrix,1);
	return 0;
}