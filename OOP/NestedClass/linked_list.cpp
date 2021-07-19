#include<iostream>
using namespace std;

class LinkedList{
	class Node {
		public:
			int val;
			Node *next;
	};
public:
	Node *head;
	LinkedList();
	LinkedList(int val);
	LinkedList(int val, Node *next);
	// LinkedList(ListNode &node);

	// Node * createNode(int val);
	void insert(int val);
	void Remove(int val);
	void Display();

};

LinkedList :: LinkedList(){
	head = NULL;
}

LinkedList :: LinkedList(int val){
	head = new Node;
	head -> val = val;
	head -> next = NULL;
}

LinkedList :: LinkedList(int val, Node *next){
	head = new Node;
	head -> val = val;
	head -> next = next;
}

// LinkedList :: LinkedList(ListNode &node){
// 	head = new Node;
// 	Node *itr = head;
// 	while(node){
// 		itr -> val = node -> val;
// 		node = node -> next;
// 		itr = itr -> next; 
// 	}
// 	itr -> next = NULL;
// }

// Node * LinkedList :: createNode(int val){
// 	Node *node = new Node;

// 	node -> val = val;
// 	node -> next = NULL;

// 	return node;
// }

void LinkedList :: insert(int val){
	Node *node = new Node;
	node -> val = val;
	node -> next = NULL;
	if(!head){
		head = node;
		return ;
	}
	Node *ptr = head;
	while(ptr -> next) ptr = ptr -> next;
	ptr -> next = node;
}

void LinkedList :: Display(){
	Node *ptr = head;

	while(ptr){
		cout << ptr -> val << " ";
		ptr = ptr -> next;
	}
	cout << endl;
}

int main(){
	LinkedList list(10);
	list.insert(20);
	list.Display();
	return 0;

}