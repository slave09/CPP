#include<iostream>
using namespace std;

class Complex{
	float real;
	float imaginary;

public:

	Complex();
	Complex(float real, float imaginary);
	Complex(Complex &number);

	float getImaginary() {return imaginary;}
	float getReal(){return real;}

	void setImaginary(float imaginary){this -> imaginary = imaginary;}
	void setReal(float real){this -> real = real;}

	// Addition Operator overloading 
	friend Complex operator+(Complex first, Complex second);
	// insertion operator overloading
	friend ostream & operator<<(ostream &o, Complex number);

};

int main(){
	Complex first(5,5);
	Complex second(6,9);
	Complex sum;

	sum = first + second;

	cout << first ;
	cout << second ;
	cout << sum << endl;

	return 0;
}

/*
	* insertion operator overloading
	* @param o reference to the ostream object
	* @param number reference of object of Complex
	* @return ostream object
*/

ostream & operator<<(ostream &o, Complex number){
	o << number.real << " + " << number.imaginary << "i" << endl;
	return o;
}


Complex :: Complex(){
	setReal(0);
	setImaginary(0);
}

Complex :: Complex(float real, float imaginary){
	setReal(real);
	setImaginary(imaginary);
}

Complex :: Complex(Complex &number){
	setReal(number.real);
	setImaginary(number.imaginary);
}

Complex operator+(Complex first, Complex second){
	Complex sum;

	sum.real = first.real + second.real;
	sum.imaginary = first.imaginary + second.imaginary;

	return sum;

}
