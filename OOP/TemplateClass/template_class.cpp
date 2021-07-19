#include<iostream>
using namespace std;

template <class T>
class Stack{
private:
	int top;
	int size;
	T *stack_array;
public:
	Stack();
	Stack(int size);
	Stack(Stack &stk);

	int GetTop(){return top;}
	T GetTopValue(){return stack_array[top];}
	int GetSize(){return size;}

	void push(T value);
	void pop();
	void printStack();

	~Stack();

};

template <class T>
Stack<T> :: Stack(){
	top = -1;
	size = 5;
	stack_array = new T[size];
}

template <class T>
Stack<T> :: Stack(int size){
	this -> size = size;
	top = -1;
	stack_array = new T[this -> size];
}

template <class T>
Stack<T> :: Stack(Stack &stk){
	this -> size = stk.size;
	this -> top = stk.GetTop();
	for(int i = 0; i < this -> size; ++i){
		this -> stack_array[i] = stk.stack_array[i];
	}
}

template <class T>
Stack<T> :: ~Stack(){
	delete []stack_array;
}

template <class T>
void Stack<T> :: push(T value){
	if(top == GetSize() - 1)
		cout << "stack is full \n";
	else{
		stack_array[++top] = value;
		cout << value << " pushed into stack" << endl;
	}
}

template <class T>
void Stack<T> :: pop(){
	if(top == -1 )
		cout << "Stack is Empty ! \n";
	else{
		top--;
	}
}

template <class T>
void Stack<T> :: printStack(){
	int itr = top;

	while(itr >= 0)
		cout << stack_array[itr--] << " ";
	cout << endl;
}

int main(){
	Stack<string> stack(5);
	stack.push("C");
	stack.push("C++");
	stack.push("Java");
	stack.push("Python");
	stack.push("Ruby");
	cout << "stack :- ";
	stack.printStack();
	stack.pop();
	cout << "stack :- ";
	stack.printStack();
	return 0;
}