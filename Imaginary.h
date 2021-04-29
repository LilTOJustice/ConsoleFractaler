#pragma once
#include <iostream>
using namespace std;

struct Imaginary {
    double coeff; //If 5, then means 5i
    Imaginary();
    Imaginary(double new_coeff);
    double get_coeff() const;
    Imaginary operator+(const Imaginary& rhs) const; //This is a "constant method"
    Imaginary operator-(const Imaginary& rhs) const;
    double       operator*(const Imaginary& rhs) const;
    Imaginary operator*(const double& rhs) const;
    Imaginary operator=(const double& rhs); 
    Imaginary operator=(const Imaginary& rhs); 
    bool      operator==(const Imaginary& rhs) const; 
    friend ostream& operator<<(ostream& lhs, const Imaginary& rhs);
    friend istream& operator>>(istream& lhs, Imaginary& rhs);
};
