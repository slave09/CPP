#include<iostream>
using namespace std;

class StackOverFLow{
public:
	void message(){
		cout << "Stackoverflow !!!" << endl;
	}
};

class StackUnderFLow{
public:
	void message(){
		cout << "Stackunderflow !!!" << endl;
	}
};

class Stack{
private:
	int top;
	int size;
	int *stack_array;
public:
	Stack();
	Stack(int size);
	Stack(Stack &stk);

	int GetTop(){return top;}
	int GetTopValue(){return stack_array[top];}
	int GetSize(){return size;}

	void push(int value);
	void pop();

	~Stack();

};

Stack :: Stack(){
	top = -1;
	size = 5;
	stack_array = new int[size];
}

Stack :: Stack(int size){
	this -> size = size;
	top = -1;
	stack_array = new int[this -> size];
}

Stack :: Stack(Stack &stk){
	this -> size = stk.size;
	this -> top = stk.GetTop();
	for(int i = 0; i < this -> size; ++i){
		this -> stack_array[i] =stk.stack_array[i];
	}
}

Stack :: ~Stack(){
	delete []stack_array;
}


void Stack :: push(int value){
	if(GetTop() == GetSize() - 1)
		throw StackOverFLow();
	else{
		stack_array[++top] = value;
	}
}

void Stack :: pop(){
	if(GetTop() == -1 )
		throw StackUnderFLow();
	else{
		top--;
	}
}

int main(){
	Stack stack(5);

	try{
		for(int i = 0; i < 6; ++i){
			stack.push(i + 1);
		}
	}

	catch(StackOverFLow over){
		over.message();
	}


	try{
		for(int i = 0; i < 6; ++i){
			stack.pop();
		}
	}

	catch(StackUnderFLow under){
		under.message();
	}

	catch(...){
		cout << "Segmentation Fault ! " << endl;
	}

	return 0;
}