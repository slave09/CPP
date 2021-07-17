#include<iostream>
using namespace std;

class Rectangle{
	int length;
	int breadth;

public:
	Rectangle();
	Rectangle(int length, int breadth);
	Rectangle(Rectangle &rect);

	int getLength(){return length;}
	int getBreadth(){return breadth;}

	void setLength(int length);
	void setBreadth(int breadth);

	int area(){return length * breadth;}
	int perimeter(){return 2 * (length + breadth);}

	~Rectangle(){}
};

class Cuboid : public Rectangle{
	int height;
public:
	Cuboid();
	Cuboid(int height);
	Cuboid(int length, int breadth, int height);
	Cuboid(Cuboid &cuboid);

	int getHeight(){return height;}
	void setHeight(int height);

	int volume();

	~Cuboid(){}
};

int main(){
	Cuboid cuboid(1, 2, 5);
	cout << "Length : " << cuboid.getLength() << endl;
	cout << "Breadth : " << cuboid.getBreadth() << endl;
	cout << "Height : " << cuboid.getHeight() << endl;
	cout << "Volume : " << cuboid.volume() << endl;
	return 0;
}

Rectangle :: Rectangle(){
	setLength(0);
	setBreadth(0);
}

Rectangle :: Rectangle(int length, int breadth){
	setLength(length);
	setBreadth(breadth);
}

Rectangle :: Rectangle(Rectangle &rect){
	setLength(rect.length);
	setBreadth(rect.breadth);
}

void Rectangle :: setLength(int length){
	if(length < 0) this -> length = 0;
	else this -> length = length;
}

void Rectangle :: setBreadth(int breadth){
	if(breadth < 0) this -> breadth = 0;
	else this -> breadth = breadth;
}

Cuboid :: Cuboid(){
	setLength(1);
	setBreadth(1);
	setHeight(1);
}

Cuboid :: Cuboid(int height){
	setHeight(height);
}

Cuboid :: Cuboid(int length, int breadth, int height){
	setLength(length);
	setBreadth(breadth);
	setHeight(height);
}

Cuboid :: Cuboid(Cuboid &cuboid){
	setLength(cuboid.getLength());
	setBreadth(cuboid.getBreadth());
	setHeight(cuboid.height);
}

void Cuboid :: setHeight(int height){
	if(height < 0) this -> height = 0;
	else this -> height = height;
}

int Cuboid :: volume(){
	return getLength() * getBreadth() * height;
}