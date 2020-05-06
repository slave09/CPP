#include<iostream>
using namespace std;

class Node
{
public:
  Node *left_child;
  int data;
  Node *right_child;
};

class QueueArray
{
private:
	int size;
	int front;
	int rear;
	Node **items;
public:
	QueueArray(){
		size = 10;
		front = rear = -1;
		items = new Node*[size];
	}
	QueueArray(int size){
		this->size = size;
		front = rear = -1;
		items = new Node*[this->size];
	}
	void enqueue(Node * value);
	Node* dequeue();
  int isEmpty();
};

void QueueArray :: enqueue(Node *value){
	if(rear == size-1)
		cout<<"QueueArray is full"<<endl;
	else{
		rear ++;
		items[rear] = value;
	}
}

Node * QueueArray :: dequeue(){
	Node * value= NULL;
	if(front == rear)
		cout<<"QueueArray is empty";
	else{
		front++;
		value = items[front];
	}
	return value;
}

int QueueArray :: isEmpty(){
  if(front == rear)
    return 1;
  return 0;
}