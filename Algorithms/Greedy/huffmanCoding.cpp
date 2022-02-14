/*	
	* Topic : Huffman Coding, a compression method to reduce data size.  
	* Algorithm : 
		1. "https://www.youtube.com/watch?v=co4_ahEDCho&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=43&t=895s"
		2. "https://www.youtube.com/watch?v=L5MloiCxHPk&ab_channel=Insidecode"
	* Take the characters on the basis of their frequency 
	* 1. Higher frequency character will have lesser number of bits
	* 2. Lower frequency character will have higher number of bits
	* generate Huffman tree by taking pair of min frequency characters.
	* Perfomr DFS on the tree and generate code for each path by taking left edges as 0s and right Edges as 1s.
	* Tags : Heap, Tree, Map, DFS, BackTracking
*/

#include <bits/stdc++.h>
using namespace std;

#define nullChar  '`'
#define maxMessageLen 100

class Node{
public:
	int frequency;
	char c;
	Node *left;
	Node *right;
	Node(char c, int frequency, Node *left, Node *right){
		this -> c = c;
		this -> frequency = frequency;
		this -> left = left;
		this -> right = right;
	}
};

class HuffmanTree{
	struct comparator{
		bool operator()(Node *min, Node *max){
			return min -> frequency > max -> frequency;
		}
	};
	unordered_map<char, int>frequencyLookup;
	priority_queue<Node*, vector<Node*>, comparator>heap;
	unordered_map<char, string>codeLookup; // Store compressed message code
	Node *root = NULL;

public:

	HuffmanTree(string message){
		for(auto m : message) frequencyLookup[m]++;
		for(auto freq : frequencyLookup) 
			heap.push(new Node(freq.first, freq.second, NULL, NULL));
		root = buildTree();
		GenerateCodeMap(root, "");
		// string encodedMessage = Encode(message);
		// string decodedMessage = Decode(root, encodedMessage);
	}

	Node* getRoot(){return this -> root;}

	/*
		* Generates binary tree
		* @return pointer to the root of binary tree
	*/
	Node * buildTree(){
		while(heap.size() > 1){
			Node *left = heap.top();
			heap.pop();
			Node *right = heap.top();
			heap.pop();
			Node *parent = new Node(nullChar, left -> frequency + right -> frequency, left, right);
			heap.push(parent);
		}
		return heap.top();
	}

	/*
		* Generates a mapping table of characters and their codes
		* @param root pointer to the root of binary tree
		* @param code compressed message code
	*/

	void GenerateCodeMap(Node *root, string code){
		if(root -> c != nullChar) codeLookup[root -> c] = code;
		else{
			code.push_back('0');
			GenerateCodeMap(root -> left, code);
			code.pop_back();
			code.push_back('1');
			GenerateCodeMap(root -> right, code);
			code.pop_back();
		}
	}

	/*
		* Encode messages
		* @param message original message string 
		* @return compressed message
	*/

	string Encode(string message){
		string encodedMessage = "";
		for(auto m : message){
			encodedMessage += codeLookup[m];
		}
		return encodedMessage;
	}

	/*
		* Decode messages
		* @param message to be decoded
		* @return string of original message
	*/

	string getRootMessage(char c, int freq){
		string decodedMessage = "";
		while(freq--){
			decodedMessage.push_back(c);
		}
		return decodedMessage;
	}

	string Decode(Node *root, string encodedMessage){
		if(root -> c != nullChar) 
			return getRootMessage(root -> c, root -> frequency);

		string decodedMessage = "";
		Node *node = root;

		for(auto bit : encodedMessage){
			if(bit == '0') node = node -> left;
			else node = node -> right;
			if(node -> c != nullChar){
			 decodedMessage.push_back(node -> c);
			 node = root;
			}
		}
		return decodedMessage;
	}
};


int main(){
	string message;
	cout << "Enter message : ";
	getline(cin, message);
	HuffmanTree compress(message);
	string encodedMessage = compress.Encode(message);
	cout << encodedMessage<< endl;
	string decodedMessage = compress.Decode(compress.getRoot(), encodedMessage);
	cout << decodedMessage << endl;
	return 0;
}