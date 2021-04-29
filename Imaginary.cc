#include "Imaginary.h"
#include <iomanip>
using namespace std;

//Sample Code - I have done the addition operator for you so you can see
//what a functioning operator should look like. Given this function below,
//in main() you could write the following code:
//  Imaginary foo(3); //foo is 3i
//  Imaginary bar(5); //bar is 5i
//  foo = foo + bar; //foo will become 8i
//In the above example, this function would get called on foo, with
//bar being passed in as the parameter named rhs (right hand side). 
Imaginary Imaginary::operator+(const Imaginary& rhs) const {
	return Imaginary(coeff+rhs.coeff); //My coeff is 3; rhs.coeff is 5. So construct a new one with a coeff of 8.
}

//These you will need to implement yourself.
//They currently are just stub functions
Imaginary::Imaginary() { //Default cstor
	//coeff = ??
	coeff = 0;
}

Imaginary::Imaginary(double new_coeff) { //One parameter cstor
	//coeff = ??
	coeff = new_coeff;
}

double Imaginary::get_coeff() const { //Get function
	return coeff; //Change this
}

Imaginary Imaginary::operator-(const Imaginary& rhs) const {
	return Imaginary(coeff-rhs.coeff); 
}

Imaginary Imaginary::operator*(const double& rhs) const {
	return Imaginary(coeff * rhs); //5i * 2 = 10i
}

double Imaginary::operator*(const Imaginary& rhs) const {
	return coeff * rhs.coeff * -1; //i * i = -1
}

//This function is functional
Imaginary Imaginary::operator=(const Imaginary& rhs) {
	coeff = rhs.coeff;
	return rhs;
}

//This function is functional
Imaginary Imaginary::operator=(const double& rhs) {
	coeff = rhs;
	return Imaginary(rhs); 
}

bool Imaginary::operator==(const Imaginary& rhs) const {
	return (coeff == rhs.coeff); 
}

//This function is done for you. It will allow you to cout variables of type Imaginary.
//For example, in main you could write:
//  Imaginary foo(2);
//  cout << foo << endl; 
//And this would print out "2i"
ostream& operator<<(ostream& lhs, const Imaginary& rhs) {
	lhs << showpos;
	lhs << rhs.coeff << "i"; //Will echo +4i or +0i or -3i or whatever
	lhs << noshowpos;
	return lhs;
}

istream& operator>>(istream& lhs, Imaginary& rhs) {
	double i;
	lhs >> i;
	rhs.coeff = i;
	return lhs;
}

