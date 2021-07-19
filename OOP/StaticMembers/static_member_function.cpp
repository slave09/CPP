#include <iostream>
using namespace std;

class Object{
	public :
	string color;
	static int count;
	Object(string color){
		count++;
		this -> color = color;
	}

	static int getCount(){ // can only access static data members
		count += 12;
		return count;
	}
};

int Object :: count = 0; // static data members should be defined outside of class

int main(){

	Object ball("red");
	Object football("blue");

	cout << "count : " << Object :: count << endl;

	ball.count = 45;

	cout << "football count : " << football.count << endl;

	cout << "getCount() = " << Object :: getCount() << endl;

	return 0;
}