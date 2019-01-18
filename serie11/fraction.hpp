#include <iostream>
#include <cassert>


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

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int n);
    void print() const;
    void reduce();

    //const Fraction operator-() const;
};
//
// const Fraction operator+(const Fraction& x, const Fraction& y);
// const Fraction operator-(const Fraction& x, const Fraction& y);
// const Fraction operator*(const Fraction& x, const Fraction& y);
// const Fraction operator/(const Fraction& x, const Fraction& y);
