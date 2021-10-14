#include<iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
	int val;
	Node *next;
public:
	Node(){this -> val = 0;}
	Node(int val){this -> val = val;}
	int getVal(){return val;}
	Node* getNextNode(){return next;}
	void setVal(int val){this -> val = val;}
	void setNextNode(Node *node, int val){node -> next = new Node(val);}
	void insert(vector<Node*>&bin, int index);
	int deleteNode(vector<Node*>&bin, int index);
};

class BinSort : protected Node{
	vector<Node*>bin;
public:
	BinSort(vector<int>&arr);
	int findMax(vector<int>&arr);
	void refillVector(vector<int>&arr);
	~BinSort();
};

int main(){
	vector<int>arr = {1,4,5,8,9,7,6,2,3};
	BinSort sort(arr);
	for(auto val : arr)
		cout << val << " ";
	cout << endl;
	return 0;
}

void Node :: insert(vector<Node*>&bin, int index){
	if(bin[index] == NULL){
		bin[index] = new Node(index);
	}
	else{
		Node *nodeItr = bin[index];
		while(nodeItr -> getNextNode()){
			nodeItr = nodeItr -> getNextNode();
		}
		setNextNode(nodeItr, index);
	}
}

int Node :: deleteNode(vector<Node *>&bin, int index){
	if(bin[index] == NULL) return 0;
	Node *temp = bin[index];
	int val = temp -> getVal();
	bin[index] = bin[index] -> getNextNode();
	delete temp;
	return val;
}

BinSort :: BinSort(vector<int>&arr){
	int maxValue = findMax(arr);
	for(int index = 0; index < maxValue + 1; ++index){
		bin.push_back(NULL);
	}
	for(int index = 0; index < arr.size(); ++index){
		insert(bin, arr[index]);
	}
	refillVector(arr);
}

int BinSort :: findMax(vector<int>&arr){
	int maxElement = INT_MIN;
	for(auto val : arr){
		maxElement = max(maxElement, val);
	}
	return maxElement;
}

void BinSort :: refillVector(vector<int>&arr){
	int key = 0;
	for(int index = 0; index < bin.size(); index++){
		while(bin[index]){
			int val = deleteNode(bin, index);
			if(val == 0) continue;
			arr[key++] = val;
		}
	}
}
 
BinSort :: ~BinSort(){
 	for(int index = 0; index < bin.size(); ++index){
		delete bin[index];
	}
}