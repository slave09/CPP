/*
	* Topic : Bellman-Ford Algorithm : Single source All pair shortest path.
	* How different from floyd-warshall ? Bellman-Ford can deal with negative edges also.
	* Apparoach : Perform relaxation on every edges n - 1 times where n is the number of vertices.
	* Drawback : cannot give correct result in case if negative weight cycle is present in the graph.
*/

#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

class Edge{
	public:
	int weight;
	int to;
	int from;
	Edge(int from, int to, int weight){
		this -> to = to;
		this -> from = from;
		this -> weight = weight;
	}
};

class Graph{
	int vertices;
	vector<Edge>adj_list;
	vector<int>distance;
public:
	Graph(int vertices){
		this -> vertices = vertices;
	}

	void CreateEdge(int from, int to, int weight){
		Edge edge(from, to, weight);
		adj_list.push_back(edge);
	}

	void printDistance(int source){
		for(int index = 1; index < distance.size(); ++index){
			if(index == source) continue;
			cout << source << "->" << index << "," << distance[index] << endl; 
		}
	}

	bool detectNegativeCycle(){
		// Update distance to -inf if -ve cycle is present
		bool isNegativeCycle = false;
		for(int start = 0; start < vertices - 1; ++start){
			for(auto edge : adj_list){
				if(distance[edge.from] != inf && distance[edge.to] > distance[edge.from] + edge.weight){
					isNegativeCycle = true;
					distance[edge.to] = -inf;
				}
			}
		}
		return isNegativeCycle;
	}

	void bellman_ford(int source){
		distance.resize(vertices + 1, inf);
		distance[source] = 0;
		for(int start = 0; start < vertices - 1; ++start){
			// Relax Edges 
			for(auto edge : adj_list){
				if(distance[edge.from] != inf && distance[edge.to] > edge.weight + distance[edge.from]){
					distance[edge.to] = edge.weight + distance[edge.from];
				}
			}
		}
		if(detectNegativeCycle()) cout << "Negative Cycle detected !" << endl;
	}
};

int main(){
	Graph graph(4);
	graph.CreateEdge(1, 2, 4);
	graph.CreateEdge(3, 2, -10);
	graph.CreateEdge(4, 3, 3);
	graph.CreateEdge(1, 4, 5);
	// graph.CreateEdge(2, 4, 5); // Negative Cycle 
	graph.bellman_ford(1);
	graph.printDistance(1);
	return 0;
}