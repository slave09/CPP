/*	
	* Topic : Huffman Coding, a compression method to reduce data size.  
	* Algorithm : "https://www.youtube.com/watch?v=L5MloiCxHPk&ab_channel=Insidecode"
	* sort the characters on the basis of their frequency 
	* 1. Higher frequency character will have lesser number of bits
	* 2. Lower frequency character will have more number of bits
	* generate Huffman tree by taking pair of min frequency characters 2 at a time
	* Perfomr DFS on the tree and generate code for each path by taking left edges as 0s and right Edges as 1s
	* Tags : Heap, Tree, Map, DFS, BackTracking
*/

#include <bits.stdc++.h>
using namespace std;

class Node{
	int frequency;
	char c;
	Node *left;
	Node *right;
public:
	Node(char c, int frequency, Node *left, Node *right){
		this -> c = c;
		this -> frequency = frequency;
		this -> left = left;
		this -> right = right;
	}
}

class HuffmanTree{
	struct comparator{
		bool operator()(Node *min, Node *max){
			return min.second > max.second;
		}
	};
	unordered_map<char, int>frequencyLookup;
	priority_queue<Node*, vector<Node*>, comparator>pq;
	unordered_map<char, string>codeLookup; // Store compressed message code
public:

	HuffmanTree(string message){
		for(auto m : message) frequencyLookup[m]++;
		for(auto freq : frequencyLookup) pq.push(new Node(freq.first, freq.second, NULL, NULL));
		Node *tree = buildTree();
		// GenerateCodeMap
		// Encode
		// Decode
	}

	Node * buildTree(){
		while(pq.size() > 1){
			Node *left = pq.top();
			pq.pop();
			Node *right = pq.top();
			pq.pop();
			Node *parent = new Node(nullptr, left -> frequency + right -> frequency, left, right);
			pq.push(parent);
		}
		return pq.top();
	}

	/*
		* Implement GenerateCodeMap
		* @param tree Huffman tree
	*/

	/*
		* Implement Encode
		* @param message original string
		* @Return compressed message
	*/

	/*
		* Implement Decode
		* @Return original message
		* @param message encoded string
	*/
};


int main(){
	return 0;
}