/*
	* Topic : Smart Pointers
	* tricky way of garbage collection
	* class of smart pointers which can be destroyed automatically after use
	* Overcome the problem of memory leakage
	* Three Types :-
		1. unique_ptr : only one pointer can point 
		2. shared_ptr : pointer can be shared and it maintains count of pointers
		3. weak_ptr : similar as shared_tr but doesn't maintain count of pointers
*/

#include<iostream>
#include <memory>
using namespace std;

class Rectangle{
	int length;
	int breadth;
public:
	Rectangle(){length = breadth = 0;}
	Rectangle(int length, int breadth){
		this -> length = length;
		this -> breadth = breadth;
	}

	int area(){return length * breadth;}

	~Rectangle(){}

};

int main(){
	unique_ptr<Rectangle> ptr(new Rectangle(10, 2));
	cout << "UNIQUE POINTER : " << endl;
	cout << "Area : " << ptr -> area() << endl;

	// we cannot assign more than one pointer to unique pointer
	// we can remove unique_ptr by move() function

	unique_ptr<Rectangle>ptr2;
	ptr2 = move(ptr);

	cout << "MOVED FIRST UNIQUE POINTER : " << endl;
	cout << "Area : " << ptr2 -> area() << endl;

	shared_ptr<Rectangle> share(new Rectangle(5, 7));
	cout << "SHARED POINTER  " << endl;
	cout << "Area : " << share -> area() << endl;

	shared_ptr<Rectangle> share2 = share;
	cout <<"COPY CREATED" << endl;
	cout << "Area : " << share2 -> area() << endl;
	cout << "Number of pointers to shared pointer : ";
	cout << share.use_count() << endl;
	return 0;
}