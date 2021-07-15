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

	// Rectangle(){
	// 	length = 0;
	// 	breadth = 0;
	// }

 	// parameterized Constructor

	Rectangle(int len = 0, int bth = 0){
		setLength(len);
		setBreadth(bth);
	}

	// Copy Constructor 
	// Shalow Copy constructor

	Rectangle(Rectangle &rect){
		length = rect.length;
		breadth = rect.breadth;
	}
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

	float getLength(){return length; }

	float getBreadth(){return breadth;}

	// Member Functions or Fascillatators

	float area(){return length * breadth;}

	float perimeter(){return 2 * (length + breadth);}
};


int main(){

	Rectangle rect;
	cout << "length : " << rect.getLength() ;
	cout << " breadth : " << rect.getBreadth();
	cout << " Area : " << rect.area() << endl; 

	Rectangle rec(10, 5);
	cout << "length : " << rec.getLength() ;
	cout << " breadth : " << rec.getBreadth() ;
	cout << " Area : " << rec.area() << endl; 

	Rectangle copy(rec);
	cout << "length : " << copy.getLength() ;
	cout << " breadth : " << copy.getBreadth() ;
	cout << " Area : " << copy.area() << endl; 
	return 0;
}