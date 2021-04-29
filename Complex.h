#pragma once
#include <iostream>
#include "Imaginary.h"
using namespace std;

struct Complex {
    double real;
    Imaginary imagine;
    //YOU: Implement all these functions
    Complex(); //Default constructor
    Complex(double new_real, Imaginary new_imagine); //Two parameter constructor
    Complex operator+(const Complex &rhs);
    Complex operator-(const Complex &rhs);
    Complex operator*(const Complex &rhs);
    bool    operator== (const Complex &rhs);
    Complex operator^(const int &exponent);
    friend ostream& operator<<(ostream &lhs,const Complex& rhs);
    friend istream& operator>>(istream &lhs,Complex& rhs);
};
