/*
	* Topic : Data Hiding 
	* Property Functions
		1. Mutators 
		2. Accessors 
*/

#include<iostream>
using namespace std;

class Rectangle {
private: 
	// hiding data so that there is no mishandelling
	float length;
	float breadth;

public:
	
	// Mutators or Setters

	void setLength(float len){// validation as length cannot be negative
		if(len < 0) length = 0; // setting to default value of 0
		else length = len;
	}

	void setBreadth(float bth){ // validation as Breadth cannot be negative
		if(bth < 0) breadth = 0; // setting to default value of 0
		else breadth = bth;
	}

	// Accessors or getters

	float getLength(){
		return length; 
	}

	float getBreadth(){
		return breadth;
	}

	// Member Functions

	float area(){
		return length * breadth;
	}

	float perimeter(){
		return 2 * (length + breadth);
	}
};


int main(){
	Rectangle rect;
	rect.setLength(-1);
	rect.setBreadth(-3);
	cout << "Length: " << rect.getLength() << endl;
	cout << "Breadth: " << rect.getBreadth() << endl;
	cout << "area: " << rect.area() << endl;
	cout << "perimeter: " << rect.perimeter() << endl;
	return 0;
}