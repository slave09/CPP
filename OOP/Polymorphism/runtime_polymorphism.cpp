#include<iostream>
using namespace std;

class Car{
public:
	virtual void start(){
		cout << "A car has Started !" << endl;
	}
};

class Inova : public Car{
public:
	void start(){
		cout << "An Inova has Started !" << endl;
	}
};

class Suzuki : public Car{
public:
	void start(){
		cout << "A Suzuki has Started !" << endl;
	}
};


int main(){
	Car *car = new Inova;
	car -> start();

	car = new Suzuki;
	car -> start();
	return 0;
}