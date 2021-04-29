#include <iostream>
#include "Complex.h"
using namespace std;

//Class definition file for Complex

//YOU: Fill in all of these functions
//There are stubs (fake functions) in there now so that it will compile
//The stubs should be removed and replaced with your own code.

Complex::Complex() {
	real = 0;
	imagine = Imaginary();
}

Complex::Complex(double new_real, Imaginary new_imagine) {
	real = new_real;
	imagine = new_imagine;
}

Complex Complex::operator+(const Complex &rhs) {
	return Complex(real + rhs.real, imagine + rhs.imagine);
}

Complex Complex::operator-(const Complex &rhs) {
	return Complex(real - rhs.real, imagine - rhs.imagine);
}

Complex Complex::operator*(const Complex &rhs) {
	return Complex(real*rhs.real + imagine*rhs.imagine, rhs.imagine*real + imagine*rhs.real);
}

bool Complex::operator==(const Complex &rhs) {
	return real == rhs.real && imagine == rhs.imagine;
}

Complex Complex::operator^(const int &exponent) {
	if (exponent == 0) return Complex(1, 0);
	if (exponent == 1) return *this;
	Complex temp;
	for (int i = 0; i < exponent - 1; i++) {
		if (!i) temp = *this * *this;
		else temp = temp * *this;
	}
	return temp;
}

ostream& operator<<(ostream &lhs,const Complex& rhs) {
	//Output a Complex here
	lhs << rhs.real << showpos << rhs.imagine;
	return lhs;
}
