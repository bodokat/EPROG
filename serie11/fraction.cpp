#include "fraction.hpp"

Fraction() {
  numerator = 0;
  denominator = 1;
}
Fraction(int p, int q) {
  assert(q != 0);
  if (q > 0) {
    numerator = p;
    denominator = q;
  } else {
    numerator = -p;
    denominator = -q;
  }
}
Fraction(const Fraction& orig) {
  numerator = orig.numerator;
  denominator = orig.denominator;
}
Fraction& operator=(const Fraction& orig) {
  numerator = orig.numerator;
  denominator = orig.denominator;}
~Fraction() {

}

int Fraction::getNumerator() { return numerator; };
int Fraction::getDenominator() { return denominator; };
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
void Fraction::print() {
  cout << numerator << "/" << denominator << "\n";
}
