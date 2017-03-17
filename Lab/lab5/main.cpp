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

// nonmember overloaded operators
ostream& operator<<(ostream &out, Rational r);
int main()
{
    Rational n1(12,24),n2(0,1),n3;
    Rational numberR(4,8);
    cout << numberR;
    n3 = n1+n2;
    cout << "n1+n2= "<< n3 << endl;
    n3 = n1-n2;
    cout << "n1-n2= "<< n3 << endl;
    n3 = n1*n2;
    cout << "n1*n2= "<< n3 << endl;
    n3 = n1/n2;
    cout << "n1/n2= "<< n3 << endl;
    bool small = (n1<n2);
    cout << "n1<n2" << small << endl;
    bool small2 = (n1<=n2);
    cout << "n1<=n2" << small2 << endl;
    bool big = (n1>n2);
    cout << "n1>n2" << big << endl;
    bool big2 = (n1>=n2);
    cout << "n1>=n2" << big2 << endl;
    bool equal = (n1==n2);
    cout << "n1=n2" << equal << endl;
    bool equal2 = (n1!=n2);
    cout << "n1!=n2" << equal2 << endl;
    return 0;
}

ostream& operator<<(ostream &out, Rational r) {
    out << " " << r.getNumerator() << " / " << r.getDenominator() << " ";
}

/// default constructor
Rational::Rational()
{
	m_Numerator = 0;
	m_Denominator = 1;

}

/// constructor for integers
Rational::Rational(int numerator)
{
	m_Numerator = numerator;
	m_Denominator = 1;
}

/// constructor for two integers
Rational::Rational(int numerator, int denominator)
{
	m_Numerator = numerator;
	m_Denominator = denominator;
    reduce();
}

/// multiple two numbers (given)
Rational operator*(Rational leftOp, Rational rightOp) {
  /*
    a      c        a * c
   ---  * ---   =  --------
    b      d        b * d

   */

  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();

  /// create a new value that matches the formula
  Rational returnValue(a * c, b * d);
  returnValue.reduce();
  /// return that new value
  return returnValue;
}


/// add two numbers
Rational operator+(Rational leftOp, Rational rightOp) {
  /*
    a      c        a*d + b*c
   ---  + ---   =  --------
    b      d        b * d

   */
  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();
  Rational returnValue(a * d + b * c, b * d);
  returnValue.reduce();
  return returnValue;
}

/// subtract two numbers
Rational operator-(Rational leftOp, Rational rightOp) {
  /*
    a      c        a*d - b*c
   ---  - ---   =  --------
    b      d        b * d

   */
  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();
  Rational returnValue((a * d - b * c), b * d);
  returnValue.reduce();
  return returnValue;
}

/// divide two numbers
Rational operator/(Rational leftOp, Rational rightOp) {
  /*
    a      c        a * d
   ---  / ---   =  --------
    b      d        b * c

   */
  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();
  if (b*c == 0)
  {
     cerr << "Error: trying to devide 0." << endl;
     exit(3);
  }
  Rational returnValue(a * d, b * c );
  returnValue.reduce();
  return returnValue;
}

bool operator<(Rational leftOp, Rational rightOp) {
  /*
    a      c
   ---  < ---   if a * d < b * c
    b      d

   */
  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();
  return (a * d < b * c);
}

bool operator<=(Rational leftOp, Rational rightOp) {
  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();
  return (a * d <= b * c);
}

bool operator>(Rational leftOp, Rational rightOp) {
  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();
  return (a * d > b * c);
}

bool operator>=(Rational leftOp, Rational rightOp) {
  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();
  return (a * d >= b * c);
}

bool operator==(Rational leftOp, Rational rightOp) {
  int a = leftOp.getNumerator();
  int b = leftOp.getDenominator();
  int c = rightOp.getNumerator();
  int d = rightOp.getDenominator();
  return (a * d == b * c);
}

bool operator!=(Rational leftOp, Rational rightOp) {

  return !(leftOp - rightOp == 0);
}


void Rational::reduce() {
  /// the sign is in the numerator
  if (m_Denominator < 0)
    { /// if the denominator is negative, multiply by -1/-1
      m_Denominator *= -1;
      m_Numerator *= -1;
    }

  int g = gcd(m_Numerator, m_Denominator);
  m_Numerator /= g;
  m_Denominator /= g;

}


/// Euclid's algorithm in recursive form
int Rational::gcd(int u, int v) {
  if (v == 0) {
    return u;
  }
  else {
    return gcd(v, u % v);
  }
}
