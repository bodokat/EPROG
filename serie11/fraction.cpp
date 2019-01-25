#include "fraction.hpp"
#include <iostream>

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
  int precision;
  if (fabs(x) <= 2) {
    precision = 1000000000;
  } else {
    precision = 1000000;
  }
  numerator = (int)(x*precision);
  denominator = precision;
  reduce();
}
Fraction::operator double() const {
  return (double) numerator / (double) denominator;
}


Fraction::operator int() const {
  // return (int)round((double) numerator / (double) denominator);
  int res = numerator / denominator;
  int frac = numerator % denominator; // nachkommaanteil, frac/denominator < 1
  if (fabs(2*frac) <= denominator) { //nachkommaanteil <= 0.5
    return res;
  } else {
    if (numerator > 0) {
      return res + 1;
    } else {
      return res - 1;
    }
  }
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
    ggT = fabs(euclid(numerator,denominator));
    numerator /= ggT;
    denominator /= ggT;
  } while(ggT != 1);
  return;
}

const Fraction Fraction::operator-() const {
  return Fraction(-numerator,denominator);
}
const Fraction operator+(const Fraction& x, const Fraction& y) {
  int num = x.getNumerator()*y.getDenominator() + y.getNumerator()*x.getDenominator();
  int det = x.getDenominator()*y.getDenominator();
  Fraction result(num, det);
  result.reduce();
  return result;
}
const Fraction operator-(const Fraction& x, const Fraction& y) {
  int num = x.getNumerator()*y.getDenominator() - y.getNumerator()*x.getDenominator();
  int det = x.getDenominator()*y.getDenominator();
  Fraction result(num, det);
  result.reduce();
  return result;
}
const Fraction operator*(const Fraction& x, const Fraction& y) {
  int num = x.getNumerator()*y.getNumerator();
  int det = x.getDenominator()*y.getDenominator();
  Fraction result(num, det);
  result.reduce();
  return result;
}
const Fraction operator/(const Fraction& x, const Fraction& y) {
  assert(y.getNumerator() != 0);
  int num = x.getNumerator()*y.getDenominator();
  int det = x.getDenominator()*y.getNumerator();
  Fraction result(num, det);
  result.reduce();
  return result;
}

std::ostream& operator<<(std::ostream& output, const Fraction& x) {
  if (x.getNumerator() == 0) {
    return output << 0;
  } else {
    return output << x.getNumerator() << "/" << x.getDenominator();
  }
}
