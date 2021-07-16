/*
	* Topic : Data Hiding 
	* This Pointer : Used to access same Object data members
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

	void setLength(float length){// validation as length cannot be negative
		if(length < 0) this -> length = 0; // setting to default value of 0
		else this -> length = length;
	}

	void setBreadth(float breadth){ // validation as Breadth cannot be negative
		if(breadth < 0) this -> breadth = 0; // setting to default value of 0
		else this -> breadth = breadth;
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
	rect.setLength(1);
	rect.setBreadth(13);
	cout << "Length: " << rect.getLength() << endl;
	cout << "Breadth: " << rect.getBreadth() << endl;
	cout << "area: " << rect.area() << endl;
	cout << "perimeter: " << rect.perimeter() << endl;
	return 0;
}