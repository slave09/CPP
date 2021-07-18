#include<iostream>
using namespace std;

class Shape{
public:
	virtual float area() = 0;
	virtual float perimeter() = 0;
};

class Rectangle : public Shape{
private:
	float length;
	float breadth;
public:
	Rectangle();
	Rectangle(float length, float breadth);
	Rectangle(Rectangle &rect);

	float getLength(){return length;}
	float getBreadth(){return breadth;}

	void setLength(float length);
	void setBreadth(float breadth);

	float area();
	float perimeter();

};

Rectangle :: Rectangle(){
	setLength(0);
	setBreadth(0);
}

Rectangle :: Rectangle(float length, float breadth){
	setLength(length);
	setBreadth(breadth);
}

Rectangle :: Rectangle(Rectangle &rectangle){
	setLength(rectangle.length);
	setBreadth(rectangle.breadth);
}

void Rectangle :: setLength(float length){
	if(length < 0) this -> length = 0;
	else this -> length = length;
}

void Rectangle :: setBreadth(float breadth){
	if(breadth < 0) this -> breadth = 0;
	else this -> breadth = breadth;
}

float Rectangle :: area(){
	return length * breadth;
}

float Rectangle :: perimeter(){
	return 2 * (length + breadth);
}


class Circle : public Shape{
private:
	const float pi = 3.14;
	float radius;
public:
	Circle();
	Circle(float radius);
	Circle(Circle &circle);

	float getRadius(){return radius;}

	void setRadius(float radius);

	float area();
	float perimeter();

};

Circle :: Circle(){
	setRadius(0);
}

Circle :: Circle(float radius){
	setRadius(radius);
}

Circle :: Circle(Circle &circle){
	setRadius(circle.radius);
}

void Circle :: setRadius(float radius){
	if(radius < 0) this -> radius = 0;
	else this -> radius = radius;
}


float Circle :: area(){
	return pi * radius * radius;
}

float Circle :: perimeter(){
	return 2 * pi * radius;
}


int main(){
	Shape *shape;
	Circle circle(10);
	Rectangle rectangle(4,3);


	shape = &circle;
	cout << "Perimeter:" << shape -> perimeter() << "\t";
	cout << "Area:" << shape -> area() << endl;

	shape = &rectangle;
	cout << "Perimeter:" << shape -> perimeter() << "\t";
	cout << "Area:" << shape -> area() << endl;

	return 0;
}