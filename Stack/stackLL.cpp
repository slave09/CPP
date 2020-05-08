/*
	Author : Fakhra Najm
	EMail  : fnajm09@gmail.com
	Cpp class for stack implementation using LL
	* 1. push
	* 2. pop
	* 3. peek
	* 4. printStack
*/

#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class stack{
	private : 
		Node * top;
	public:
		stack(){
			top = NULL;
		}
		void push(int value);
		int pop();
		int peek(int index);
		void printStack();
};

void stack :: push(int value){
	Node *node = new Node;
	if(node == NULL)
		cout<<"stack overflow";
	else{
		node->data = value;
		node->next = top;
		top = node;
	}
}

int stack :: pop(){
	int value = -1;
	if(top == NULL){
		cout<<"stack underflow";
	}
	else{
		value = top->data;
		Node *node = top;
		top = top->next;
		delete node;
	}
	return value;
}

int stack :: peek(int index){
	Node * node = top;
  while(node != NULL){
  	for(int i = 0; i < index-1; i++)
  		node = node->next;
  	return node->data;
  }
  return -1;
}

void stack :: printStack(){
	Node *node = top;
	while(node != NULL){
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

int main(){
	stack stk;
	stk.push(10);
	stk.push(20); 
	stk.push(30);
	stk.push(40);
	stk.push(50);
	stk.printStack();
	cout<<stk.pop();
	cout<<endl;
	cout<<stk.peek(1);
	cout<<endl;
	return 0;
}