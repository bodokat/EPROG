#include "fraction.hpp"

Fraction::Fraction() {
  numerator = 0;
  denominator = 1;
}
Fraction::Fraction(int p, int q) {
  assert(q != 0);
  if (q > 0) {
    numerator = p;
    denominator = q;
  } else {
    numerator = -p;
    denominator = -q;
  }
}
Fraction::Fraction(const Fraction& orig) {
  numerator = orig.numerator;
  denominator = orig.denominator;
}
Fraction& Fraction::operator=(const Fraction& orig) {
  numerator = orig.numerator;
  denominator = orig.denominator;
  return *this;
}
Fraction::~Fraction() {}

Fraction::Fraction(double x) {
  int tolerance = 1000000000;
  numerator = (int)(x*tolerance);
  denominator = tolerance;
  reduce();
}
Fraction::operator double() const {
  return (double) numerator / (double) denominator;
}

int Fraction::getNumerator() const { return numerator; };
int Fraction::getDenominator() const { return denominator; };
void Fraction::setNumerator(int n) { numerator = n; };
void Fraction::setDenominator(int n) {
  assert(n != 0);
  if (n > 0) {
    denominator = n;
  }
  else {
    denominator = -n;
    numerator = -numerator;
  }
}
void Fraction::print() const {
  std::cout << numerator << "/" << denominator << "\n";
}

int euclid(int a,int b) {
  while (b != 0) {
    int h = a % b;
    a = b;
    b = h;
  }
  return a;
}
void Fraction::reduce() {
  int ggT;
  do {
    ggT = euclid(numerator,denominator);
    numerator /= ggT;
    denominator /= ggT;
  } while(ggT != 1);
  return;
}
/*
const Fraction Fraction::operator-() const {
  return new Fraction(-numerator,denominator);
}
const Fraction operator+(const Fraction& x, const Fraction& y) {

}
const Fraction operator-(const Fraction& x, const Fraction& y);
const Fraction operator*(const Fraction& x, const Fraction& y);
const Fraction operator/(const Fraction& x, const Fraction& y);
*/
