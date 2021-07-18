#include<iostream>
using namespace std;

class Rectangle{
protected:
	int length;
	int breadth;
public:
	Rectangle(int length = 0, int breadth = 0){
		this -> length = length;
		this -> breadth = breadth;
	}
	virtual int area(){return length * breadth;}
};

class Cuboid : public Rectangle{
	int height;
public:
	Cuboid(int length = 0, int breadth = 0, int height = 0) 
	: Rectangle(length, breadth)
	{
		this -> height = height;
	}
	int area(){
		return 2 * (length * breadth + breadth * height + length * height);
	}
};

int main(){
	Rectangle *rect = new Cuboid(10,3,6);
	cout << "Area : " << rect -> area() << endl;
	return 0;
}