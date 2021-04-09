/*
	Author : Fakhra Najm
	Email  : fnajm09@gmail.com
*/

#include<iostream>
using namespace std;

class QueueArray
{
private:
	int size;
	int front;
	int rear;
	int *items;
public:
	QueueArray(){
		size = 10;
		front = rear = -1;
		items = new int[size];
	}
	QueueArray(int size){
		this->size = size;
		front = rear = -1;
		items = new int[this->size];
	}
	void enqueue(int value);
	int dequeue();
	void printQ();
};

void QueueArray :: enqueue(int value){
	if(rear == size-1)
		cout<<"QueueArray is full"<<endl;
	else{
		rear ++;
		items[rear] = value;
	}
}

int QueueArray :: dequeue(){
	int value = -1;
	if(front == rear)
		cout<<"QueueArray is empty";
	else{
		front++;
		value = items[front];
	}
	return value;
}

void QueueArray :: printQ(){
	for (int i = front+1; i <= rear; ++i)
		cout<<items[i]<<" ";
	cout<<endl;
}

int main(){
	QueueArray q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.printQ();
	cout<<"deleted value:"<<q.dequeue();
	return 0;
}