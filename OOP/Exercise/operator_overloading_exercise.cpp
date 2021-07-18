#include <iostream>
using namespace std;

class Rational{
	int numerator;
	int denominator;

public:
	Rational();
	Rational(int numerator, int denominator);
	Rational(Rational &number);

	int getNumerator(){return numerator;}
	int getDenominator(){return denominator;}

	void setNumerator(int numerator){this -> numerator = numerator;}
	void setDenominator(int denominator){this -> denominator = denominator;}

	friend Rational operator+(Rational first, Rational second);
	friend istream & operator>>(istream &in, Rational &number);
	friend ostream & operator<<(ostream &out, Rational &number);

	~Rational(){}
};

int main(){
	Rational first, second, sum;

	cout << "Enter numerator && denominator : ";
	cin >> first;
	cout << "First rational number : "<< first ;

	cout << "Enter numerator && denominator : ";
	cin >> second;
	cout << "Second rational number : "<< second ;

	sum = first + second;

	cout << "Sum : " << sum ;

	return 0;
}

Rational :: Rational(){
	setNumerator(1);
	setDenominator(1);
}

Rational :: Rational(int numerator, int denominator){
	setNumerator(numerator);
	setDenominator(denominator);
}

Rational :: Rational(Rational &number){
	setNumerator(number.numerator);
	setDenominator(number.denominator);
}

Rational operator+(Rational first, Rational second){
	
	Rational sum;
	sum.numerator = (second.denominator * first.numerator )+ (first.denominator * second.numerator);
	sum.denominator= first.denominator * second.denominator;

	return sum;
}

ostream & operator<<(ostream &out, Rational &number){
	out << number.numerator << "/" << number.denominator << endl;
	return out;
}

istream & operator>>(istream &in, Rational &number){
	in >> number.numerator >> number.denominator ;
	return in;
}