#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;
#define inf INT_MAX

// struct comparator{
// 	bool operator()(p max, p min){
// 		return max.front() < min.front();
// 	}
// };

void printEdge(vector<int>Edges, vector<int>minCostArr){
	int totalCost = 0;
	for(int index = 1; index < Edges.size(); ++index){
		if(Edges[index] == -1) continue;	
		cout << "[" << index << "]" << " -> " << "[" << Edges[index] << "] ";
		cout << "Cost : " << minCostArr[index] << endl;
		totalCost	+= minCostArr[index];
	}
	cout <<  "Total cost : " << totalCost << endl;
}

void prims(vector<vector<int>>&adjacencyMatrix){
	int vertices = adjacencyMatrix.size(); // number of vertices
	
	priority_queue<p, vector<p>, greater<p>>heap; // sorts according to edges costs

	vector<int>isVertexVisited(vertices, 0); // keeps track of visited vertex 
	vector<int>minCostArr(vertices, inf); // minimum cost of edge of vertices
	vector<int>Edges(vertices, -1); //  represent edge between key and val

	heap.push(make_pair(0, 1));

	while(!heap.empty()){
		int vertex = heap.top().second;
		heap.pop();
		if(isVertexVisited[vertex] == 1) continue;
		isVertexVisited[vertex] = 1;

		for(int adj = 1; adj < vertices; ++adj){

			int currCost = adjacencyMatrix[vertex][adj];

			if(isVertexVisited[adj] == 0 && minCostArr[adj] > currCost){
				minCostArr[adj] = currCost;
				Edges[adj] = vertex;
				heap.push(make_pair(currCost, adj));
			}
		}
	}	
	printEdge(Edges, minCostArr);
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
	prims(matrix);
	return 0;
}