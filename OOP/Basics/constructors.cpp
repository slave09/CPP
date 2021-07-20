/*
	* Topic : Constructors 
	* Types
		1. Default Constructors : compiler provided 
		2. Non parameterized Constructors 
		3. parameterized Constructors 
		4. Copy Constructors 
*/

#include<iostream>
using namespace std;

class Rectangle {
private: 
	// hiding data so that there is no mishandelling
	float length;
	float breadth;

public:
	
	// Non parameterized Constructor

	Rectangle(){
		setLength(0);
		setBreadth(0);
	}

 	// parameterized Constructor

	Rectangle(int length, int breadth){
		setLength(length);
		setBreadth(breadth);
	}

	// Copy Constructor 
	// Shallow Copy constructor

	Rectangle(Rectangle &rect){
		setLength(rect.length);
		setBreadth(rect.breadth);
	}
	// Mutators or Setters

	void setLength(float length){// validation as length cannot be negative
		if(length < 0) this -> length = 0; // setting to default value of 0
		else this -> length = length;
	}

	void setBreadth(float breadth){ // validation as Breadth cannot be negative
		if(breadth < 0) this -> breadth = 0; // setting to default value of 0
		else this -> breadth = breadth;
	}

	// Accessors or getters

	float getLength(){return length; }

	float getBreadth(){return breadth;}

	// Member Functions or Fascillatators

	void getDetails(){
		cout << "length : " << getLength() ;
		cout << "\tbreadth : " << getBreadth();
		cout << "\tArea : " << area() << endl; 
	}

	float area(){return length * breadth;}

	float perimeter(){return 2 * (length + breadth);}
};


int main(){

	Rectangle rect;
	rect.getDetails();

	Rectangle rec(10, 5);
	rec.getDetails();

	Rectangle copy(rec);
	copy.getDetails();
	
	return 0;
}