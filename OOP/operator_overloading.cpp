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

// Operator overloading 
	// Complex operator+(Complex complex_number);
	friend Complex operator+(Complex first, Complex second);

};

int main(){
	Complex first(5,5);
	Complex second(6,9);
	Complex sum;
	sum = first + second;

	cout << "First Number : " << first.getReal() << " + " << first.getImaginary() << "i" << endl; 
	cout << "second Number : " << second.getReal() << " + " << second.getImaginary() << "i" << endl;
	cout << "Sum : " << sum.getReal() << " + " << sum.getImaginary() << "i" << endl;
	return 0;
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

// Complex Complex :: operator+(Complex complex_number){ 

// 	Complex sum;

// 	sum.real = real + complex_number.real;
// 	sum.imaginary = imaginary + complex_number.imaginary;

// 	return sum;
// }