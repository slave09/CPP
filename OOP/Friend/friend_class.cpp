#include<iostream>
using namespace std;

class Friend;

class Mass{
private:
	int mass;
protected:
	int velocity;
public:
	int radius;

	Mass(int mass = 0, int velocity = 0, int radius = 0){
		this -> mass = mass;
		this -> velocity = velocity;
		this -> radius = radius;
	}

	friend Friend;
};

class Friend{
public:
	Mass point;
	void getData(){
		cout << "It is a point mass" << endl;
		cout << "velocity : " << point.velocity << " meter/sec" << endl;
		cout << "velocity : " << point.mass << " kg" << endl;
		cout << "velocity : " << point.radius << " meter" << endl;
	}
};

int main(){
	Friend f;
	f.getData();
	return 0;
}