#include "fraction.hpp"

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
