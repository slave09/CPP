#include <bits/stdc++.h>
using namespace std;

class Graph{
	int vertices;
	list<int>*ADJ_List;
public:
	Graph(int vertices){
		this -> vertices = vertices;
		ADJ_List = new list<int>[vertices];
	}

	void create_edge(int vertex1, int vertex2){
		ADJ_List[vertex1].push_back(vertex2);
		ADJ_List[vertex2].push_back(vertex1);
	}

	void print(){
		for(int vertex = 1; vertex < vertices; ++vertex){
			cout << "Vertex : " << vertex << " -> " ;
			for(auto edge : ADJ_List[vertex]){
				cout << edge << ", "; 
			}
			cout << endl;
		}
	}
};

int main(){
	Graph graph(5);
	graph.create_edge(1,2);
	graph.create_edge(1,4);
	graph.create_edge(2,3);
	graph.create_edge(3,4);
	graph.print();
	return 0;
}