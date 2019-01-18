#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
#include <cassert>
#include <cmath>


class Fraction {
  private:
    int numerator;
    int denominator;
  public:
    Fraction();
    Fraction(int p, int q);
    Fraction(const Fraction& orig);
    Fraction& operator=(const Fraction& orig);
    ~Fraction();

    Fraction(double x);
    operator double() const;
    operator int() const;

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int n);
    void print() const;
    void reduce();

    const Fraction operator-() const;
};

const Fraction operator+(const Fraction& x, const Fraction& y);
const Fraction operator-(const Fraction& x, const Fraction& y);
const Fraction operator*(const Fraction& x, const Fraction& y);
const Fraction operator/(const Fraction& x, const Fraction& y);

std::ostream& operator<<(std::ostream& output, const Fraction& x);

#endif /* end of include guard: _FRACTION_ */
