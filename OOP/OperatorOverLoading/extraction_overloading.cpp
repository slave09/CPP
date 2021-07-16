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
	// for continue operation of cout << return ostream is necessary here
	// otherwise single cout << will give us result with void function
	friend ostream & operator<<(ostream &out, Complex number);
  // Extraction Operation overloading
  friend istream & operator>>(istream &in, Complex &number);

};

int main(){
	Complex first, second, sum;
  cout << "Enter real and imaginary part : ";
  cin >> first;
  cout << "Enter real and imaginary part : ";
  cin >> second;
  sum = first + second;
	cout << first ;
	cout << second ;
	cout << sum << endl;

	return 0;
}

/*
	* Extraction operator overloading
	* @param in reference to the istream object
	* @param number reference of object of Complex
	* @return istream object
*/
istream & operator>>(istream &in, Complex &number){
  in >> number.real >> number.imaginary;
  return in;
}


/*
	* insertion operator overloading
	* @param out reference to the ostream object
	* @param number reference of object of Complex
	* @return ostream object
*/

ostream & operator<<(ostream &out, Complex number){
	out << number.real << " + " << number.imaginary << "i" << endl;
	return out;
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
