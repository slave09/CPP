#include<iostream>
using namespace std;

class LinkedList{
	class Node {
	public:
		int val;
		Node *next;
		static Node * createNode(int val){
			Node *node = new Node;
			node -> val = val;
			node -> next = NULL;
			return node;
		}
	};

	Node *head;

public:
	LinkedList();
	LinkedList(int val);
	LinkedList(int val, Node *next);
	LinkedList(Node * &node);
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

LinkedList :: LinkedList(Node * &node){
	head = new Node;
	Node *itr = head;
	Node *ref = node;

	while(ref){
		itr -> val = ref -> val;
		ref = ref -> next;
		itr = itr -> next;
	}

}

void LinkedList :: insert(int val){
	Node *node = Node::createNode(val);
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

void LinkedList :: Remove(int val){
	if(head -> val == val) head = head -> next;
	else{
		Node *ptr = head;
		while(ptr && ptr -> next){
			if(ptr -> next -> val == val){
				Node *temp = ptr -> next;
				ptr -> next = ptr -> next -> next;
				delete temp;
				return;
			}
			ptr  = ptr -> next;
		}
	}
}

int main(){
	LinkedList list(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	list.insert(50);
	list.insert(60);
	cout << "List:\n";
	list.Display();
	list.Remove(20);
	cout << "After Removing 20" << endl;
	cout << "List:\t";
	list.Display();
	LinkedList new_list(list);
	cout << "Copied List" << endl;
	cout << "List:\t";
	new_list.Display();
	return 0;

}