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

    int getNumerator();
    int getDenominator();
    void setNumerator(int n);
    void setDenominator(int n);
    void print();
};
