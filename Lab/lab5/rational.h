#ifndef _RATIONAL_H_
#define _RATIONAL_H_
#include <iostream>
#include <cstdlib>

using namespace std;

class Rational {

 public:

    /// constructors
    Rational();
    Rational(int n, int d);
    Rational(int n);

    /// accessors
    int getNumerator() {return m_Numerator;}
    int getDenominator() {return m_Denominator;}

    //  math
    friend Rational operator*(Rational, Rational);
    friend Rational operator/(Rational, Rational);
    friend Rational operator+(Rational, Rational);
    friend Rational operator-(Rational, Rational);

    // comparison
    friend bool operator<(Rational, Rational);
    friend bool operator<=(Rational, Rational);
    friend bool operator>(Rational, Rational);
    friend bool operator>=(Rational, Rational);
    friend bool operator==(Rational, Rational);
    friend bool operator!=(Rational, Rational);

  private:
    int m_Numerator;
    int m_Denominator;

    /// helper functions
    int gcd(int, int);
    void reduce();

};

ostream& operator<<(ostream &out, Rational r);

#endif

