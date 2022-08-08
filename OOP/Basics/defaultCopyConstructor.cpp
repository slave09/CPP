/*
	* Topic : Default Copy constructor
	* Built in constructor which takes an object as parameter and creates copy of that object.
*/
#include<iostream>
using namespace std;

class Car{
	int cost;
	string color;
	int seats;
public:
	Car() : cost(100000), color("red"), seats(5)
	{}
	Car(int cost, string color, int seats){
		this -> cost = cost;
		this -> color =  color;
		this -> seats = seats;
	}
	int getNumberOfSeats(){return this -> seats;}
	int getCarCost(){return this -> cost;}
	string getCarColor(){return this -> color;}
};

int main(){
	Car car(1000, "red", 5);
	Car newCar(car);
	cout << "Color : "<< newCar.getCarColor() << endl;
	cout << "Color : "<< newCar.getCarCost() << endl;
	cout << "Color : "<< newCar.getNumberOfSeats() << endl;
	return 0;
}