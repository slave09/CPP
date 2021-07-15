#include<iostream>
using namespace std;

class Rectangle{
public:
	int length;
	int width;

	int area(){
		return length * width;
	}

	int perimeter(){
		return 2 * (length + width);
	}
};

int main(){

	// Creating Object in stack 

	Rectangle rect1;

	rect1.length = 10;
	rect1.width  = 8;

	cout << "Length : " << rect1.length << endl;
	cout << "Width : " << rect1.width << endl;

	cout << "Area: " << rect1.area() << endl;

	// Creating Pointer to objecr

	Rectangle *ptr ;
	ptr = &rect1;

	cout << "Length : " << ptr -> length << endl;
	cout << "Width : " << ptr -> width << endl;

		cout << "Area: " << ptr -> area() << endl;


	// Creating Object inside Heap

	Rectangle *rect2 = new Rectangle(); // parantheses can be avoided
	rect2 -> length = 20;
	rect2 -> width = 15;

	cout << "Length : " << rect2 -> length << endl;
	cout << "Width : " << rect2 -> width << endl;

	cout << "Area : " << rect2 -> area() << endl;
	cout << "perimeter : " << rect2 -> perimeter() << endl;
	return 0;
}