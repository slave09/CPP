#include<iostream>
using namespace std;

class Rectangle{
	int length;
	int breadth;
public:

	// Constructors
	Rectangle();
	Rectangle(int l, int b);
	Rectangle(Rectangle &r);

	// Accessors
	// inline functions with simple logic 
	int getLength(){return length;}
	int getBreadth(){return breadth;}

	// Mutators
	void setLength(int len);
	void setBreadth(int b);

	// Fascilitators
	// inline functionss
	int area(){return length * breadth;}
	int perimeter(){return 2 * (length + breadth);}

	// Enquiry function

	bool isSquare();
	~Rectangle();

};
int main(){

	Rectangle rect;
	rect.setLength(10);
	rect.setBreadth(5);

	cout << "Length : "<< rect.getLength() << " ";
	cout << "Breadth : "<< rect.getBreadth() << " ";
	cout << "perimeter : "<< rect.perimeter() << " " ;
	cout << "Area : "<< rect.area() << endl;

	if(rect.isSquare()) cout << "It's a Rectangle" << endl;
	else cout << "It's not a Rectangle !" << endl;

	return 0;
}

Rectangle :: Rectangle(){
	setLength(0);
	setBreadth(0);
}

Rectangle :: Rectangle(int len, int b){
	setLength(len);
	setBreadth(b);
}

Rectangle :: Rectangle(Rectangle &rect){
	setLength(rect.length);
	setBreadth(rect.breadth);
}

void Rectangle :: setLength(int len){
	if(len < 0) length = 0;
	else length = len;
}

void Rectangle :: setBreadth(int b){
	if(b < 0) breadth = 0;
	else breadth = b;
}

bool Rectangle :: isSquare(){
	return length == breadth ? true : false;
}

Rectangle :: ~Rectangle(){}