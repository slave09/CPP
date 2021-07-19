#include<iostream>
using namespace std;

class Shape{
private:
	int length;
protected:
	int breadth;
public:
	int height;

	Shape(int edge){
		length = breadth = height = edge;
	}

	friend int Volume(Shape shape);
};

int Volume(Shape shape){
	return shape.length*shape.breadth*shape.height;
}

int main(){
	Shape cube(10);
	cout << Volume(cube) << endl;
	return 0;
}