/*
	* Assigning child class Object to parent class pointer
*/

#include<iostream>
using namespace std;

class Rectangle {
protected:
	int length;
	int breadth;
public:
	Rectangle(int length, int breadth){
		this -> length = length;
		this -> breadth = breadth;
	}
	int Area(){
		return length * breadth;
	}
};

class Cuboid : public Rectangle{
	int height;
public:
	Cuboid(int length, int breadth, int height):Rectangle(length, breadth){
		this -> height = height;
	}
	int Volume(){
		return length * breadth * height;
	}
};

int main(){
	Rectangle *rectangle;
	Cuboid cuboid(5,10,15);
	rectangle = &cuboid;

	cout << "area : " << rectangle -> Area() << endl;
	return 0;
}

